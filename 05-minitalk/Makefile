# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 14:16:51 by fbingol           #+#    #+#              #
#    Updated: 2022/08/24 14:19:22 by fbingol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SRCLIENT =   client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER = $(SRCSERVER:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/libftprintf.a 

all: $(NAME)

$(NAME): $(OBJSERVER) $(OBJSCLIENT)
	@make -C ./ft_printf
	@gcc -o server $(SRCSERVER) $(CFLAGS) $(LIB)
	@gcc -o client $(SRCLIENT) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT)
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f server client
	rm -f ./ft_printf/*.o ./ft_printf/*.a

re: fclean all

.PHONY: all clean fclean re