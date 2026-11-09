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

void	set_table(t_data *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		error_exit("Usage: ./philo n_philos t_die t_eat t_sleep [meals]\n");
	data->n_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_total = ft_atoi(av[5]);
	else
		data->meals_total = -1;
	if (data->n_philos < 1)
		error_exit("Error: invalid n_philos value\n");
	if (data->time_to_die < 1)
		error_exit("Error: invalid time_to_die value\n");
	if (data->time_to_eat < 1)
		error_exit("Error: invalid time_to_eat value\n");
	if (data->time_to_sleep < 1)
		error_exit("Error: invalid time_to_sleep value\n");
	if (ac == 6 && data->meals_total < 1)
		error_exit("Error: invalid meals_total value\n");
	data->sim_end = 0;
}
