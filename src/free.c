/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:19:12 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 12:55:33 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Frees Sim Struct
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

// Joins Philo threads
int	join_philos(t_philo *p, int n)
{
	int	i;
	int	fails;

	if (!p)
		return (print_err("NULL Philos"));
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
		return (print_err("Joining Threads Failed"));
	return (0);
}

// Frees Philo Struct
void	free_philos(t_philo **p)
{
	if (!p || !*p)
		return ;
	free(*p);
	*p = NULL;
}
