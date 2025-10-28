void   start_ph(t_philo *philo)
{
  if (philo_id % 2 == 0)
    prec_sleep(1);
}

void  *philo_routine(void *arg)
{
  t_philo  *philo;

  philo = (t_philo *)arg;
  start_ph(philo);
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

void  set_start_time(t_data *data)
{
  int  i;
  data->start_time = get_time();
  i = 0;
  while (i < data->n_philos)
    {
      data->philos[i].last_meal = data->start_time;
      i++;
    }
}

int  create_threads(t_data *data)
{
  int  i;

  i = 0;
  while (i < data->n_philos)
    {
      if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine, &data->philos[i]))
        return (1);
      i++;
    }
  return (0);
}

int  start_sim(t_data *data)
{
  set_start_time(data);
  if (create_threads(data))
    return (1);
  return (0);
}
