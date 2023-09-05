#include "philosopher.h"

void *routine(void *arg)
{
	t_resources	*resources;
	int			id;

	resources = (t_resources *)arg;
	id = resources->id;
	int i = 0;
	while( i < 10)
	{
		printf("timestamp_in_ms %d is sleeping\n", id);
		usleep(1000 * 1000);
		if (pthread_mutex_lock(&resources->mutex) != 0) {
			printf(ANSI_COLOR_RED "Erro ao bloquear mutex\n" ANSI_COLOR_RESET);
			exit(1);
		}

		printf(ANSI_COLOR_YELLOW "timestamp_in_ms %d is eating\n" ANSI_COLOR_RESET, id);
		usleep(1000 * 1000);

		if (pthread_mutex_unlock(&resources->mutex) != 0) {
			printf(ANSI_COLOR_RED "Erro ao desbloquear mutex\n" ANSI_COLOR_RESET);
			exit(1);
		}
		printf("timestamp_in_ms %d is thinking\n", id);
		usleep(1000 * 1000);
		i++;
	}

	free(arg);

	return (NULL);
}

void	set_config(t_conf *config, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	config->philo_count = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		config->meals_quota = ft_atoi(argv[5]);
	else
		config->meals_quota = -1;
}

void clean_all(t_conf *conf, t_threads *threads, t_resources *resources)
{
	free(conf);
	free(threads);
	free(resources);
}

int main(int argc, char **argv)
{
	t_conf		*conf;
	t_threads	*threads;
	t_resources	*resources;

	conf = malloc(sizeof(t_conf));
	set_config(conf, argc, argv);
	threads = malloc(sizeof(t_threads) * conf->philo_count);
	resources = malloc(sizeof(t_resources));
	pthread_mutex_init(&resources->mutex, NULL);
	create_threads(conf, threads);
	wait_threads(conf, threads);
	pthread_mutex_destroy(&resources->mutex);
	clean_all(conf, threads, resources);
	return (0);
}
