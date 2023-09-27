CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -lpthread
SOURCES = main.c libs/libs.c src/threads.c src/routine.c src/configuration.c \
          src/simulation.c src/run_sleep.c src/run_eat.c src/run_think.c \
          src/time.c src/health.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = philo

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all fclean clean re