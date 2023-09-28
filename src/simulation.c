#include "../headers/philosopher.h"

void clean_philosopher(t_philosopher *philosopher)
{
	if (philosopher->info)
		free(philosopher->info);
	if (philosopher)
		free(philosopher);
}

void	clean_simulation(t_simulation *simulation)
{
	if (simulation->threads)
		free(simulation->threads);
	if (simulation->config)
		free(simulation->config);
	if (simulation)
		free(simulation);
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
	clean_simulation(simulation);
}
