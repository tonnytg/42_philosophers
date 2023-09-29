/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_think.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:35:53 by antthoma          #+#    #+#             */
/*   Updated: 2023/09/29 01:35:54 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	run_think(t_philosopher *philosopher)
{
	int	current_time;
	int	live_time;

	if (check_health(philosopher))
		return (1);
	current_time = get_time();
	live_time = current_time - philosopher->created_at;
	printf("%d %d is thinking\n", live_time, philosopher->id);
	return (0);
}
