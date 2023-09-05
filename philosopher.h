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

typedef struct s_conf
{
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_quota;
}	t_conf;

typedef struct s_resources
{
	int				id;
	int				forks;
	t_conf			*config;
	pthread_mutex_t	mutex;
}	t_resources;

typedef struct s_info
{
	int	id;
}	t_info;

typedef struct s_threads
{
	pthread_t	thread;
	int			id;
	int			action;
}	t_threads;

int		ft_atoi(const char *nptr);
void	wait_threads(t_conf *config, t_threads *threads);
int		create_threads(t_conf *conf, t_threads *threads);
void	clean_all(t_conf *conf, t_threads *threads, t_resources *resources);
void	set_config(t_conf *config, int argc, char **argv);
void	*routine(void *arg);

#endif
