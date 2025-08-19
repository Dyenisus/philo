/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:14 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 10:28:51 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Just a silly helper isspace
static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

// Project specified version of atol
long	ft_atol(const char *s, int *ok)
{
	long	res;

	*ok = 0;
	res = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		return (0);
	if (*s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s && ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	if (*s)
		return (0);
	*ok = 1;
	return (res);
}
