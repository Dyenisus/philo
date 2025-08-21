/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:41:09 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:06:25 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	count_check(int argc)
{
	return (argc == 5 || argc == 6);
}

static int	argv_int_check(char **argv)
{
	char	*str;

	argv++;
	while (*argv)
	{
		str = *argv;
		if (*str == '+')
			str++;
		if (!*str)
			return (0);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		argv++;
	}
	return (1);
}

int	first_checks(int argc, char **argv)
{
	return (count_check(argc) && argv_int_check(argv));
}
