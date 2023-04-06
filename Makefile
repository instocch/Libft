# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstocche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 13:36:10 by mstocche          #+#    #+#              #
#    Updated: 2023/04/06 13:36:16 by mstocche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS_DIR := ./
SRCS := ft_strlcpy.c ft_calloc.c ft_putnbr_fd.c ft_strdup.c ft_tolower.c ft_strlcat.c ft_isprint.c ft_isdigit.c ft_memchr.c ft_substr.c ft_putendl_fd.c ft_memcmp.c ft_strncmp.c ft_striteri.c ft_memset.c ft_putchar_fd.c ft_split.c ft_strnstr.c ft_bzero.c ft_atoi.c ft_isalpha.c ft_strjoin.c ft_memmove.c ft_isascii.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_isalnum.c ft_strmapi.c ft_strtrim.c ft_itoa.c ft_strchr.c ft_memcpy.c ft_putstr_fd.c
B_SRCS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
FLAGS := -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}


all: $(NAME)

%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS) 
	ar crs libft.a $(OBJS) 

bonus : ${B_OBJS} 
	ar crs libft.a $(B_OBJS)

clean:
	rm -f $(OBJS) ${B_OBJS} 

fclean: clean
	rm -f $(NAME)

re: fclean all
