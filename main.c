#include "./headers/philosopher.h"

int	main(int argc, char **argv)
{
	t_simulation	*simulation;

	simulation = calloc(1, sizeof(t_simulation));
	init_simulation_struct(simulation);
	set_config(simulation, argc, argv);
	set_philosophers(simulation);
	start_simulation(simulation);
	end_simulation(simulation);
	return (0);
}
