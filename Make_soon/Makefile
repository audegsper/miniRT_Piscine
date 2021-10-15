# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 17:08:27 by hyson             #+#    #+#              #
#    Updated: 2021/10/16 00:02:47 by dohykim          ###   ########.fr        #
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
LIBDIR		=	../lib/ft_functions/
LIBNAME		=	libft.a
D_PARSE		=	./parse/
D_ERROR		=	./parse/error/
D_GET		=	./parse/get/
SRC_LIST	=	main.c						\
			$(D_PARSE)parse.c				\
			$(D_PARSE)identifier.c			\
			$(D_GET)ambient.c				\
			$(D_GET)camera.c				\
			$(D_GET)light.c					\
			$(D_GET)sphere.c				\
			$(D_GET)plane.c					\
			$(D_GET)cylinder.c				\
			$(D_ERROR)error.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

#------------------------------------------------------------------------------#
# T A R G E T
#------------------------------------------------------------------------------#

%.o			:	%.c
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(LIBFT) $(OBJ)
				@$(CC) $(LIBFT) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(OBJ)

$(LIBNAME):
			@$(MAKE) -C $(LIBDIR)
			@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)
#------------------------------------------------------------------------------#
# R U L E
#------------------------------------------------------------------------------#

.PHONY		: 	all
all			: 	$(NAME)

.PHONY		:	clean
clean		:
				@$(RM) $(OBJ)

.PHONY		:	fclean
fclean		: 	clean
				@$(RM) $(NAME)

.PHONY		:	re
re			:	fclean all
