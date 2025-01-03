/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:12 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/21 21:47:44 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int argc, char *argv[]);
void	reinsert(t_list **stack_a, t_list **stack_b);
int		compute_cost(t_list **stack_a, t_list **stack_b, int b_value, int pos);
void	rotate_ab(t_list **stack_a, t_list **stack_b,
			int b_value, int best_i);
void	push_on_b(t_list **stack_a, t_list **stack_b);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = parse_input(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	exit_gracefully(stack_a, stack_b, INIT_PTR);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) <= 5)
		minisort(stack_a, stack_b);
	push_on_b(stack_a, stack_b);
	while (*stack_b)
		reinsert(stack_a, stack_b);
	goto_val(stack_a, 'a', ft_lstmini(stack_a), false);
	if (minichecker(stack_a, stack_b))
		exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	exit_gracefully(NULL, NULL, EXIT_SUCCESS);
	return (0);
}

void	reinsert(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		best_i;
	int		best_b_value;
	int		min_c;
	t_list	*current;

	min_c = ft_abs(compute_cost(stack_a, stack_b, (*stack_b)->i, 0));
	current = (*stack_b)->next;
	i = 1;
	best_i = 0;
	best_b_value = (*stack_b)->i;
	while (current)
	{
		if (ft_abs(compute_cost(stack_a, stack_b, current->i, i)) < min_c)
		{
			best_i = i;
			min_c = ft_abs(compute_cost(stack_a, stack_b, current->i, i));
			best_b_value = current->i;
		}
		current = current->next;
		i++;
	}
	rotate_ab(stack_a, stack_b, best_b_value, best_i);
	pa(stack_a, stack_b);
	return ;
}

int	compute_cost(t_list **stack_a, t_list **stack_b, int b_value, int pos)
{
	int	forward;
	int	backward;
	int	zigzag_forward;
	int	zigzag_backward;
	int	min;

	min = goto_val(stack_a, 'a', b_value, true);
	min %= ft_lstsize(*stack_a);
	forward = ft_max(min, pos);
	backward = ft_max(ft_lstsize(*stack_a) - min, ft_lstsize(*stack_b) - pos);
	zigzag_forward = pos + (ft_lstsize(*stack_a) - min);
	zigzag_backward = (ft_lstsize(*stack_b) - pos) + min;
	min = ft_min(ft_min(forward, backward),
			ft_min(zigzag_forward, zigzag_backward));
	if (min == forward || min == zigzag_forward)
		return (min);
	else if (min == backward || min == zigzag_backward)
		return (-min);
	else
		exit_gracefully(NULL, NULL, EXIT_FAILURE);
	return (0);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b,
		int b_value, int best_i)
{
	int		i;
	bool	rev;

	i = 0;
	rev = compute_cost(stack_a, stack_b, b_value, best_i) < 0;
	if (rev == false && 2 * goto_val(stack_a, 'a', b_value, true)
		<= ft_lstsize(*stack_a))
	{
		i = ft_min(best_i, goto_val(stack_a, 'a', b_value, true));
		rotate_i(stack_a, stack_b, i, 'r');
		best_i -= i;
	}
	else if (rev == true && 2 * goto_val(stack_a, 'a', b_value, true)
		>= ft_lstsize(*stack_a))
	{
		i = ft_min(ft_lstsize(*stack_b) - best_i,
				ft_lstsize(*stack_a) - goto_val(stack_a, 'a', b_value, true));
		revrotate_i(stack_a, stack_b, i, 'r');
		best_i = (best_i + i) % ft_lstsize(*stack_b);
	}
	rotate_i(stack_b, NULL, best_i, 'b');
	goto_val(stack_a, 'a', b_value, false);
	return ;
}

void	push_on_b(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	*to_keep;
	int	size_a;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	to_keep = get_lis(stack_a);
	while (i < size_a)
	{
		if (to_keep[i] == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	free(to_keep);
	return ;
}
