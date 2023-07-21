# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 10:43:02 by xadabunu          #+#    #+#              #
#    Updated: 2023/07/21 13:25:23 by xadabunu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

SRC		:=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_len.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_printf.c \
			ft_put_basic.c \
			ft_put_hexa.c \
			ft_putendl_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_utils.c

S_DIR	:=	srcs
B_DIR	:=	build
I_DIR	:=	include

CFLAGS	:=	-Wall -Wextra -Werror

SRCS	:=	${addprefix ${S_DIR}/,${SRC}}

OBJS	:=	${SRCS:%.c=${B_DIR}/%.o}

DEPS	:=	${OBJS:.o=.d}

CPPFLAGS:=	${addprefix -I, ${I_DIR}} -MMD -MP

RM		:=	rm -rf

all		:	${NAME}

${NAME}	:	${OBJS}
			${AR} rcs $@ ${OBJS}

${B_DIR}/%.o:	%.c
			mkdir -p $(dir $@)
			${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

clean	:
		${RM} ${B_DIR}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re

-include ${DEPS}
