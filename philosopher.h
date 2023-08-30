#include <stdio.h>
#include <pthread.h>

#ifndef PHILO_H
#define PHILO_H

#define THREADS 10

#define SLEEP 0
#define EAT 1
#define THINK 2

typedef struct s_philosopher
{
	pthread_t	thread;
	int			id;
	int			left_fork;
	int			right_fork;
	int			action;
}	t_philosopher;

#endif
