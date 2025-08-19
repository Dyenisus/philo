/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:19:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 13:12:22 by yesoytur         ###   ########.fr       */
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
		return (print_err("Invalid Arguments"));
	init_cfg(&cfg, list, ac);
	if (init_sim(&sim, cfg))
		return (print_err("Sim Initialization Failed"));
	if (init_philos(&philos, &sim))
		return (free_sim(&sim), print_err("Philo Initialization Failed"));
}
