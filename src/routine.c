/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:08:51 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:07:57 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	delay_time(t_philo *p)
{
	while (now_ms() < p->sim->start_ms)
		usleep(100);
	if (p->id % 2 == 0)
		usleep(1000);
}

static int	do_eat(t_philo *p)
{
	if (take_forks(p))
		return (1);
	pthread_mutex_lock(&p->sim->m_meal);
	p->last_meal = now_ms();
	p->meals++;
	pthread_mutex_unlock(&p->sim->m_meal);
	print_state(p, "is eating");
	if (ms_sleep(p->sim, p->sim->cfg.t_eat))
		return (drop_forks(p), 1);
	drop_forks(p);
	return (0);
}

static void	do_sleep(t_philo *p)
{
	print_state(p, "is sleeping");
	(void)ms_sleep(p->sim, p->sim->cfg.t_sleep);
}

static void	do_think(t_philo *p)
{
	print_state(p, "is thinking");
	(void)ms_sleep(p->sim, 100);
}

void	*philo_routine(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	delay_time(p);
	while (!get_dead(p->sim))
	{
		if (do_eat(p))
			break ;
		if (get_dead(p->sim))
			break ;
		do_sleep(p);
		do_think(p);
	}
	return (NULL);
}
