/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:46:45 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/06 11:46:47 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	setup_simulation(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(*data));
	set_table(data, ac, av);
	return (0);
}

static int	start_simulation(t_data *data)
{
	if (init_data(data))
		return (1);
	if (start_sim(data))
		return (1);
	return (0);
}

static void	monitor_simulation(t_data *data)
{
	while (!sim_stopped(data))
	{
		if (check_death(data) || check_if_all_eaten(data))
		{
			stop_sim(data);
			break ;
		}
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	setup_simulation(&data, ac, av);
	if (start_simulation(&data))
	{
		cleanup(&data);
		return (1);
	}
	monitor_simulation(&data);
	join_threads(&data);
	cleanup(&data);
	return (0);
}
