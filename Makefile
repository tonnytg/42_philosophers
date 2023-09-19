CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
FILES  = main.c 	\
		libs.c		\
		threads.c	\
		routine.c	\
		set_config.c

all:
	$(CC) $(CFLAGS) $(FILES) -lpthread -o philo

clean:
	rm philo