/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:29 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/02 15:05:11 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_they_all_eat(t_phi_d *p, int ph__n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ph__n)
	{
		if (p[i].set_e_l <= 0)
			j++;
		i++;
	}
	if (j == ph__n)
		return (-1);
	return (0);
}

void	sleeping(t_phi_d *p)
{
	printing("\033[0;35m", p, " is sleeping");
	p_sleep(p->s_t);
	printing("\033[0;36m", p, " is thinking");
}

void	printing(char *color, t_phi_d	*p, char *message)
{
	pthread_mutex_lock(p->mu);
	printf("%s%ld ms (%d) %s \n", color,
		p_time_now() - p->current_time, p->p_n +1, message);
	pthread_mutex_unlock(p->mu);
}
