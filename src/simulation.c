#include "../headers/philosopher.h"

void	clean_all(t_simulation *simulation)
{
	pthread_mutex_destroy(&simulation->resources->mutex);
//	free(simulation->config);
//	free(simulation->threads);
//	free(simulation->resources);
}

void	init_simulation_struct(t_simulation *simulation)
{
	simulation->config = calloc(1, sizeof(t_config));
	simulation->config->philosopher = calloc(1, sizeof(t_philosopher_config));
	simulation->config->shared = calloc(1, sizeof(t_resources));
	simulation->resources = calloc(1, sizeof(t_resources));
	simulation->resources->forks = calloc(simulation->config->philo_count, sizeof(int));
	simulation->threads = calloc(simulation->config->philo_count, sizeof(t_threads));
	pthread_mutex_init(&simulation->resources->mutex, NULL);
}

void	start_simulation(t_simulation *simulation)
{
	create_threads(simulation);
	wait_threads(simulation);
}

void	end_simulation(t_simulation *simulation)
{
	clean_all(simulation);
}
