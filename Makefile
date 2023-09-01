CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) main.c libs.c -lpthread -o philo

clean:
	rm philo