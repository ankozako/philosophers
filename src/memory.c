/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:34:24 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/27 15:34:26 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	alloc_meal_mutexes(t_data *data)
{
	data->meal_mutexes = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->meal_mutexes)
		return (1);
	return (0);
}

int	alloc_memory(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
	{
		free(data->forks);
		return (1);
	}
	data->meal_mutexes = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->meal_mutexes)
	{
		free(data->forks);
		free(data->philos);
		return (1);
	}
	return (0);
}
