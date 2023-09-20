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

	i = 0;
	while (i < simulation->config->philo_count)
	{
		simulation->config->philosopher = calloc(1, sizeof(t_philosopher_config));
		simulation->config->philosopher->id = i;
		simulation->config->philosopher->when_started = get_time_now();
		err = pthread_create(&simulation->threads[i].thread, NULL, &routine, simulation->config);
		if (err != 0)
		{
			printf("Error when tries create thread - Code: %d\n", err);
			return (err);
		}
		i++;
	}
	return (0);
}
