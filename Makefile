# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaes <acaes@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 17:26:12 by acaes             #+#    #+#              #
#    Updated: 2024/12/03 18:06:28 by acaes            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = ./inc
SRCS = ./srcs
OBJS = ./objs

LIBFT = $(wildcard $(SRCS)/libft/*.c)
PRINTF = $(wildcard $(SRCS)/printf/*.c)
GNL = $(wildcard $(SRCS)/gnl/*.c)
SOURCE = $(LIBFT) $(PRINTF) $(GNL)

OBJET = $(SOURCE:$(SRCS)/%.c=$(OBJS)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC)
RM = @rm -rf
AR = @ar -rcs

all: $(NAME)

$(NAME): $(OBJET)
	$(AR) $(NAME) $(OBJET)

$(OBJS)/%.o: $(SRCS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
