/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:55:40 by mait-aad          #+#    #+#             */
/*   Updated: 2022/06/02 15:15:19 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_negativ(char **av, int ac)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (-1);
	if (ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (-1);
	}
	return (0);
}

void	data_treating(t_phi_d	*ph_data, char	**av, int ac)
{
	int	i;

	i = -1;
	while (ft_atoi(av[1]) > ++i)
	{
		ph_data[i].r_fork = i;
		ph_data[i].l_fork = i + 1;
		if (i == ft_atoi(av[1]) - 1)
			ph_data[i].l_fork = 0;
		ph_data[i].there_is_e_l = 0;
		if (ac == 6)
		{
			ph_data[i].there_is_e_l = 1;
			ph_data[i].set_e_l = ft_atoi(av[5]);
		}
		ph_data[i].philo_max = ft_atoi(av[1]);
		ph_data[i].d_t = ft_atoi(av[2]);
		ph_data[i].e_t = ft_atoi(av[3]);
		ph_data[i].s_t = ft_atoi(av[4]);
		ph_data[i].p_n = i;
	}
}

int	main(int ac, char	**av)
{
	t_phi_d		*ph_data;
	int			i;

	if (ac >= 5 && ac < 7
		&& check_args(av + 1) == 0 && check_negativ(av, ac) == 0)
	{
		ph_data = (t_phi_d *)malloc(ft_atoi(av[1]) * sizeof(t_phi_d) + 1);
		if (!ph_data)
			return (0);
		i = -1;
		data_treating(ph_data, av, ac);
		philos(ph_data, ft_atoi(av[1]));
		return (0);
	}
	printf("\x1b[31m Error\n");
	return (0);
}
