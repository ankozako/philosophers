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
CFLAGS 		= -Wall -Wextra -Werror
INCLUDE		= -I inc

SRC = 	src/actions_forks.c src/actions.c src/arguments.c src/cleanup.c \
		src/init.c src/main.c src/memory.c src/mutex.c src/sim.c \
		src/threads.c src/utils.c src/meal_mutex.c
			  
OBJ	= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all