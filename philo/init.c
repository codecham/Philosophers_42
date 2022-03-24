/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:26:16 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/21 04:26:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(data->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(data->check_eat), NULL))
		return (1);
	return(0);
}

void	init_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork_id = i;
		data->philo[i].right_fork_id = (i + 1) % data->nb_philo;
		data->philo[i].last_eat = 0;
		data->philo[i].nb_of_eat = 0;
		data->philo[i].data = data;
		i++;
	}
}

void	init(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	data->first_time = 0;
	data->is_dead = 0;
	data->all_eat = 0;
	data->philo = NULL;
	data->forks = NULL;
	data->philo = malloc(sizeof(t_philosopher) * data->nb_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->philo || !data->forks)
		exit_free(data, "Allocation error");
	if (init_mutex(data) != 0)
		exit_free(data, "Mutex init error");
	init_philo(data);
}