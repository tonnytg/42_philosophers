CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
FILES  = main.c 	\
		libs/libs.c		\
		src/threads.c	\
		src/routine.c	\
		src/configuration.c	\
		src/simulation.c

all:
	$(CC) $(CFLAGS) $(FILES) -lpthread -o philo

clean:
	rm philo