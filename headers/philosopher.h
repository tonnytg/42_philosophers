#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef PHILO_H
#define PHILO_H

#define THREADS 10

#define SLEEP 0
#define EAT 1
#define THINK 2

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

# define SLEEP 0
# define EAT 1
# define THINK 2

# define FALSE 0
# define TRUE 1

typedef struct s_resources
{
	pthread_mutex_t	mutex;
	int				*forks;
}	t_resources;

typedef struct s_status
{
	int	status;
	int has_eated;
	int	has_sleeped;
	int	has_thinked;
}	t_status;

typedef struct s_philosopher_config
{
	int		when_started;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_quota;
	int 	status;
	int 	id;
}	t_philosopher_config;

typedef struct s_config
{
	t_resources				*shared;
	t_philosopher_config	*philosopher;
	t_philosopher_config	thread;
	int						philo_count;
	pthread_mutex_t			mutex;
}	t_config;

typedef struct s_threads
{
	pthread_t	thread;
}	t_threads;

typedef struct s_simulation
{
	t_config	*config;
	t_threads	*threads;
	t_resources	*resources;
}	t_simulation;

int		ft_atoi(const char *nptr);
void	wait_threads(t_simulation *simulation);
int		create_threads(t_simulation *simulation);
void	clean_all(t_simulation *simulation);
void	set_config(t_simulation *simulation, int argc, char **argv);
void	init_simulation_struct(t_simulation *simulation);
void	start_simulation(t_simulation *simulation);
void	end_simulation(t_simulation *simulation);
void	*routine(void *arg);

#endif
