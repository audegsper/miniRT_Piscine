# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 17:08:27 by hyson             #+#    #+#              #
#    Updated: 2021/10/25 22:33:25 by dohykim          ###   ########.fr        #
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
D_UTILS		=	./utils/
D_TRACE		=	./trace/
D_PARSE		=	./parse/
D_ERROR		=	./parse/error/
D_GET		=	./parse/get/
D_FT		=	./lib/ft_functions/
FTLIB		=	libft.a
MLXDIR		=	./lib/mlx/
MLXNAME		=	libmlx.a
LIB_FLAG	=	-L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit
SRC_LIST	=	main.c						\
			$(D_UTILS)vec_utils1.c			\
			$(D_UTILS)vec_utils2.c			\
			$(D_UTILS)vec_utils3.c			\
			$(D_UTILS)struct_utils.c		\
			$(D_TRACE)object_trace.c		\
			$(D_TRACE)ray_trace.c			\
			$(D_TRACE)phong_light.c			\
			$(D_PARSE)parse.c				\
			$(D_PARSE)identifier.c			\
			$(D_PARSE)check_double.c		\
			$(D_PARSE)check_int.c			\
			$(D_PARSE)valid.c				\
			$(D_GET)ambient.c				\
			$(D_GET)camera.c				\
			$(D_GET)light.c					\
			$(D_GET)sphere.c				\
			$(D_GET)plane.c					\
			$(D_GET)cylinder.c				\
			$(D_ERROR)error.c				\
			$(D_TRACE)cylinder_trace.c		\
			$(D_TRACE)plane_trace.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
LIBFT		=	$(addprefix $(D_FT), $(FTLIB))
OBJ			=	$(SRC:.c=.o)

#------------------------------------------------------------------------------#
# T A R G E T
#------------------------------------------------------------------------------#

%.o			:	%.c
				$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(LIBFT) $(OBJ)
				$(CC) $(LIBFT) $(CFLAGS) $(CDEBUG) $(LIB_FLAG) -I $(HEADER) -o $(NAME) $(OBJ)

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
