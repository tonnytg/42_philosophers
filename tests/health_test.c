#include "../headers/philosopher.h"
#include <assert.h>

int	check_health2(t_philosopher *philosopher)
{
	int current_time;
	int time_since_last_eat;

	current_time = get_time();
	time_since_last_eat = current_time - philosopher->info->last_time_ate;
	if (time_since_last_eat >= philosopher->config->time_to_die)
	{
		printf("%d %d died\n",
			   current_time - philosopher->created_at,
			   philosopher->id);
		return (1);
	}
	return (0);
}

int main(void) {

	t_philosopher *philosopher;

	philosopher = malloc(sizeof(t_philosopher));
	philosopher->info = malloc(sizeof(t_info));
	philosopher->info->last_time_ate = get_time();

	// test with assert
	assert(check_health(philosopher) == 0);


	return (0);
}