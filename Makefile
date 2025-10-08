# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankozako <ankozako@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 11:38:16 by ankozako          #+#    #+#              #
#    Updated: 2025/10/06 11:38:18 by ankozako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 		= philo
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g -fsanitize=thread

SRC = src/utils.c src/main.c src/args.c
			  
OBJ	= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all