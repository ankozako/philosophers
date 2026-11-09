/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:57:03 by ankozako          #+#    #+#             */
/*   Updated: 2025/11/10 10:57:05 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	get_last_meal(t_philo *philo)
{
	long long	lastmeal;

	lastmeal = 0;
	pthread_mutex_lock(philo->meal_mutex);
	lastmeal = philo->last_meal;
	pthread_mutex_unlock(philo->meal_mutex);
	return (lastmeal);
}

void	set_last_meal(t_philo *philo, long long value)
{
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal = value;
	pthread_mutex_unlock(philo->meal_mutex);
}

int	get_meals_eaten(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(philo->meal_mutex);
	meals = philo->meals_eaten;
	pthread_mutex_unlock(philo->meal_mutex);
	return (meals);
}

void	increment_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);
}
