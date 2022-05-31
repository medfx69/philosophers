/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:26:58 by mait-aad          #+#    #+#             */
/*   Updated: 2022/05/29 14:45:13 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phi_d
{
	pthread_t		philo_id;
	int				d_t;
	int				e_t;
	int				s_t;
	int				p_n;
	int				r_fork;
	int				l_fork;
	int				philo_max;
	int				there_is_e_l;
	int				set_e_l;
	pthread_mutex_t	chopstick;
	struct s_phi_d	*ph;
	long			current_time;
	long			last_time_eat;
}	t_phi_d;
int		ft_atoi(char	*str);
int		check_args(char **c);
int		check_if_dead(t_phi_d	*ph_data);
long	p_time_now(void);
int		check_if_they_all_eat(t_phi_d *p, int ph__n);
void	p_sleep(int i);
long	p_time_now(void);
void	sleeping(t_phi_d *p);
void	philos(t_phi_d	*ph_data, int phi_n);

#endif