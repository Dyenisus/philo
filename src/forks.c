/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:11:38 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/20 22:49:45 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->left);
	print_state(p, "has taken a fork");
	if (p->sim->cfg.count == 1 || p->left == p->right)
	{
		while (!get_dead(p->sim))
			usleep(1000);
		pthread_mutex_unlock(p->left);
		return (1);
	}
	if (get_dead(p->sim))
		return (pthread_mutex_unlock(p->left), 1);
	pthread_mutex_lock(p->right);
	print_state(p, "has taken a fork");
	return (0);
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}
