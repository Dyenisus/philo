/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:41:09 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 10:27:18 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Checks argument count 
static int	count_check(int argc)
{
	return (argc == 5 || argc == 6);
}

// Checks if given arguments are digits
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

// Firsthand checks before conversion
int	first_checks(int argc, char **argv)
{
	return (count_check(argc) && argv_int_check(argv));
}
