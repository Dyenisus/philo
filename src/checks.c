/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:41:09 by yesoytur          #+#    #+#             */
/*   Updated: 2025/07/24 11:50:18 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// 5 - The number of philosophers
// 800 - The time a philosopher will die if he doesn't eat
// 200 - The time it takes a philosopher to eat
// 200 - The time it takes a philosopher to sleep
// 7 - Number of times all the philosophers need to eat before terminating the program optional argument

// Checks the number of arguments
int	count_check(int argc)
{
	return (argc == 5 || argc == 6);
}

// Checks if the arguments given are numbers
int	argv_int_check(char **argv)
{
	char	**arg;
	char	*ch;

	arg = argv + 1;
	while (*arg)
	{
		ch = *arg;
		if (!*ch)
			return (0);
		while (*ch)
		{
			if (!ft_isdigit(*ch))
				return (0);
			ch++;
		}
		arg++;
	}
	return (1);
}

// Checks number validity
int	isvalid_check(int argc, char **argv)
{
	char	**arg;
	int		index;

	arg = argv + 1;
	index = 1;
	while (index < argc)
	{
		if (index != 5 && (*arg)[0] == '0')
			return (0);
		arg++;
		index++;
	}
	return (1);
}

// Parent of Checks
int	check_input(int argc, char **argv)
{
	if (!count_check(argc))
		return (0);
	if (!argv_int_check(argv))
		return (0);
	if (!isvalid_check(argc, argv))
		return (0);
	return (1);
}
