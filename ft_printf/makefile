# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 07:01:38 by tpita-de          #+#    #+#              #
#    Updated: 2020/06/29 07:06:41 by tpita-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	char.c \
			decimal.c \
			decimal_paddings.c \
			ft_printf.c \
			hexadecimal.c \
			modifiers.c \
			percent_sing.c \
			pointer.c \
			string.c \
			unsigned.c \
			utils.c \

OBJS	:= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.
RM		= rm -f

all: ${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

%.o: libft/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS}
		make -C libft
		ar rc ${NAME} libft/*.o ${OBJS}

debug:
		$(CC) $(CFLAGS) -g $(SRCS) libft/ft_*.c -I libft

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} libft/*.o *.o

re:		fclean all
.PHONY: all clean fclean re
