# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:00:32 by donghwik          #+#    #+#              #
#    Updated: 2021/12/18 17:05:59 by donghwik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= init.c main.c run.c status_check.c time_check.c util.c
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=philo

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%($(OBJS)) : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean fclean all re bonus

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all