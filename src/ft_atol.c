/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:22:14 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:06:14 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

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
