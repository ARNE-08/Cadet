/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:24:42 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 19:11:25 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack {
	int				num;
	int				order;
	struct s_stack	*next;
}		t_stack;

void	exit_error(int error);
int		count_list(t_stack **lst);
void	swap_a(t_stack **lst, int c);
void	swap_b(t_stack **lst, int c);
void	swap_ab(t_stack **a, t_stack **b, int c);
void	rot_a(t_stack **lst, int c);
void	rot_b(t_stack **lst, int c);
void	rot_ab(t_stack **a, t_stack **b, int c);
void	rev_rot_a(t_stack **lst, int c);
void	rev_rot_b(t_stack **lst, int c);
void	rev_rot_ab(t_stack **a, t_stack **b, int c);
void	push_a(t_stack **a, t_stack **b, int c);
void	push_b(t_stack **a, t_stack **b, int c);
t_stack	*arg_check(int argc, char **argv);
t_stack	*create_list(int argc, char **argv, int j);

#endif
