/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:40:04 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/19 12:54:57 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Inits and assigns the values to Configuration Struct
void	init_cfg(t_cfg *cfg, long *list, int ac)
{
	(*cfg).count = list[0];
	(*cfg).t_die = list[1];
	(*cfg).t_eat = list[2];
	(*cfg).t_sleep = list[3];
	if (ac == 6)
		(*cfg).must_eat = list[4];
	else
		(*cfg).must_eat = -1;
}

static int	init_forks(t_sim *sim)
{
	int	i;

	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->cfg.count);
	if (!sim->forks)
		return ("Forks Cannot be Initialized");
	i = 0;
	while (i < sim->cfg.count)
	{
		if ((pthread_mutex_init(&sim->forks[i++], NULL)) != 0)
			return (print_err("Mutexes Cannot be Initialized"));
	}
	return (0);
}

// Inits and assigns the values to Simulation Struct
int	init_sim(t_sim *sim, t_cfg cfg)
{
	if ((pthread_mutex_init(&sim->m_dead, NULL)) != 0)
		return (print_err("Mutex Cannot be Initialized"));
	if ((pthread_mutex_init(&sim->m_print, NULL)) != 0)
		return (print_err("Mutex Cannot be Initialized"));
	if (init_forks(sim))
		return (1);
	(*sim).cfg = cfg;
	(*sim).start_ms = now_ms();
	(*sim).dead = 0;
	return (0);
}

// Inits and assigns the values of Philosphers Struct
int	init_philos(t_philo **philos, t_sim *sim)
{
	int				i;
	t_philo			*p;

	p = malloc(sizeof(t_philo) * sim->cfg.count);
	if (!p)
		return (print_err("Philo Cannot be Initialized"));
	i = 0;
	while (i < sim->cfg.count)
	{
		p[i].id = i + 1;
		p[i].meals = 0;
		p[i].last_meal = sim->start_ms;
		p[i].left = &sim->forks[i];
		p[i].right = &sim->forks[(i + 1) % sim->cfg.count];
		if ((p[i].id % 2) == 0)
			ft_swap(&p[i].left, &p[i].right);
		i++;
	}
	return (*philos = p, 0);
}
