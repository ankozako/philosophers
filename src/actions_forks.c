/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:14:44 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/27 18:14:46 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	safe_print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	safe_print(philo->data, philo->id, "has taken a fork");
}

static void	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	safe_print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	safe_print(philo->data, philo->id, "has taken a fork");
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
		take_forks_even(t_philo *philo);
	else
		void	take_forks_odd(t_philo *philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

