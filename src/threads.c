#include "../headers/philosopher.h"

int	wait_threads(t_simulation *simulation)
{
	int	i;
	int err;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		err = pthread_join(simulation->threads[i].thread, NULL);
		if (err != 0)
			return (1);
		i++;
	}
	return (0);
}

int get_time_now()
{
	return 1629900000;
}

int	create_threads(t_simulation *simulation)
{
	int						err;
	int						i;
	t_threads				**threads;

	i = 0;
	threads = calloc(simulation->config->philo_count, sizeof(t_threads));
	while (i < simulation->config->philo_count)
	{
		threads[i] = calloc(1, sizeof(t_threads));
		threads[i]->id = i;
		threads[i]->config = simulation->config;
		err = pthread_create(&simulation->threads[i].thread, NULL, (void *)&routine, threads[i]);
		if (err != 0)
		{
			printf("ERROR when tries create thread - code: %d\n", err);
			return (err);
		}
		i++;
	}
	return (0);
}
