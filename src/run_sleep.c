# include "../headers/philosopher.h"

int run_sleep(t_philosopher *philosopher)
{
	int current_time;
	int live_time;

	if(check_health(philosopher))
		return (1);
	current_time = get_time();
	live_time = current_time - philosopher->created_at;
	printf("%d %d is sleeping\n", live_time, philosopher->id);
	usleep(philosopher->config->time_to_sleep * 1000);
	return (0);
}
