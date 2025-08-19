/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:45:26 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 10:24:43 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Converts the arguments to the list
static long	*conv_to_nbr_list(int argc, char **argv)
{
	long	*list;
	int		i;
	int		ok;

	list = malloc(sizeof(long) * (argc - 1));
	if (!list)
		return (NULL);
	i = 0;
	while (++argv, --argc)
	{
		list[i] = ft_atol(*argv, &ok);
		if (!ok)
			return (free(list), NULL);
		i++;
	}
	return (list);
}

// Checks and Prepares arguments and converts them to long *list
long	*prep(int argc, char **argv)
{
	long	*list;

	if (!first_checks(argc, argv))
		return (NULL);
	list = conv_to_nbr_list(argc, argv);
	if (!list)
		return (NULL);
	if (!secondary_checks(argc, list))
		return (free(list), NULL);
	return (list);
}
