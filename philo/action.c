/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:12:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/20 19:47:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philosopher *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork_id]));
	action_print(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork_id]));
	action_print(data, philo->id, "has taken a fork");
	action_print(data, philo->id, "is eating");
	pthread_mutex_lock(&(data->check_eat));
	philo->last_eat = timestamp();
	pthread_mutex_unlock(&(data->check_eat));
	philo_sleep(data, data->time_eat);
	philo->nb_of_eat++;
	pthread_mutex_unlock(&(data->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork_id]));	
}

void	philo_sleep(t_data *data, int time)
{
	(void)data;
	usleep(time * 1000);
}

void	action_print(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing));
	if (data->is_dead == 0)
	{
		printf("%lld ", timestamp() - data->first_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(data->writing));
}