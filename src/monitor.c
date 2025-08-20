/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:49:03 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/20 18:11:26 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_all_fed(t_philo *p, int n)
{
	int	i;
	int	full;

	if (p->sim->cfg.must_eat <= 0)
		return (0);
	full = 0;
	i = 0;
	while (i < n)
	{
		pthread_mutex_lock(&p->sim->m_meal);
		if (p[i].meals >= p->sim->cfg.must_eat)
			full++;
		pthread_mutex_unlock(&p->sim->m_meal);
		i++;
	}
	return (full == n);
}

void	*monitor_routine(void *philos)
{
	t_philo	*p;
	int		i;
	long	lm;
	long	now;

	p = (t_philo *)philos;
	while (!get_dead(p->sim))
	{
		i = 0;
		now = now_ms();
		while (i < p->sim->cfg.count && !get_dead(p->sim))
		{
			pthread_mutex_lock(&p->sim->m_meal);
			lm = p[i].last_meal;
			pthread_mutex_unlock(&p->sim->m_meal);
			if (now - lm >= p->sim->cfg.t_die)
				return (print_dead_stop(&p[i]), NULL);
			i++;
		}
		if (is_all_fed(p, p->sim->cfg.count))
			return (set_dead(p->sim, 1), NULL);
		ms_sleep(p->sim, 1);
	}
	return (NULL);
}
