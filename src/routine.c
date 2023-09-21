#include "../headers/philosopher.h"

void run_sleep(t_config *config)
{
	printf("timestamp_in_ms %d is sleeping\n", config->thread.id);
	usleep(1000 * 1000);
}

//void run_eat(t_config *philosopher)
//{
//	pthread_mutex_lock(&resources->mutex);
//	printf(ANSI_COLOR_YELLOW "timestamp_in_ms %d is eating\n" ANSI_COLOR_RESET, id);
//	usleep(1000 * 1000);
//	pthread_mutex_unlock(&resources->mutex);
//}

//void run_think(t_config *philosopher)
//{
//	printf("timestamp_in_ms %d is thinking\n", id);
//	usleep(1000 * 1000);
//}

//void set_philosopher_config(t_resources *resources, t_conf *philosopher)
//{
//	philosopher->philo_count = 10;
//	philosopher->time_to_die = 10;
//	philosopher->time_to_eat = 10;
//	philosopher->time_to_sleep = 10;
//	philosopher->meals_quota = -1;
//	resources->philosopher = philosopher;
//}

void *routine(void *arg)
{
	t_config				*config;
	int						i;

	config = (t_config *)arg;

	i = 0;
	while (i < 10)
	{
		run_sleep(config);
//		run_eat(philosopher);
//		run_think(philosopher);
		i++;
	}
//	free(arg);
	return (NULL);
}
