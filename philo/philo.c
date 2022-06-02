/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:20:18 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/02 15:04:58 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_phi_d *p)
{
	usleep(30);
	pthread_mutex_lock(&p->ph[p->r_fork].chopstick);
	pthread_mutex_lock(&p->ph[p->l_fork].chopstick);
	printing("\033[0;32m", p, "taken a fork");
	printing("\033[0;33m", p, "taken a fork");
	printing("\033[0;34m", p, "is eating");
	if (p->there_is_e_l == 1 && p->set_e_l > 0)
		p->set_e_l = p->set_e_l - 1;
	p->last_time_eat = p_time_now() - p->current_time;
	p_sleep(p->e_t);
	pthread_mutex_unlock(&p->ph[p->r_fork].chopstick);
	pthread_mutex_unlock(&p->ph[p->l_fork].chopstick);
}

void	*threads_handler(void	*s)
{
	t_phi_d			*p;

	p = (t_phi_d *)s;
	while (1)
	{
		if (p->there_is_e_l == 1 && p->set_e_l <= 0)
			break ;
		eating(p);
		sleeping(p);
	}
	return (NULL);
}

int	threads_creating(t_phi_d *ph, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		if (i % 2 == 1)
		{
			usleep(30);
			if (pthread_create(&ph[i].philo_id, NULL, threads_handler, &ph[i]))
				return (-1);
		}
	}
	i = -1;
	while (++i < num)
	{
		if (i % 2 == 0)
		{
			usleep(30);
			if (pthread_create(&ph[i].philo_id, NULL, threads_handler, &ph[i]))
				return (-1);
		}
	}
	if (num == 1)
		printf("\033[0;33m0ms (1) takse fork (1)\n");
	return (0);
}

int	manag(t_phi_d *ph, int num)
{
	int				i;
	pthread_mutex_t	mu;

	i = 0;
	pthread_mutex_init(&mu, NULL);
	while (i < num)
	{
		if (pthread_mutex_init(&ph[i++].chopstick, NULL))
			return (0);
	}
	threads_creating(ph, num);
	i = 0;
	while (check_if_dead(&ph[i]) != -1)
	{
		usleep(30);
		if (ph[i++].there_is_e_l == 1 && check_if_they_all_eat(ph, num) == -1)
			return (0);
		if (i == num)
			i = 0;
	}
	return (0);
}

void	philos(t_phi_d	*ph_data, int phi_n)
{
	pthread_mutex_t	*mu;
	pthread_t		*ph_id;
	int				i;

	ph_id = (pthread_t *)malloc(phi_n * sizeof(pthread_t) + 1);
	mu = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!ph_id)
		return ;
	i = -1;
	pthread_mutex_init(mu, NULL);
	while (phi_n > ++i)
	{
		ph_data[i].last_time_eat = 0;
		ph_data[i].current_time = p_time_now();
		ph_data[i].philo_id = ph_id[i];
		ph_data[i].ph = ph_data;
		ph_data[i].mu = mu;
	}
	manag(ph_data, phi_n);
	free(ph_id);
}
