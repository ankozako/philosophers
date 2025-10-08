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

static void	usage(void)
{
	write(2, "Usage: ./philo n t_die t_eat t_sleep [meals_total]\n", 49);
}

static int	validate_pos(const char *s)
{
	int	temp;

	temp = ft_atoi(s);
	if (s && s[0] == '-')
		return (0);
	return (v > 0);
}

void	set_table(t_data *d, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		usage();
		exit(1);
	}
	if (!validate_pos(av[1]) || !validate_pos(av[2]) || !validate_pos(av[3])
		|| !validate_pos(av[4]) || !validate_pos(av[5]))
	{
		write(2, "Error: invalid arguments\n", 25);
		exit(1);
	}
	d->n_philos = ft_atoi(av[1]);
	d->time_to_die = ft_atoi(av[2]);
	d->time_to_eat = ft_atoi(av[3]);
	d->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		d->meals_total = ft_atoi(av[5]);
	else
		d->meals_total = -1;
	if (d->n_philos < 1 || d->time_to_die < 1 || d->time_to_eat < 1
		|| d->time_to_sleep < 1 || (ac == 6 && d->meals_total < 1))
	{
		write(2, "Error: values must be >=1\n", 27);
		exit(1);
	}
	d->sim_end = 0;
}
