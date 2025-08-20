/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:44:28 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/20 11:14:45 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Prints the given Error message and returns 1
int	print_err(const char *msg)
{
	size_t	i;

	write(2, "Error: ", 7);
	i = 0;
	while (msg[i])
		i++;
	write(2, msg, i);
	write(2, "\n", 1);
	return (1);
}

// Prints the given message for philos (think and sleep only)
void	print_state(t_philo *p, const char *msg)
{
	long	ts;

	pthread_mutex_lock(&p->sim->m_print);
	if (!get_dead(p->sim))
	{
		ts = now_ms() - p->sim->start_ms;
		printf("%ld %d %s\n", ts, p->id, msg);
	}
	pthread_mutex_unlock(&p->sim->m_print);
}

// Prints the given message for philos (dead only)
void	print_dead_stop(t_philo *p)
{
	long	ts;

	pthread_mutex_lock(&p->sim->m_print);
	if (!get_dead(p->sim))
	{
		ts = now_ms() - p->sim->start_ms;
		printf("%ld %d died\n", ts, p->id);
		set_dead(p->sim, 1);
	}
	pthread_mutex_unlock(&p->sim->m_print);
}
