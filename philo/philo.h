/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:37:59 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/20 14:45:20 by dcorenti         ###   ########.fr       */
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

struct s_data;

typedef struct s_philosopher
{
	int				id;
	int				left_fork_id;
	int 			right_fork_id;
	int				nb_of_eat;
	long long		last_eat;
	struct s_data	*data;
	pthread_t		thread_id;

}	t_philosopher;

typedef struct	s_data
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int 			max_eat;
	int				is_dead;
	int				all_eat;
	pthread_mutex_t *forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	check_eat;
	long long		first_time;
	t_philosopher	*philo;
}	t_data;

void		exit_message(char *message);
void		check_args(int argc, char **argv);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		init(t_data *data, int argc, char **argv);
int			ft_atoi(const char *str);
void		exit_free(t_data *data, char *message);
long long	time_diff(long long past, long long present);
long long	timestamp(void);
void		action_print(t_data *data, int id, char *str);
void		philo_sleep(t_data *data, int time);
void		philo_eat(t_philosopher *philo);
void		launcher(t_data *data);


#endif