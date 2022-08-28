# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wthanata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 21:46:46 by wthanata          #+#    #+#              #
#    Updated: 2022/08/27 16:47:34 by wthanata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_printf_bonus.c ft_printf_case_bonus.c ft_printf_utils_bonus.c ft_printf_utils2_bonus.c ft_strcmp.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

HEAD	=	libft.h

RM	=	rm -f

.c.o:
		@gcc ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@ar rc ${NAME} ${OBJS}
		@ranlib ${NAME}

all:		${NAME}

clean:
		@${RM} ${OBJS} ${B_OBJS}

fclean:		clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
