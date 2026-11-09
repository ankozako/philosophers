/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:01:42 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/27 17:01:45 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	init_single_philo(t_data *data, int i)
{
	data->philos[i].id = i + 1;
	data->philos[i].meals_eaten = 0;
	data->philos[i].last_meal = 0;
	data->philos[i].data = data;
	data->philos[i].left_fork = &data->forks[i];
	data->philos[i].right_fork = &data->forks[(i + 1) % data->n_philos];
	data->philos[i].meal_mutex = &data->meal_mutexes[i];
}

static void	init_all_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		init_single_philo(data, i);
		i++;
	}
}

int	init_data(t_data *data)
{
	if (alloc_memory(data))
		return (1);
	if (init_all_mutexes(data))
		return (1);
	init_all_philos(data);
	return (0);
}
