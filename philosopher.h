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
	int	id;
	int	forks;
}	t_resources;

typedef struct s_threads
{
	pthread_t	thread;
	int			id;
	int			action;
}	t_threads;

int	ft_atoi(const char *nptr);

#endif
