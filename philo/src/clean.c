/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c       		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:36:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:36:18 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

void	clean_forks(t_simulation *simulation)
{
	int	i;

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

void	clean_thread_return(t_simulation *simulation)
{
	if (simulation->err == 1)
		return ;
	if (simulation->thread_return)
		free(simulation->thread_return);
}

void	clean_simulation(t_simulation *simulation)
{
	int	i;

	int j = 0;
	while(j < simulation->config->count)
	{
		free(simulation->thread_return[j]);
		j++;
	}
	free(simulation->thread_return);


	clean_forks(simulation);
	i = 0;
	while (i < simulation->config->count)
	{
		if (simulation->philosophers[i]->info)
			free(simulation->philosophers[i]->info);
		if (simulation->philosophers[i])
			free(simulation->philosophers[i]);
		i++;
	}

	pthread_detach(simulation->threads[simulation->thread_dead]);
	free(simulation->threads);

	free(simulation->philosophers);
	clean_thread_return(simulation);
	// if (simulation->threads)
		free(simulation->threads);
	// if (simulation->config)
		free(simulation->config);
	// if (simulation)
		free(simulation);
}
