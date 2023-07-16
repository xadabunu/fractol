# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 00:30:17 by xadabunu          #+#    #+#              #
#    Updated: 2023/07/16 00:21:36 by xadabunu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

LDFLAGS	=	-Llibft

LDLIBS	=	-lft

RM		=	rm -rf

MLX		=	minilibx-linux/libmlx_Linux.a

MLX_DIR	=	-Lminilibx-linux

#LIB_DIR	=	libft

#LIBFT	=	${LIB_DIR}/libft.a

all		:	${NAME}

${MLX}	:
			${MAKE} -C minilibx-linux

${NAME}	:	${OBJS} ${LIBFT} ${MLX}
			${CC} -lm ${MLX_DIR} -lmlx ${OBJS} -o ${NAME}

#${LIBFT}:
#			${MAKE} -C ${LIB_DIR}

clean	:
#			${MAKE} clean -C ${LIB_DIR}
			${RM} ${OBJS}

fclean	:	clean
#			${RM} ${LIBFT}
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
