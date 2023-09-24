# include "../headers/philosopher.h"

void run_think(t_philosopher *philosopher)
{
	int current_time;
	int live_time;

	check_health(philosopher);
	current_time = get_time();
	live_time = current_time - philosopher->created_at;
	printf("%d %d is thinking\n", live_time, philosopher->id);
}