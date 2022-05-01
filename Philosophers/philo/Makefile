CC		=	cc

CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread

NAME	=	philo

HEADERS	=	philo.h philo_error.h

SRC 	=	set_current_time.c		set_time_interval.c	\
			set_arguments.c			error.c				\
			set_general.c			set_personal.c		\
			philo_scenario.c		start_dinner.c		\
			philo_eat.c				philo_sleep.c		\
			philo_think.c			main.c				\
			msleep.c				mprintf.c			\
			check_alive.c			life_monitoring.c

OBJ		=	$(SRC:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all