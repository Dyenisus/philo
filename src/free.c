/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:19:12 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:06:37 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_sim(t_sim *sim)
{
	int	i;

	if (sim->forks)
	{
		i = 0;
		while (i < sim->cfg.count)
			pthread_mutex_destroy(&sim->forks[i++]);
		free(sim->forks);
	}
	pthread_mutex_destroy(&sim->m_dead);
	pthread_mutex_destroy(&sim->m_print);
}

int	join_philos(t_philo *p, int n)
{
	int	i;
	int	fails;

	if (!p)
		return (print_err("null philos"));
	if (n <= 0)
		return (0);
	i = 0;
	fails = 0;
	while (i < n)
	{
		if (pthread_join(p[i++].th, NULL) != 0)
			fails++;
	}
	if (fails)
		return (print_err("pthread_join failed"));
	return (0);
}

void	free_philos(t_philo **p)
{
	if (!p || !*p)
		return ;
	free(*p);
	*p = NULL;
}

int	join_threads(pthread_t mon, t_philo *philos)
{
	if (pthread_join(mon, NULL) != 0)
		return (print_err("monitor pthread_join failed"));
	return (join_philos(philos, philos->sim->cfg.count));
}
