/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:35:56 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:35:57 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	run_sleep(t_philosopher *philosopher)
{
	int	current_time;
	int	live_time;

	if (philosopher->config->panic_stop == TRUE
		|| check_health(philosopher))
		return (1);
	current_time = get_time();
	live_time = current_time - philosopher->created_at;
	printf("%d %d is sleeping\n", live_time, philosopher->id);
	usleep(philosopher->config->time_to_sleep * 1000);
	return (0);
}
