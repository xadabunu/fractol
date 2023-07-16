# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 00:30:17 by xadabunu          #+#    #+#              #
#    Updated: 2023/07/16 15:27:37 by xadabunu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

LDFLAGS	=	-Llibft

LDLIBS	=	-lft

RM		=	rm -rf

#MLX		=	minilibx-linux/libmlx_Linux.a

MLX		=	minilibx_macos/libmlx.a

MLX_DIR	=	-Lminilibx_macos

LIB_DIR	=	minilibx_macos libft

LDFLAGS	=	${addprefix -L, ${LIB_DIR}}

LDLIBS	=	-lm -lmlx -lft -framework OpenGL -framework Appkit

LIBFT	=	${LIB_DIR}/libft.a

all		:	${NAME}

${MLX}	:
			${MAKE} -C minilibx_macos

${LIBFT}:
			${MAKE} -C libft

${NAME}	:	${OBJS} ${MLX} ${LIBFT}
			${CC} ${LDFLAGS} ${OBJS} ${LDLIBS} -o ${NAME}

clean	:
			${MAKE} clean -C ${LIB_DIR}
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${LIBFT}
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
