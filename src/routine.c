#include "../headers/philosopher.h"

void *routine()
{
	int						i;

	i = 0;
	while (i < 10)
	{
		printf("teste\n");
		usleep(1000 * 1000);
		i++;
	}
	return (NULL);
}
