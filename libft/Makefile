# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperronc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 12:07:00 by mperronc          #+#    #+#              #
#    Updated: 2016/02/16 13:14:20 by mperronc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Thanks to fdaudre- for his tutorial #

SRC_PATH = ./

SRC_NAME = ft_memset.c		\
		   ft_bzero.c		\
		   ft_memcpy.c		\
		   ft_memccpy.c		\
		   ft_memmove.c		\
		   ft_memchr.c		\
		   ft_memcmp.c		\
		   ft_strlen.c		\
		   ft_strdup.c		\
		   ft_strcpy.c		\
		   ft_strncpy.c		\
		   ft_strcat.c		\
		   ft_strncat.c		\
		   ft_strlcat.c		\
		   ft_strchr.c		\
		   ft_strrchr.c		\
		   ft_strstr.c		\
		   ft_strnstr.c		\
		   ft_strcmp.c		\
		   ft_strncmp.c		\
		   ft_atoi.c		\
		   ft_isalpha.c		\
		   ft_isdigit.c		\
		   ft_isalnum.c		\
		   ft_isascii.c		\
		   ft_isprint.c		\
		   ft_toupper.c		\
		   ft_tolower.c		\
		   ft_memalloc.c	\
		   ft_memdel.c		\
		   ft_strnew.c		\
		   ft_strdel.c		\
		   ft_strclr.c		\
		   ft_striter.c		\
		   ft_striteri.c	\
		   ft_strmap.c		\
		   ft_strmapi.c		\
		   ft_strequ.c		\
		   ft_strnequ.c		\
		   ft_strsub.c		\
		   ft_strjoin.c		\
		   ft_strtrim.c		\
		   ft_strsplit.c	\
		   ft_itoa.c		\
		   ft_putchar.c		\
		   ft_putstr.c		\
		   ft_putendl.c		\
		   ft_putnbr.c		\
		   ft_putchar_fd.c	\
		   ft_putstr_fd.c	\
		   ft_putendl_fd.c	\
		   ft_putnbr_fd.c	\
		   ft_lstnew.c		\
		   ft_lstdelone.c	\
		   ft_lstdel.c		\
		   ft_lstadd.c		\
		   ft_lstiter.c		\
		   ft_lstmap.c		\
		   ft_intlen.c		\
		   ft_islower.c		\
		   ft_isupper.c		\
		   ft_strrev.c		\
		   ft_strctrim.c	\
			get_next_line.c \
			ft_min2.c		\
			ft_max2.c

OBJ_PATH = ./obj/

INC_PATH = ./includes/

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME)

re:	fclean all
