/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:09:19 by dcorenti          #+#    #+#             */
/*   Updated: 2022/03/25 00:49:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_int(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 0)
			exit_message("Arguments must be positives numbers");
		i++;
	}
	if (i == 1 && number[0] == '0')
		exit_message("Arguments can't be zero");
	if (i > 10)
		exit_message("Arguments must be a integer");
	if (i == 10)
	{
		if (ft_strncmp(number, "2147483647", 10) > 0)
			exit_message("Arguments must be a integer");
	}
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		exit_message("Wrong number of arguments");
	while (i < argc)
	{
		ft_is_int(argv[i]);
		i++;
	}
}
