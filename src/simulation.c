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
	printf("init\n");
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
