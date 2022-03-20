/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:09:38 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/20 05:44:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_free(t_data *data, char *message)
{
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
	if (!message)
		exit(0);
	else
		exit_message(message);
}

void	exit_message(char *message)
{
	printf("Error: %s\n", message);
	exit(0);
}