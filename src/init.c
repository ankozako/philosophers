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

static void	set_philo_data(t_philo *philo, int id, t_data *data)
{
	philo->id = id;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->data = data;
}

static void set_philo_forks(t_philo *philo, t_data *data, int i)
{
	philo->left_fork = &data->forks[i];
	philo->right_fork = &data->forks[(i + 1) % data->n_philos];
}

static void	init_single_philo(t_data *data, int i)
{
	set_philo_data(&data->philos[i], i + 1, data);
	set_philo_forks(&data->philos[i], data, i);
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