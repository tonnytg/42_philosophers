/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:35:50 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:41:15 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

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
