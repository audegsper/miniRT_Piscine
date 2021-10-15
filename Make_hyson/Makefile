# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 17:08:27 by hyson             #+#    #+#              #
#    Updated: 2021/10/15 18:31:56 by hyson            ###   ########.fr        #
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
D_FT		=	../lib/ft_functions/
D_PARSE		=	./parse/
D_ERROR		=	./parse/error/
SRC_LIST	=	main.c						\
			$(D_PARSE)parse.c				\
			$(D_PARSE)identifier.c			\
			$(D_FT)dalloc.c					\
			$(D_FT)free_ptr.c				\
			$(D_FT)ft_strdup.c				\
			$(D_FT)ft_strlcpy.c				\
			$(D_FT)ft_strlen.c				\
			$(D_FT)get_next_line.c			\
			$(D_FT)ft_strncmp.c				\
			$(D_ERROR)error.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

#------------------------------------------------------------------------------#
# T A R G E T
#------------------------------------------------------------------------------#

%.o			:	%.c
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(OBJ)

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
