# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 00:30:17 by xadabunu          #+#    #+#              #
#    Updated: 2023/10/19 14:01:24 by xadabunu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c \
			map.c \
			check_command.c \
			fractals.c \
			get_colors.c \
			hookers.c \
			images.c \
			setup.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror \
			-O3

RM		=	rm -rf

MLX		=	minilibx/libmlx.a

LIB_DIR	=	minilibx libft

LDFLAGS	=	${addprefix -L, ${LIB_DIR}}

LDLIBS	=	-lm -lmlx -lft -framework OpenGL -framework Appkit
#LDLIBS	=	-lm -lft -lmlx -lXext -lX11

LIBFT	=	libft/libft.a

all		:	${NAME}

${MLX}	:
			${MAKE} -C minilibx

${LIBFT}:
			${MAKE} -C libft

${NAME}	:	${OBJS} ${MLX} ${LIBFT}
			${CC} ${LDFLAGS} ${OBJS} ${LDLIBS} -o ${NAME}

clean	:
			${MAKE} clean -C libft
			${MAKE} clean -C minilibx
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${MLX}
			${RM} ${LIBFT}
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
