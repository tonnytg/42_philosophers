CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) main.c -lpthread -o philo

clean:
	rm philo