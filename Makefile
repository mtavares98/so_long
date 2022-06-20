# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 22:22:28 by mtavares          #+#    #+#              #
#    Updated: 2022/06/20 22:22:16 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))

SRCS_DIR	=	srcs

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs

LIBFT		=	libs/libft/libft.a

PRINTF		=	libs/printf_fd/libprintf_fd.a

MINILIBX	=	libs/minilibx-linux/libmlx.a

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

RM			=	rm -rf

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(LIBFT) $(PRINTF) $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MINILIBX) -L/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
		@make -C libs/libft

$(PRINTF):
		@make -C libs/printf_fd

clean:
		$(RM) $(OBJS_DIR)
		make clean -C libs/libft
		make clean -C libs/printf_fd

fclean:		clean
		$(RM) $(NAME)
		make fclean -C libs/libft
		make fclean -C libs/printf_fd

re:			fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re 