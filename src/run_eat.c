# include "../headers/philosopher.h"

void run_eat(t_philosopher *philosopher)
{
	int current_time;
	int live_time;
	t_table *t;

	t = philosopher->config->table;
	check_health(philosopher);

	if (philosopher->config->count > 1)
	{
		int right_fork_id = philosopher->id;
		int left_fork_id = (philosopher->id + 1) % philosopher->config->count; // Garfo à esquerda

		if (philosopher->id % 2 == 0) {
			// Filósofos pares pegam primeiro o garfo direito
			if (!pthread_mutex_lock(&t->forks[right_fork_id]->mutex)) {
				if (!pthread_mutex_lock(&t->forks[left_fork_id]->mutex)) {
					current_time = get_time();
					live_time = current_time - philosopher->created_at;
					printf("%d %d is eating\n", live_time, philosopher->id);

					usleep(philosopher->config->time_to_eat * 1000);
					philosopher->info->last_time_ate = current_time;
					pthread_mutex_unlock(&t->forks[left_fork_id]->mutex);
				}
				pthread_mutex_unlock(&t->forks[right_fork_id]->mutex);
			} else {
				printf("skip eat\n");
			}
		} else {
			// Filósofos ímpares pegam primeiro o garfo esquerdo
			if (!pthread_mutex_lock(&t->forks[left_fork_id]->mutex)) {
				if (!pthread_mutex_lock(&t->forks[right_fork_id]->mutex)) {
					current_time = get_time();

					live_time = current_time - philosopher->created_at;
					printf("%d %d is eating\n", live_time, philosopher->id);
					usleep(philosopher->config->time_to_eat * 1000);
					philosopher->info->last_time_ate = current_time;
					pthread_mutex_unlock(&t->forks[right_fork_id]->mutex);
				}
				pthread_mutex_unlock(&t->forks[left_fork_id]->mutex);
			} else {
				printf("skip eat\n");
			}
		}
	}
}
