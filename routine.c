#include "philosopher.h"

void run_sleep(int id)
{
	printf("timestamp_in_ms %d is sleeping\n", id);
	usleep(1000 * 1000);
}

void run_eat(t_resources *resources, int id)
{
	if (pthread_mutex_lock(&resources->mutex) == 0)
	{
		printf(ANSI_COLOR_YELLOW "timestamp_in_ms %d is eating\n" ANSI_COLOR_RESET, id);
		usleep(1000 * 1000);
		pthread_mutex_unlock(&resources->mutex);
	}
}

void run_think(int id)
{
	printf("timestamp_in_ms %d is thinking\n", id);
	usleep(1000 * 1000);
}

void *routine(void *arg)
{
	t_resources *resources;
	int id;

	resources = (t_resources *)arg;
	id = resources->id;
	int i = 0;
	while (i < 10)
	{
		run_sleep(id);
		run_eat(resources, id);
		run_think(id);
		i++;
	}

	free(arg);

	return (NULL);
}