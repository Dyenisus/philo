/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:20:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 12:01:25 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Gets the current time as ms
long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

// Swaps two pointers
void	ft_swap(void *p1, void *p2)
{
	void	*tmp;

	ft_memcpy(&tmp, p1, sizeof(void *));
	ft_memcpy(&p1, p2, sizeof(void *));
	ft_memcpy(&p2, tmp, sizeof(void *));
}
