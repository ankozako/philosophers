/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:46:36 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/06 11:46:39 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	check_ac(void)
{
	if (ac != 5 || ac != 6)
		error_exit("Usage: ./philo n t_die t_eat t_sleep [meals]\n");
}

void	parse_arg(t_data *data, char **av)
{
	data->n_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
}

void	parse_opt_arg(t_data *data, int ac, char **av)
{
	if (ac == 6)
		data->meals_total = ft_atoi(av[5]);
	else
		data->meals_total = -1;
}

void	validate_values(t_data *data, int ac)
{
	if (data->n_philos < 1)
		error_exit("Error: number of philospohers must be >= 1\n");
	if (data->time_to_die < 1)
		error_exit("Error: time_to_die must be >= 1\n");
	if (data->time_to_eat < 1)
		error_exit("Error: time_to_eat must be >= 1\n");
	if (data->time_to_sleep < 1)
		error_exit("Error: time_to_sleep must be >= 1\n");
	if (ac == 6 && data->meals_total < 1)
		error_exit("Error: meals_total must be >= 1\n");
}

void	set_table(t_data *data, int ac, char **av)
{
	check_ac(ac);
	parse_arg(data, av);
	parse_opt_arg(data, ac, av);
	validate_values(data, ac);
	data->sim_end = 0;
}
