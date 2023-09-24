#include "../headers/philosopher.h"

void	*routine(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->config->loop || philosopher->config->loop == -1)
	{
		run_sleep(philosopher);
		run_eat(philosopher);
		run_think(philosopher);
		i++;
	}
	return (NULL);
}
