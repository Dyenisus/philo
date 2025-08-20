/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:19:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/20 21:28:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int start_monitor(t_philo *p, pthread_t *mon)
{
    if (pthread_create(mon, NULL, monitor_routine, p) != 0)
        return (print_err("monitor pthread_create failed"));
    return (0);
}

static int	start_threads(t_philo *p, int n)
{
	int	i;

	if (!p || n <= 0)
		return (print_err("invalid philo list"));
	p->sim->start_ms = now_ms() + 250;
	i = 0;
	while (i < p->sim->cfg.count)
    	p[i++].last_meal = p->sim->start_ms;
	i = 0;
	while (i < n)
	{
		if (pthread_create(&p[i].th, NULL, philo_routine, &p[i]) != 0)
			return (print_err("philo pthread_create failed"));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_sim		sim;
	t_philo		*philos;
	pthread_t	mon;

	philos = NULL;
	if (prep(ac, av, &sim, &philos))
		return (1);
	if (start_threads(philos, sim.cfg.count))
		return (free_philos(&philos), free_sim(&sim), 1);
	if (start_monitor(philos, &mon))
		return (free_philos(&philos), free_sim(&sim), 1);
	if (join_threads(mon, philos))
		return (free_philos(&philos), free_sim(&sim), 1);
	return (free_philos(&philos), free_sim(&sim), 0);
}
