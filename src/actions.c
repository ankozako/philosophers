#include "philo.h"

void   philo_eat(t_philo *philo)
{
  safe_print(philo->data, philo->id, "is eating");
  philo->last_meal = get_time();
  philo-meals_eaten++;
  prec_sleep(philo->data->time_to_eat);
}

void   philo_sleep(t_philo *philo)
{
  safe_print(philo->data, philo->id, "is sleeping");
  prec_sleep(philo->data->time_to_sleep);
}

void  philo_think(t_philo *philo)
{
  safe_print(philo->data, philo->id, "is thinking");
}
