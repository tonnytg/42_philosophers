#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

#define SLEEP 0
#define EAT 1
#define THINK 2

# define FALSE 0
# define TRUE 1

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct s_config
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int loop;
	int	count;
} t_config;

typedef struct s_fork
{
	int				is_used;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_table
{
	t_fork	*forks;
} t_table;

typedef struct s_info
{
		int	is_live;
		int	last_eat;
		int	last_sleep;
		int	last_think;
		int	last_action;
		int	count_eat;
} t_info;

typedef struct s_philosopher
{
	int			id;
	int 		action;
	t_config	*config;
	t_info		*info;
}	t_philosopher;

typedef struct s_simulation
{
	pthread_t	*threads;
	t_config	*config;
} t_simulation;

int		ft_atoi(const char *nptr);
int		wait_threads(t_simulation *simulation);
int		create_threads(t_simulation *simulation);
void	clean_all(t_simulation *simulation);
void	set_config(t_simulation *simulation, int argc, char **argv);
void	set_philosophers(t_simulation *simulation);
void	init_simulation_struct(t_simulation *simulation);
void	start_simulation(t_simulation *simulation);
void	end_simulation(t_simulation *simulation);
void	*routine(t_philosopher *philo);

#endif
