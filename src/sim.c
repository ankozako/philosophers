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

int	sim_stop(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->stop_mutex);
	data->sim_end = 1;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stop);
}

void	safe_print(t_data *data, int id, char *msg)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!sim_stop(data))
		printf("%lld %d %s\n", get_time() - data->start_time, id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}
