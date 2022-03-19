# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:35:30 by dcorenti          #+#    #+#              #
#    Updated: 2022/03/18 18:40:27 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CO_GREEN		= 	\033[1;32m
CO_RED			= 	\033[1;31m
CO_DEFAULT		= 	\033[0m

NAME 			= 	philo

SRCS			= 	main.c \
					errors.c \
					utils.c \
					check_args.c \
		
CC 				= gcc

FLAGS 			= -Wall -Wextra -Werror

OBJS 			= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS)-o $(NAME)
	clear
	@printf "${CO_GREEN}${NAME} successfully build!${CO_DEFAULT}\n"

all : $(NAME)

clean :
	rm -rf $(OBJS)
	clear
	@printf "${CO_RED}${SURPL_O} successfully deleted!${CO_DEFAULT}\n"

fclean : clean
	rm -rf $(NAME)
	clear
	@printf "${CO_RED}${SURPL_O}${NAME} successfully deleted!${CO_DEFAULT}\n"

re : fclean all

.PHONY: all clean fclean re