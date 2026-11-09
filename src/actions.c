/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:59:46 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/29 08:59:48 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo)
{
	safe_print(philo->data, philo->id, "is eating");
	set_last_meal(philo, get_time());
	increment_meals_eaten(philo);
	prec_sleep(philo->data->time_to_eat, philo->data);
}

void	philo_sleep(t_philo *philo)
{
	safe_print(philo->data, philo->id, "is sleeping");
	prec_sleep(philo->data->time_to_sleep, philo->data);
}

static void	philo_think(t_philo *philo)
{
	safe_print(philo->data, philo->id, "is thinking");
}

static void	single_philo_routine(t_philo *philo)
{
	while (!sim_stopped(philo->data))
	{
		philo_think(philo);
		pthread_mutex_lock(philo->left_fork);
		safe_print(philo->data, philo->id, "has taken a fork");
		while (!sim_stopped(philo->data))
			usleep(1000);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		prec_sleep(1, philo->data);
	if (philo->data->n_philos == 1)
	{
		single_philo_routine(philo);
		return (NULL);
	}
	while (!sim_stopped(philo->data))
	{
		philo_think(philo);
		take_forks(philo);
		philo_eat(philo);
		drop_forks(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
