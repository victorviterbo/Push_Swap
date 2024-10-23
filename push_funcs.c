/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:45:15 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/23 17:00:32 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_node_a;
	t_list	*next_node_b;

	if (!*stack_b)
		return ;
	if (!*stack_a)
		next_node_a = NULL;
	else
		next_node_a = *stack_a;
	*stack_a = *stack_b;
	next_node_b = (*stack_b)->next;
	(*stack_a)->next = next_node_a;
	*stack_b = next_node_b;
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	pa(stack_b, stack_a);
}
