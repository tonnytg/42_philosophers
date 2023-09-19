#include "philosopher.h"

void clean_all(t_simulation *simulation)
{
	pthread_mutex_destroy(&simulation->resources->mutex);
	free(simulation->config);
	free(simulation->threads);
	free(simulation->resources);
}

void init_simulation_struct(t_simulation *simulation)
{
	simulation->config = calloc(1, sizeof(t_conf));
	simulation->resources = calloc(1, sizeof(t_resources));
	simulation->threads = malloc(sizeof(t_threads) * simulation->config->philo_count);
	pthread_mutex_init(&simulation->resources->mutex, NULL);
}

void start_simulation(t_simulation *simulation)
{
	create_threads(simulation);
	wait_threads(simulation);
}

void end_simulation(t_simulation *simulation)
{
	clean_all(simulation);
}

int main(int argc, char **argv)
{
	t_simulation *simulation;

	simulation = calloc(1, sizeof(t_simulation));
	init_simulation_struct(simulation);
	set_config(simulation, argc, argv);
	start_simulation(simulation);
	end_simulation(simulation);
	return (0);
}
