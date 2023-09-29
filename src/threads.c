/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:35:46 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:35:47 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	wait_threads(t_simulation *simulation)
{
	int				i;
	int				err;
	int				current_time;
	void			**thread_return;
	t_philosopher	*philosopher;

	i = 0;
	thread_return = simulation->thread_return;
	while (i < simulation->config->count)
	{
		thread_return[i] = NULL;
		err = pthread_join(simulation->threads[i], &thread_return[i]);
		if (err != 0)
			return (1);
		if (thread_return[i] != NULL)
		{
			current_time = get_time();
			philosopher = (t_philosopher *)thread_return[i];
			printf("%d %d died\n",
				current_time - philosopher->created_at, philosopher->id);
			return (1);
		}
		i++;
	}
	return (0);
}

void	set_philosopher(
		t_simulation *simulation,
		t_philosopher *philosopher,
		int i)
{
	philosopher->id = i;
	philosopher->created_at = get_time();
	philosopher->config = simulation->config;
	philosopher->info = ft_calloc(1, sizeof(t_info));
	philosopher->info->is_live = TRUE;
	philosopher->info->last_time_ate = get_time();
}

int	create_threads(t_simulation *simulation)
{
	int				err;
	int				i;
	t_philosopher	**philosophers;

	philosophers = simulation->philosophers;
	i = 0;
	while (i < simulation->config->count)
	{
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
