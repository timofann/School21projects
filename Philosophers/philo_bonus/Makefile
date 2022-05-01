CC		=	cc

CFLAGS	= -Wall -Werror -Wextra

NAME	=	philo_bonus

HEADERS	=	philo_bonus.h philo_bonus_error.h

SRC 	=	set_current_time.c		set_time_interval.c			\
			set_arguments.c			set_general.c				\
			start_dinner.c			msleep.c					\
			mprintf.c				kill_philosophers.c			\
			init_sighandler.c		put_error.c					\
			philo_scenario.c		main.c						\
			philo_eat.c				philo_think.c				\
			philo_sleep.c			life_monitoring.c

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