/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:46:57 by ankozako          #+#    #+#             */
/*   Updated: 2025/10/06 11:46:58 by ankozako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_atoi(char *s)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			return (-1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)res);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	error_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	prec_sleep(long long ms, t_data *data)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
	{
		if (sim_stopped(data))
			return ;
		usleep(100);
	}
}
