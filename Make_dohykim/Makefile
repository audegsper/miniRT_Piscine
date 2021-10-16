# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 17:08:27 by hyson             #+#    #+#              #
#    Updated: 2021/10/16 17:00:56 by dohykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#------------------------------------------------------------------------------#
# I N S T  V A R
#------------------------------------------------------------------------------#

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
CDEBUG		= 	-fsanitize=address -g
RM			= 	rm -f

#------------------------------------------------------------------------------#
# F I L E
#------------------------------------------------------------------------------#

NAME		=	miniRT
HEADER		=	./includes/
FOLDER		=	./srcs/
D_PARSE		=	./parse/
D_ERROR		=	./parse/error/
D_GET		=	./parse/get/
D_FT		=	./lib/ft_functions/
FTLIB		=	libft.a
SRC_LIST	=	main.c						\
				dohykim.c					\

SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
LIBFT		=	$(addprefix $(D_FT), $(FTLIB))
OBJ			=	$(SRC:.c=.o)

#------------------------------------------------------------------------------#
# T A R G E T
#------------------------------------------------------------------------------#

%.o			:	%.c
				$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(LIBFT) $(OBJ)
				$(CC) $(LIBFT) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(OBJ)

$(LIBFT):
			$(MAKE) -C $(D_FT) all

#------------------------------------------------------------------------------#
# R U L E
#------------------------------------------------------------------------------#

.PHONY		: 	all
all			: 	$(NAME)

.PHONY		:	clean
clean		:
				$(RM) $(OBJ)
				$(MAKE) -C $(D_FT) clean

.PHONY		:	fclean
fclean		: 	clean
				$(RM) $(NAME)
				$(MAKE) -C $(D_FT) fclean

.PHONY		:	re
re			:	fclean all
