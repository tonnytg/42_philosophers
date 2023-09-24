#include "../headers/philosopher.h"

void	set_config(t_simulation *simulation, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	simulation->config->count = ft_atoi(argv[1]);
	simulation->config->time_to_die = ft_atoi(argv[2]);
	simulation->config->time_to_eat = ft_atoi(argv[3]);
	simulation->config->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->config->loop = ft_atoi(argv[5]);
	else
		simulation->config->loop = -1;
}

void	set_philosophers(t_simulation *simulation)
{
	t_config *c;

	c = simulation->config;
	simulation->threads = calloc(c->count, sizeof(pthread_t));

}