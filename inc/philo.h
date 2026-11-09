/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:38:01 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/06 11:38:05 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_meal;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_mutex;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				n_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				meals_total;
	long long		start_time;
	int				sim_end;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meal_mutexes;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}	t_data;

void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);

void		set_table(t_data *data, int ac, char **av);

void		join_threads(t_data *data);
void		cleanup(t_data *data);

int			init_data(t_data *data);

int			alloc_memory(t_data *data);

int			init_all_mutexes(t_data *data);

int			sim_stopped(t_data *data);
void		stop_sim(t_data *data);
void		safe_print(t_data *data, int id, char *msg);

int			ft_atoi(char *s);
void		error_exit(char *msg);
long long	get_time(void);
void		prec_sleep(long long ms, t_data *data);

void		*philo_routine(void *arg);
int			start_sim(t_data *data);
int			check_death(t_data *data);
int			check_if_all_eaten(t_data *data);

void		set_last_meal(t_philo *philo, long long value);
void		increment_meals_eaten(t_philo *philo);
long long	get_last_meal(t_philo *philo);
int			get_meals_eaten(t_philo *philo);

#endif