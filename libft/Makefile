# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpita-de <tpita-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 05:56:57 by tomasrpita        #+#    #+#              #
#    Updated: 2020/08/29 14:05:27 by tpita-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=ft_atoi.c  ft_isascii.c  ft_memcmp.c   ft_strdup.c  ft_strnstr.c \
	ft_bzero.c    ft_isdigit.c  ft_memcpy.c   ft_strlcat.c  ft_strrchr.c \
	ft_calloc.c   ft_isprint.c  ft_memmove.c  ft_strlcpy.c  ft_tolower.c \
	ft_isalnum.c  ft_memccpy.c  ft_memset.c   ft_strlen.c   ft_toupper.c \
	ft_isalpha.c  ft_memchr.c   ft_strchr.c   ft_strncmp.c  ft_substr.c \
	ft_strjoin.c  ft_strtrim.c  ft_split.c    ft_itoa.c		ft_strmapi.c \
	ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c

OBJETCS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
INCLUDES = libft.h

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror  -c $(SRCS) $(INCLUDES)
	@ar -rc $(NAME) $(OBJETCS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJETCS)

fclean: clean
	@/bin/rm -f $(NAME) $(OBJS_BONUS)

re: fclean all

bonus: all $(OBJS_BONUS)
	@gcc -Wall -Wextra -Werror  -c $(SRCS_BONUS) $(INCLUDES)
	@ar rc $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)

.PHONY: all clean fclean re
