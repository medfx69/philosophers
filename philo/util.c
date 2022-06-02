/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:21:09 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/02 14:35:42 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char	*str)
{
	int	i;
	int	countmi;
	int	num;

	i = 0;
	countmi = 0;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			countmi++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (countmi != 0)
		return (-num);
	else
		return (num);
}

int	check_args(char **c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i])
	{
		j = 0;
		if (!c[i][j])
			return (-1);
		while (c[i][j])
		{
			if (!((c[i][j] <= '9' && c[i][j] >= '0')
				|| c[i][j] == '+' || c[i][j] == '-'))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_dead(t_phi_d	*ph_data)
{
	if (ph_data->there_is_e_l == 1 && ph_data->set_e_l <= 0)
		return (0);
	if (p_time_now() - ph_data->current_time
		- ph_data->last_time_eat >= ph_data->d_t)
	{
		pthread_mutex_lock(ph_data->mu);
		printf("\x1b[31m%ldms  %d died\n",
			p_time_now() - ph_data->current_time, ph_data->p_n + 1);
		return (-1);
	}
	return (0);
}

long	p_time_now(void)
{
	struct timeval	last_time_eat;

	gettimeofday(&last_time_eat, NULL);
	return ((last_time_eat.tv_usec / 1000) + (last_time_eat.tv_sec * 1000));
}

void	p_sleep(int i)
{
	long	k;

	k = p_time_now();
	while ((p_time_now() - k) < i)
		usleep(300);
}
