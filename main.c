#include "philosopher.h"

void *thread(void *arg)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)arg;
	printf("[%d]Philosopher Action: %d\n", philo.id, philo.action);
	return (NULL);
}

int main(void)
{
	t_philosopher	philosopher[THREADS];
	int				i;

	i = 0;
	while(i < THREADS)
	{
		philosopher[i].id = i;
		philosopher[i].action = THINK;
		philosopher[i].left_fork = i;
		philosopher[i].right_fork = (i + 1);
		int result = pthread_create(&philosopher[i].thread, NULL, thread, &philosopher[i]);
		if (result != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(philosopher[i].thread, NULL);
		i++;
	}
	return (0);
}
