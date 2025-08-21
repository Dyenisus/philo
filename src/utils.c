/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:20:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:07:38 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	ft_swap(pthread_mutex_t **a, pthread_mutex_t **b)
{
	pthread_mutex_t	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ms_sleep(t_sim *s, long ms)
{
	long	end;

	end = now_ms() + ms;
	while (now_ms() < end)
	{
		if (s && get_dead(s))
			return (1);
		usleep(1000);
	}
	return (0);
}

int	get_dead(t_sim *sim)
{
	int	v;

	pthread_mutex_lock(&sim->m_dead);
	v = sim->dead;
	pthread_mutex_unlock(&sim->m_dead);
	return (v);
}

void	set_dead(t_sim *sim, int v)
{
	pthread_mutex_lock(&sim->m_dead);
	sim->dead = v;
	pthread_mutex_unlock(&sim->m_dead);
}
