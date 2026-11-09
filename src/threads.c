/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:11:14 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/29 10:11:15 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_start_time(t_data *data)
{
	int	i;

	data->start_time = get_time();
	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].last_meal = data->start_time;
		i++;
	}
}

static int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread,
				NULL, philo_routine, &data->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

int	start_sim(t_data *data)
{
	set_start_time(data);
	if (create_threads(data))
		return (1);
	return (0);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
