/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:44:28 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:07:13 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
