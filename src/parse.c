/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:45:26 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:07:03 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static long	*conv_to_nbr_list(int ac, char **av)
{
	long	*list;
	int		i;
	int		ok;

	list = malloc(sizeof(long) * (ac - 1));
	if (!list)
		return (NULL);
	i = 0;
	while (++av, --ac)
	{
		list[i] = ft_atol(*av, &ok);
		if (!ok)
			return (free(list), NULL);
		i++;
	}
	return (list);
}

int	prep(int ac, char **av, t_sim *sim, t_philo **philos)
{
	long	*list;
	t_cfg	cfg;

	if (!first_checks(ac, av))
		return (print_err("first_checks failed"));
	list = conv_to_nbr_list(ac, av);
	if (!list)
		return (print_err("conv_to_nbr_list failed"));
	if (!secondary_checks(ac, list))
		return (free(list), print_err("secondary_checks failed"));
	init_cfg(&cfg, list, ac);
	free(list);
	if (init_sim(sim, cfg))
		return (print_err("init_sim failed"));
	if (init_philos(philos, sim))
		return (free_sim(sim), print_err("init_philo failed"));
	return (0);
}
