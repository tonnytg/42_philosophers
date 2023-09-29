/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:35:32 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:35:33 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philosopher.h"

int	main(int argc, char **argv)
{
	t_simulation	*simulation;

	simulation = ft_calloc(1, sizeof(t_simulation));
	init_simulation_struct(simulation);
	set_config(simulation, argc, argv);
	set_philosophers(simulation);
	start_simulation(simulation);
	end_simulation(simulation);
	return (0);
}
