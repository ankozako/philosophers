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

int	alloc_forks(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (1);
	return (0);
}

int	alloc_philos(t_data *data)
{
	data->philos(sizeof(t_philo) * data->n_philos)
	if (!data->philos)
		return (1);
	return (0);
}

int	alloc_memory(t_data *data)
{
	if (alloc_forks(data))
		return (1);
	if (alloc_philos(data))
		return (1);
	return (0);
}