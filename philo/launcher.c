/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:16:54 by dcorenti          #+#    #+#             */
/*   Updated: 2022/08/28 22:05:53 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *v_philo)
{
	t_data			*data;
	t_philosopher	*philo;

	philo = (t_philosopher *)v_philo;
	data = philo->data;
	if (philo->id % 2)
		usleep(data->time_die / 2);
	while (data->is_dead == 0)
	{
		philo_eat(philo);
		if (philo->nb_of_eat == data->max_eat)
		{
			data->all_eat++;
			break ;
		}
		action_print(data, philo->id, "is sleeping");
		philo_sleep(data, data->time_sleep);
		action_print(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	dead_check(t_data *data, t_philosopher *philo)
{
	int	i;

	while (data->all_eat < data->nb_philo)
	{
		i = -1;
		while (++i < data->nb_philo)
		{
			pthread_mutex_lock(&(data->check_eat));
			if (time_diff(philo[i].last_eat, timestamp()) > data->time_die)
			{
				action_print(data, philo[i].id, "died");
				data->is_dead = 1;
			}
			pthread_mutex_unlock(&(data->check_eat));
			usleep(100);
			if (data->is_dead == 1)
				break ;
		}
		if (data->nb_philo == data->all_eat || data->is_dead != 0)
			break ;
	}
}

void	exit_launcher(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nb_philo)
	{
		pthread_detach(data->philo[i].thread_id);
		i++;
	}
	while (i <= data->nb_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->writing));
	pthread_mutex_destroy(&(data->check_eat));
}

void	launcher(t_data *data)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	data->first_time = timestamp();
	philo = data->philo;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
			exit_free(data, "Error during create thread");
		philo[i].last_eat = timestamp();
		i++;
	}
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread_id, NULL))
			exit_free(data, "pthread_join failed");
		i++;
	}
	dead_check(data, data->philo);
	exit_launcher(data);
	exit_free(data, NULL);
}
