CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
FILES  = main.c 	\
		libs/libs.c		\
		src/threads.c	\
		src/routine.c	\
		src/configuration.c	\
		src/simulation.c	\
		src/run_sleep.c	\
		src/run_eat.c	\
		src/run_think.c	\
		src/time.c \
		src/health.c

all:
	$(CC) $(CFLAGS) $(FILES) -lpthread -o philo

clean:
	rm philo