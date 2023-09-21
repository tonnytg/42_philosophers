#include "../headers/philosopher.h"

void	wait_threads(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		pthread_join(simulation->threads[i].thread, NULL);
		i++;
	}
}

int get_time_now()
{
	return 1629900000;
}

int	create_threads(t_simulation *simulation)
{
	int			i;
	int			err;
	t_philosopher_config *philosopher_config;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		philosopher_config = calloc(1, sizeof(t_philosopher_config));

		philosopher_config->id = i;
		philosopher_config->when_started = get_time_now();

		simulation->config->philosopher = philosopher_config;

		err = pthread_create(&simulation->threads[i].thread, NULL, &routine, simulation->config);
		if (err != 0)
		{
			printf("Error when tries create thread - Code: %d\n", err);
			return (err);
		}
		i++;
		free(philosopher_config);
		philosopher_config = NULL;
	}
	return (0);
}
