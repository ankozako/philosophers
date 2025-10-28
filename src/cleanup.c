#include "philo.h"

static void  destroy_fork_mutexes(t_data *data)
{
  int  i;

  i = 0;
  while (i < data->n_philos)
    {
      pthread_mutex_destroy(&data->forks[i]);
      i++;
    }
}

static void  destroy_control_mutexes(t_data *data)
{
  pthread_mutex_destroy(&data->print_mutex);
  pthread_mutex_destroy(&data->stop_mutex);
}

void  join_threads(t_data *data)
{
  int  i;

  i = 0;
  while (i < data->n_philos)
    {
      pthread_join(data->philos[i].thread, NULL);
      i++;
    }
}

void  cleanup(t_data *data)
{
  if (data->forks)
  {
    destroy_fork_mutexes(data);
    free(data->forks);
  }
  destroy_control_mutexes(data);
  if (data->philos)
    free(data->philos);
}
