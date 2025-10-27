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

int	main(int ac, char **av)
{
	t_data	d;

	memset(&d, 0, sizeof(d));
	set_table(&d, ac, av);
	printf("n = %d die=%lld eat=%lld sleep=%lld meals_total=%d\n",
		d.n_philos, d.time_to_die, d.time_to_eat, d.time_to_sleep, d.meals_total);
	return (0);
}
