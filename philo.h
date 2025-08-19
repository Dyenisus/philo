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

/* --------- utils --------- */

int		print_err(const char *msg);
long	now_ms(void);
void	ft_swap(void *p1, void *p2);

#endif
