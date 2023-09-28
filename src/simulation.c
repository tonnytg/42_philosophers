#include "../headers/philosopher.h"

void clean_philosopher(t_philosopher *philosopher)
{
	if (philosopher->info != NULL)
		free(philosopher->info);
}

void clean_forks(t_simulation *simulation)
{
	int i;

	if (simulation->err == 1)
		return ;
	i = 0;
	while (i < simulation->config->count)
	{
		if (simulation->config->table->forks[i])
			pthread_mutex_destroy(&simulation->config->table->forks[i]->mutex);
		if (simulation->config->table->forks[i])
			free(simulation->config->table->forks[i]);		
		i++;
	}
	free(simulation->config->table->forks);
	free(simulation->config->table);
}

void clean_thread_return(t_simulation *simulation)
{
	int	i;

	if (simulation->err == 1)
		return ;
	i = 0;
	while (i < simulation->config->count)
	{
		if (simulation->thread_return[i])
			free(simulation->thread_return[i]);
		i++;
	}
	if (simulation->thread_return)
		free(simulation->thread_return);
}

void	clean_simulation(t_simulation *simulation)
{
	int i;

	i = 0;
	while(i < simulation->config->count)
	{
		clean_philosopher(simulation->philosophers[i]);
		i++;
	}
	clean_forks(simulation);
	free(simulation->philosophers);
	clean_thread_return(simulation);
	if (simulation->threads)
		free(simulation->threads);
	if (simulation->config)
		free(simulation->config);
	if (simulation)
		free(simulation);
}

void	init_simulation_struct(t_simulation *simulation)
{
	simulation->config = ft_calloc(1, sizeof(t_config));
	simulation->err = 0;
}

void	start_simulation(t_simulation *simulation)
{
	if (simulation->err)
		return ;
	create_threads(simulation);
	wait_threads(simulation);
}

void	end_simulation(t_simulation *simulation)
{
	clean_simulation(simulation);
}
