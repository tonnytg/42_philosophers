#include "philosopher.h"

void	wait_threads(t_conf *config, t_threads *threads)
{
	int	i;

	i = 0;
	while (i < config->philo_count)
	{
		pthread_join(threads[i].thread, NULL);
		i++;
	}
}

int create_threads(t_conf *conf, t_threads *threads)
{
	int i;
	int result;

	i = 0;
	while (i < conf->philo_count)
	{
		t_resources *resources = malloc(sizeof(t_resources));
		resources->id = i;
		result = pthread_create(&threads[i].thread, NULL, &routine, resources);
		if (result != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}
