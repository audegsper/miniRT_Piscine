# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 23:35:42 by dohykim           #+#    #+#              #
#    Updated: 2021/10/16 10:37:18 by dohykim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	dalloc.c free_ptr.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
			ft_strncmp.c get_next_line.c is_blank.c
OBJS	= $(SRCS:.c=.o)
HEADER	=	../../includes/
NAME	= libft.a
GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror -std=c99
RM		= rm -f

.c.o:
			$(GCC) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re .c.o
