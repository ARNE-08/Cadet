/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wthanata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:05:08 by wthanata          #+#    #+#             */
/*   Updated: 2022/08/27 17:54:12 by wthanata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

int	is_sort(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr->next)
	{
		if (ptr->order > ptr->next->order)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	ck_op(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_a(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		swap_ab(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(a, b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		rot_a(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rot_b(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rot_ab(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rev_rot_a(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rev_rot_b(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rev_rot_ab(a, b, 0);
	else
		exit_error(1);
}

void	get_command_execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ck_op(a, b, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = arg_check(argc, argv);
	b = NULL;
	get_command_execute(&a, &b);
	if (is_sort(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(a);
	free_list(b);
	return (0);
}
