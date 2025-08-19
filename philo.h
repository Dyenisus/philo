#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

/* --------- parse --------- */

long	*prep(int argc, char **argv);
int		first_checks(int argc, char **argv);
int		secondary_checks(int argc, long *list);
long	ft_atol(const char *s, int *ok);

/* ------------- structs ------------- */

// Configurations Struct
typedef struct s_cfg
{
	int	count;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
}	t_cfg;

// Simulation Struct
typedef struct s_sim
{
	t_cfg			cfg;
	long			start_ms;
	int				dead;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*forks;
}	t_sim;

// Philosopher Struct
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

/* --------- init --------- */

void	init_cfg(t_cfg *cfg, long *list, int ac);
int		init_sim(t_sim *sim, t_cfg cfg);
int		init_philos(t_philo **philos, t_sim *sim);

/* --------- free --------- */

void	free_sim(t_sim *sim);
int		join_philos(t_philo *p, int n);
void	free_philos(t_philo **p);


/* --------- print --------- */

int		print_err(const char *msg);
void	print_state(t_philo *p, const char *msg);
void	print_dead_stop(t_philo *p);

/* --------- utils --------- */

long	now_ms(void);
void	ft_swap(void *p1, void *p2);
void	ms_sleep(long ms);
int		get_dead(t_sim *sim);
void	set_dead(t_sim *sim, int v);

#endif
