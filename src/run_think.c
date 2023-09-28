# include "../headers/philosopher.h"

int run_think(t_philosopher *philosopher)
{
	int current_time;
	int live_time;

	if (check_health(philosopher))
		return (1);
	current_time = get_time();
	live_time = current_time - philosopher->created_at;
	printf("%d %d is thinking\n", live_time, philosopher->id);
	return (0);
}