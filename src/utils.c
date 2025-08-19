/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:20:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 13:23:16 by yesoytur         ###   ########.fr       */
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

// Sleeps untill ms time passes
void	ms_sleep(long ms)
{
	long	start;

	start = now_ms();
	while (now_ms() - start < ms)
		usleep(100);
}

// Gets the dead value
int	get_dead(t_sim *sim)
{
	int	v;

	pthread_mutex_lock(&sim->m_dead);
	v = sim->dead;
	pthread_mutex_unlock(&sim->m_dead);
	return (v);
}

// Gets the dead value
void	set_dead(t_sim *sim, int v)
{
	pthread_mutex_lock(&sim->m_dead);
	sim->dead = v;
	pthread_mutex_unlock(&sim->m_dead);
}
