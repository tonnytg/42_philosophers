/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:36:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:39:13 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

void	*routine(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->config->loop || philosopher->config->loop == -1)
	{
		if (run_sleep(philosopher)
			|| run_eat(philosopher)
			|| run_think(philosopher))
			break ;
		i++;
	}
	if (philosopher->info->is_live == FALSE)
		return (philosopher);
	return (NULL);
}
