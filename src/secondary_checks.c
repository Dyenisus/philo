/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:15:17 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:07:26 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <limits.h>

static int	in_range(long v, long lo, long hi)
{
	return (v >= lo && v <= hi);
}

int	secondary_checks(int argc, long *list)
{
	int	nargs;

	nargs = argc - 1;
	if (!in_range(list[0], 1, 200))
		return (0);
	if (!in_range(list[1], 1, INT_MAX))
		return (0);
	if (!in_range(list[2], 1, INT_MAX))
		return (0);
	if (!in_range(list[3], 1, INT_MAX))
		return (0);
	if (nargs == 5 && !in_range(list[4], 0, INT_MAX))
		return (0);
	return (1);
}
