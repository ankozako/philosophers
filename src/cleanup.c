/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:59:58 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/29 09:00:00 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->n_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->meal_mutexes[i]);
			i++;
		}
		free(data->forks);
		free(data->meal_mutexes);
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->stop_mutex);
	if (data->philos)
		free(data->philos);
}
