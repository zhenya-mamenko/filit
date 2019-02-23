# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 11:09:55 by emamenko          #+#    #+#              #
#    Updated: 2019/02/22 13:12:26 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

LIBFT_PATH	=	libft/

NAME		=	fillit
FLAGS		=	-Wall -Werror -Wextra -o $(NAME) -lft -L$(LIBFT_PATH) -I$(LIBFT_PATH)
SOURCES		=	fillit.c input_output.c functions.c \
				get_next_line.c

all:			$(NAME)

$(NAME):
				make -C $(LIBFT_PATH)
				gcc $(FLAGS) $(SOURCES)

clean:
				make -C $(LIBFT_PATH) clean

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				rm -f $(NAME)

re:				fclean all