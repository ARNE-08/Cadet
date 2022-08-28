# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wthanata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 10:58:18 by wthanata          #+#    #+#              #
#    Updated: 2022/08/27 19:06:38 by wthanata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

BONUS		=	checker

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	srcs/main.c srcs/arg_check.c srcs/op_swap.c srcs/op_rot.c srcs/op_rev_rot.c srcs/op_push.c srcs/create_list.c srcs/sort_small.c srcs/sort_big1.c srcs/sort_big2.c srcs/sort_big3.c

OBJS		=	${SRCS:.c=.o}

B_SRCS		=	b_srcs/check_ps.c b_srcs/arg_check.c b_srcs/op_swap.c b_srcs/op_rot.c b_srcs/op_rev_rot.c b_srcs/op_push_ck.c b_srcs/create_list.c

B_OBJS		=	${B_SRCS:.c=.o}

HEAD		=	./includes

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

RM		=	rm -f

.c.o:
		gcc ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

all:		${LIBFT} ${NAME}

bonus:		${LIBFT} ${B_OBJS}
		gcc ${CFLAGS} -L ${LIBFT_DIR} -lft ${B_OBJS} -o ${BONUS}

${NAME}:	${OBJS}
		gcc ${CFLAGS} -L ${LIBFT_DIR} -lft ${OBJS} -o ${NAME}

${LIBFT}:
		make -sC ${LIBFT_DIR}

clean:
		make clean -sC ${LIBFT_DIR}
		${RM} ${OBJS}
		${RM} ${B_OBJS}

fclean:		clean
		make fclean -sC ${LIBFT_DIR}
		${RM} ${NAME}
		${RM} ${BONUS}

re:		fclean all

.PHONY:		all bonus clean fclean re
