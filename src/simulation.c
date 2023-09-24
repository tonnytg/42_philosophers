#include "../headers/philosopher.h"

void	clean_all(t_simulation *simulation)
{
	printf("clean - %p\n", simulation);
//	pthread_mutex_destroy(&simulation);
//	free(simulation->config);
//	free(simulation->threads);
//	free(simulation->resources);
}

void	init_simulation_struct(t_simulation *simulation)
{
	simulation->config = calloc(1, sizeof(t_config));
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
