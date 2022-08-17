# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 22:22:28 by mtavares          #+#    #+#              #
#    Updated: 2022/08/17 22:50:41 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(SRCS_DIR)/check_map.c \
				$(SRCS_DIR)/create_window.c \
				$(SRCS_DIR)/exit_free.c \
				$(SRCS_DIR)/get_next_line.c \
				$(SRCS_DIR)/get_next_line_utils.c \
				$(SRCS_DIR)/hooks.c \
				$(SRCS_DIR)/init_values.c \
				$(SRCS_DIR)/load_imgs.c \
				$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/map_to_str.c \
				$(SRCS_DIR)/move_player.c \
				$(SRCS_DIR)/algorithm.c \

SRCS_DIR	=	srcs

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs

LIBFT		=	libs/libft/libft.a

PRINTF		=	libs/printf_fd/libprintf_fd.a

MLX			=	mlx_linux/libmlx_Linux.a

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g# -fsanitize=address

RM			=	rm -rf

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(LIBFT) $(PRINTF) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
		make -C libs/libft

$(PRINTF):
		make -C libs/printf_fd

$(MLX):
		make -C mlx_linux

clean:
		$(RM) $(OBJS_DIR)
		make clean -C libs/libft
		make clean -C libs/printf_fd
		make clean -C mlx_linux

fclean:		clean
		$(RM) $(NAME)
		make fclean -C libs/libft
		make fclean -C libs/printf_fd

re:			fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re
