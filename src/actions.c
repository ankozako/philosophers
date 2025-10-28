#include "philo.h"

void   philo_eat(t_philo *philo)
{
  safe_print(philo->data, philo->id, "is eating");
  philo->last_meal = get_time();
  philo-meals_eaten++;
  precise_sleep(philo->data->time_to_eat)
}
