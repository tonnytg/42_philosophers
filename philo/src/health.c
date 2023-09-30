/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:36:14 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:38:12 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	check_health(t_philosopher *philosopher)
{
	int	current_time;
	int	time_since_last_eat;

	current_time = get_time();
	time_since_last_eat = current_time - philosopher->info->last_time_ate;
	if (time_since_last_eat >= philosopher->config->time_to_die)
	{
		philosopher->info->is_live = FALSE;
		philosopher->config->panic_stop = 1;
		return (1);
	}
	return (0);
}
