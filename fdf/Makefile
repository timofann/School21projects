CC		=	cc

NAME	=	fdf

HEADERS	=	fdf.h			fdf_put_error.h		fdf_parse_model.h	\
			fdf_colors.h	fdf_keycodes.h		fdf_put_message.h

SRC 	=	fill_map.c              		get_fd.c                \
			get_next_color.c        		get_next_line_utils.c	\
			long_type_is_needed.c   		parse_model.c			\
			put_message.c					get_default_altitude.c	\
			get_next_altitude.c				get_next_line.c			\
			get_sign.c             			main.c					\
			put_error.c             		set_empty_map.c			\
			str_len.c						set_new_window.c		\
			put_pixel.c						draw_state.c			\
			get_default_zoom.c				rotate_model.c			\
			put_edge.c						put_axes.c				\
			set_hooks_for_drawing.c			set_new_image.c			\
			set_default_state.c				clear_window.c			\
			apply_perversion.c				apply_centering.c		\
			init_workspace.c				put_edges_isometric.c	\
			put_edges_perspective.c			put_info.c				\
			float_to_string.c

OBJ		=	$(SRC:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all