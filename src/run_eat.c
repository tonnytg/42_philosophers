/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:35:59 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:36:00 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	run_eat(t_philosopher *philosopher)
{
	int		current_time;
	int		live_time;
	int		right_fork_id;
	int		left_fork_id;
	t_table	*t;

	t = philosopher->config->table;
	if (check_health(philosopher))
		return (1);
	if (philosopher->config->count > 1)
	{
		right_fork_id = philosopher->id;
		left_fork_id = (philosopher->id + 1) % philosopher->config->count;
		if (philosopher->id % 2 == 0)
		{
			if (!pthread_mutex_lock(&t->forks[right_fork_id]->mutex))
			{
				if (!pthread_mutex_lock(&t->forks[left_fork_id]->mutex))
				{
					current_time = get_time();
					live_time = current_time - philosopher->created_at;
					printf("%d %d is eating\n", live_time, philosopher->id);
					usleep(philosopher->config->time_to_eat * 1000);
					philosopher->info->last_time_ate = current_time;
					pthread_mutex_unlock(&t->forks[left_fork_id]->mutex);
				}
				pthread_mutex_unlock(&t->forks[right_fork_id]->mutex);
			}
			else
			{
				printf("skip eat\n");
			}
		}
		else
		{
			if (!pthread_mutex_lock(&t->forks[left_fork_id]->mutex))
			{
				if (!pthread_mutex_lock(&t->forks[right_fork_id]->mutex))
				{
					current_time = get_time();
					live_time = current_time - philosopher->created_at;
					printf("%d %d is eating\n", live_time, philosopher->id);
					usleep(philosopher->config->time_to_eat * 1000);
					philosopher->info->last_time_ate = current_time;
					pthread_mutex_unlock(&t->forks[right_fork_id]->mutex);
				}
				pthread_mutex_unlock(&t->forks[left_fork_id]->mutex);
			}
			else
			{
				printf("skip eat\n");
			}
		}
	}
	return (0);
}
