/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:05:26 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 14:52:30 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack {
	int				num;
	int				order;
	struct s_stack	*next;
}		t_stack;

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
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
t_stack	*arg_check(int argc, char **argv);
t_stack	*create_list(int argc, char **argv, int j);
void	sort_small(t_stack **a, t_stack **b);
t_stack	*to_last(t_stack **lst);
int		is_max_min(t_stack **a, t_stack **b, int mm);
void	rot_high_top(t_stack **right);
void	rot_mid_top(t_stack **left, t_stack **right);
void	act_sort1(t_stack **a, t_stack **b);
int		ck_chunk(t_stack **a, int size, int chunk_cnt);
int		find_top(t_stack **a, int npch, int chunk_cnt);
int		find_bot(t_stack **a, int npch, int chunk_cnt);
void	rot_chunk_top(t_stack **a, int size, int chunk_cnt);
void	chunk_loop(t_stack **a, t_stack **b, int size, int chunk_cnt);

#endif
