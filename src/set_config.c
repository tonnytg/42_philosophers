#include "../headers/philosopher.h"

void	set_config(t_simulation *simulation, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	simulation->config->philo_count = ft_atoi(argv[1]);
	simulation->config->philosopher->time_to_die = ft_atoi(argv[2]);
	simulation->config->philosopher->time_to_eat = ft_atoi(argv[3]);
	simulation->config->philosopher->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->config->philosopher->meals_quota = ft_atoi(argv[5]);
	else
		simulation->config->philosopher->meals_quota = -1;
}
