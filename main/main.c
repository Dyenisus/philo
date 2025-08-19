/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:19:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 10:54:24 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	long	*list;
	t_cfg	cfg;
	t_sim	sim;
	t_philo	*philos;

	list = prep(ac, av);
	if (!list)
		return (print_err("Error: Invalid Arguments\n"));
	init_cfg(&cfg, list, ac);
	if (!init_sim(&sim, cfg))
		return (print_err("Error: Sim Initialization Failed\n"));
}
