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

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_meal;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
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
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}	t_data;

int		set_table(t_data *d, int ac, char **av);

int		ft_atoi(char *s);
int		ft_strlen(char *s);
void	error_exit(char *msg);
void	prec_sleep(long long ms);

int	alloc_memory(t_data *data);
int	init_all_mutexes(t_data *data);
long long	get_time(void);
void	safe_print(t_data *data, int id, char *msg);

#endif