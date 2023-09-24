#include "../headers/philosopher.h"

int	wait_threads(t_simulation *simulation)
{
	int	i;
	int err;

	i = 0;
	while (i < simulation->config->count)
	{
		err = pthread_join(simulation->threads[i], NULL);
		if (err != 0)
			return (1);
		i++;
	}
	return (0);
}

int get_time_now()
{
	return 1629900000;
}

void set_philosopher(
		t_simulation *simulation,
		t_philosopher *philosopher,
		int i)
{
	philosopher->id = i;
	philosopher->config = simulation->config;
	philosopher->info = calloc(1, sizeof(t_info));
}

int	create_threads(t_simulation *simulation)
{
	int						err;
	int						i;
	t_philosopher **philosophers;

	philosophers = calloc(simulation->config->count, sizeof(t_philosopher));
	i = 0;
	while (i < simulation->config->count)
	{
		philosophers[i] = calloc(1, sizeof(t_philosopher));
		set_philosopher(simulation, philosophers[i], i);
		err = pthread_create(
				&simulation->threads[i],
				NULL,
				(void *)&routine,
				philosophers[i]);
		if (err != 0)
		{
			printf("ERROR when tries create thread - code: %d\n", err);
			return (err);
		}
		i++;
	}
	return (0);
}
