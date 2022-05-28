/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:29 by mait-aad          #+#    #+#             */
/*   Updated: 2022/05/27 19:49:07 by mait-aad         ###   ########.fr       */
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
	pthread_mutex_t	mu;

	pthread_mutex_lock(&mu);
	printf("\033[0;34m%ldms (%d) is sleeping \n",
		p_time_now() - p->current_time, p->p_n +1);
	p_sleep(p->s_t);
	printf("\033[0;36m%ldms (%d) is thinking \n",
		p_time_now() - p->current_time, p->p_n +1);
	pthread_mutex_unlock(&mu);
}
