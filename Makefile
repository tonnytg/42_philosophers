CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) main.c libs.c threads.c -lpthread -o philo

clean:
	rm philo