#include "../headers/philosopher.h"

void *routine(t_philosopher *philosopher)
{
	int						i;

	i = 0;
	while (i < philosopher->config->loop)
	{
		printf("Philosopher ID: %d\n", philosopher->id);
		printf("Last Eat: %d\n", philosopher->info->last_eat);
		printf("Last Sleep: %d\n", philosopher->info->last_sleep);
		printf("Last Think: %d\n", philosopher->info->last_think);
		usleep(1000 * 1000);
		i++;
	}
	return (NULL);
}
