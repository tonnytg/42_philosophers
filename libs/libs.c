#include "../headers/philosopher.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	*ft_memset(void *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (size > i)
	{
		((unsigned char *)s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if ((nmemb * size) / size != nmemb)
		return (NULL);
	mem = malloc((nmemb * size));
	if (!mem)
		return (NULL);
	ft_memset(mem, '\0', (nmemb * size));
	return (mem);
}
