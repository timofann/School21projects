NAME		=	libftprintf.a

MAIN		=	main.c

AOUT		=	a.out

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_printf.c			ft_printf_flags.c	\
				ft_printf_check1.c	ft_printf_check2.c	\
				ft_printf_print1.c	ft_printf_print2.c	\
				ft_printf_utils1.c	ft_printf_utils2.c

OBJS		=	$(SRCS:.c=.o) 

HEADER		=	ft_printf.h

.PHONY	:	all bonus re clean fclean main dedelmir

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $@ $?

%.o	:	%.c $(HEADER)
	$(CC) -c $(CFLAGS) -I$(HEADER) $< -o $@

main	:	$(NAME)
	gcc $(MAIN) $(NAME)
	./$(AOUT)

bonus	:	all

clean	:
	rm -f $(OBJS) $(AOUT)

fclean	:
	rm -f $(OBJS) $(NAME) $(AOUT)

re: fclean all

F_GREEN		= \033[32m
F_NONE		= \033[30m

dedelmir :
	@echo "$(F_NONE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀$(F_GREEN)⣆⣀⡔⣀$(F_NONE)"
	@echo "$(F_GREEN)⣤⣀⣀$(F_NONE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⣀⣤⡶⠚⢋⡉⠁⠇⠸⠉⠋⠓⠦⣤⣀$(F_NONE)"
	@echo "$(F_GREEN)⠹⣿⣽⣿⣿⣷⣶⣶⣦⣤⣤⣴⣶⡾⠿⣦⣾⠟⠁⠄⠘⠉⠁⠄⣀⣀⡀⠘⠛⠓⠈⠙⢷⣤⡶⢶⣶⣤⣀⣀⠄⠄⠄⣀⣀⣠⣤⣴⢶⡇$(F_NONE)"
	@echo "⠄$(F_GREEN)⠘⣷⣍⠙⠛⠿⠿⣿⣭⣿⣯⣭⡄⠄⣿⠃⠠⢞⣛⣛⠷⣦⠘⠉⠉⠙⢀⡴⠚⠛⠶⠄⢻⡇⠄⠙⠛⠿⠿⠿⠿⢿⣟⣛⣯⡽⣾⡟$(F_NONE)"
	@echo "⠄⠄$(F_GREEN)⠈⢿⣷⣄⠄⠄⠄⠄⠄⠄⢸⣇⠄⠇⢠⣾⣟⣻⣿⣷⣌⠄⠄⠄⠄⢨⣶⢻⣿⣿⣦⡀⠇⢀⡿⠛⠻⠟⠛⠛⠛⠋⠉⣡⣾⠏$(F_NONE)"
	@echo "⠄⠄⠄$(F_GREEN)⠈⠻⣿⣷⣄⡀⠄⠄⠄⠘⣿⡆⢠⡿⣿⣿⣿⣿⣿⣿⡄⠄⠄⢠⣿⣿⣿⣿⣿⣿⣷⢀⣾⡇⠄⠄⠄⠄⠄⠄⣠⣾⡿⠁$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄$(F_GREEN)⠈⠻⣿⣿⣦⣀⠄⠄⠹⣧⠄⠙⠛⠻⠿⠿⠿⠛⠑⢏⡉⠊⠛⠿⠿⠿⠟⠛⠁⣸⡟⠄⠄⠄⠄⣠⣴⣿⡿⠋$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⠈⠙⠻⠿⣿⣶⣤⣽⣆⠄⠄⠄⠄⠄⢲⣦⣴⣶⣶⣦⣤⡶⠄⠄⠄⠄⣠⣿⣤⣤⣴⣶⡿⠿⠛⠁$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⣴⣏⠳⣤⣀⣀⣀⣀⣙⣳⠶⠶⢟⣋⡀⢀⣀⣤⡶⠋⢹$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⣸⠛⢻⣄⠈⠙⠛⠿⠿⠿⠿⠟⠻⡟⠛⠛⠛⠛⠉⢀⣠⡟⢳⡄$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⣸⣧⣄⠹⢿⣦⣤⣀⣀⣀⣀⣀⣠⣧⣤⣤⣤⣴⣾⡿⠋⠄⣀⡇$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⡼⠓⣄⢹⣧⠄⠈⠉⠉⠉⠉⠉⠁⠘⡇⠄⠄⠄⠄⠄⠄⢠⡿⠋⢣$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⢳⣤⠛⣶⡿⠄⠄⠄⠄⠄⠄⠄⠄⠄⣷⠄⠄⠄⠄⠄⠄⣿⡇⣴⠉⢳$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⢀⣿⠙⠚⠋⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⡄⠄⠄⠄⠄⠄⠙⢧⣨⣶⠏$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⢠⣾⠟⢷⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⡇⠄⠄⠄⠄⠄⠄⠄⣁⣼⣷⣄$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⣾⡿⠄⠄⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⡇⠄⠄⠄⠄⠄⠄⠄⠋⠁⠘⣿⡄$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⣿⣧⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢹⣷$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⠘⣿⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣟⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣾⠟$(F_NONE)"
	@echo "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(F_GREEN)⠉⠛⠛⠛⠛⠋⠉⠉⠉⠉⠉⠉⠉⠁⠉⠛⠛⠛⠒⠒⠒⠒⠛⠉⠉⠉⠁$(F_NONE)"