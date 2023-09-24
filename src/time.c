# include "../headers/philosopher.h"
# include <sys/time.h>

int get_time(void)
{
	struct timeval		time;
	int					result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}
