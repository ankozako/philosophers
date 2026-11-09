/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:53:50 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/27 17:53:51 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	sim_stopped(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->stop_mutex);
	stopped = data->sim_end;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stopped);
}

void	stop_sim(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->sim_end = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}

void	safe_print(t_data *data, int id, char *msg)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!sim_stopped(data))
		printf("%lld %d %s\n", get_time() - data->start_time, id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}

int	check_death(t_data *data)
{
	int			i;
	long long	current;
	long long	last_meal;

	current = get_time();
	i = 0;
	while (i < data->n_philos)
	{
		last_meal = get_last_meal(&data->philos[i]);
		if (current - last_meal > data->time_to_die)
		{
			safe_print(data, data->philos[i].id, "died");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_eaten(t_data *data)
{
	int	i;
	int	meals;

	if (data->meals_total == -1)
		return (0);
	i = 0;
	while (i < data->n_philos)
	{
		meals = get_meals_eaten(&data->philos[i]);
		if (meals < data->meals_total)
			return (0);
		i++;
	}
	return (1);
}
