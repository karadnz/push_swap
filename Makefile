# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 18:19:32 by mkaraden          #+#    #+#              #
#    Updated: 2023/02/01 11:30:30 by mkaraden         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#fclean clean bonus bak 
NAME            =   push_swap

SRC				=	init.c initutils.c sortBinary.c stackExtra.c sortBinaryUtils.c index.c libftutils.c \
main.c stack.c stackoperations.c sortExtra.c

OBJ = $(SRC:.c=.o)

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

bonus : $(SERVER_B) $(CLIENT_B)


re : fclean all

.PHONY: all fclean re bonus