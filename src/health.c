# include "../headers/philosopher.h"

void check_health(t_philosopher *philosopher)
{
	int current_time;
	int result;

	current_time = get_time();
	result = current_time - philosopher->info->last_time_ate;
	printf("result: %d\n", result);
	if ( result > philosopher->config->time_to_die)
	{
		printf("result: %d\n", result);
		printf("%d %d died\n", current_time - philosopher->created_at, philosopher->id);
		exit(1);
	}
}