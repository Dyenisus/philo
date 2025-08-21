/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoyturstudent.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:02:37 by yesoytur          #+#    #+#             */
/*   Updated: 2025/08/21 14:03:56 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cfg
{
	int	count;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
}	t_cfg;

typedef struct s_sim
{
	t_cfg			cfg;
	long			start_ms;
	int				dead;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	*forks;
}	t_sim;

typedef struct s_philo
{
	int				id;
	int				meals;
	long			last_meal;
	pthread_t		th;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_sim			*sim;
}	t_philo;

int		prep(int ac, char **av, t_sim *sim, t_philo **philos);
int		first_checks(int argc, char **argv);
int		secondary_checks(int argc, long *list);
long	ft_atol(const char *s, int *ok);
int		ft_isdigit(int c);
void	init_cfg(t_cfg *cfg, long *list, int ac);
int		init_sim(t_sim *sim, t_cfg cfg);
int		init_philos(t_philo **philos, t_sim *sim);
void	free_sim(t_sim *sim);
int		join_philos(t_philo *p, int n);
void	free_philos(t_philo **p);
int		join_threads(pthread_t mon, t_philo *philos);
int		print_err(const char *msg);
void	print_state(t_philo *p, const char *msg);
void	print_dead_stop(t_philo *p);
long	now_ms(void);
void	ft_swap(pthread_mutex_t **a, pthread_mutex_t **b);
int		ms_sleep(t_sim *s, long ms);
int		get_dead(t_sim *sim);
void	set_dead(t_sim *sim, int v);
int		take_forks(t_philo *p);
void	drop_forks(t_philo *p);
void	*philo_routine(void *philos);
void	*monitor_routine(void *philos);

#endif
