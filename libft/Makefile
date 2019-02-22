# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:54:51 by emamenko          #+#    #+#              #
#    Updated: 2019/02/20 22:54:16 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

NAME	=	libft.a
SOURCES	=	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
			ft_strncat.c ft_strlcat.c ft_strstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_strchr.c ft_strnstr.c ft_strrchr.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c \
			\
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			\
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c \
			\
			ft_word_count.c ft_extract_word.c ft_strshrink.c \
			ft_flatten_charr.c ft_flatten_intarr.c ft_flatten_tlist.c \
			ft_strchri.c ft_strsetdel.c ft_freeret.c

OBJECTS	=	$(SOURCES:.c=.o)

all:		$(NAME)

$(NAME):
			gcc -Wall -Wextra -Werror -I. -c $(SOURCES)
			ar rcs $(NAME) $(OBJECTS)

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all

reclean:	re; make clean
