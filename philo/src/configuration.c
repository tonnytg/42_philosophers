/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:36:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:36:18 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

void	set_config(t_simulation *simulation, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		simulation->err = 1;
		return ;
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

void	set_forks(t_simulation *simulation)
{
	t_config	*c;
	int			i;

	c = simulation->config;
	i = 0;
	while (i < c->count)
	{
		c->table->forks[i] = ft_calloc(1, sizeof(t_fork));
		pthread_mutex_init(&c->table->forks[i]->mutex, NULL);
		i++;
	}
}

void	set_philosophers(t_simulation *simulation)
{
	t_config	*c;
	int			i;

	if (simulation->err)
		return ;
	c = simulation->config;
	simulation->threads = ft_calloc(c->count, sizeof(pthread_t));
	simulation->config->table = ft_calloc(1, sizeof(t_table));
	simulation->config->table->forks = ft_calloc(c->count, sizeof(t_fork *));
	set_forks(simulation);
	simulation->philosophers = ft_calloc(
			simulation->config->count,
			sizeof(t_philosopher));
	i = 0;
	while (i < simulation->config->count)
	{
		simulation->philosophers[i] = ft_calloc(1, sizeof(t_philosopher));
		i++;
	}
	simulation->thread_return = ft_calloc(
			simulation->config->count,
			sizeof(void *));
}
