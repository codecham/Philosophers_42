/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:37:59 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/18 19:37:29 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>


typedef struct	s_data
{
	int	nb_philo;
	int	time_death;
	int	time_eat;
	int	time_sleep;
	int max_eat;
	
}	t_data;

void	exit_message(char *message);
void	check_args(int argc, char **argv);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif