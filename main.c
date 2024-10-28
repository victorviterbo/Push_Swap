/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 14:20:10 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	init(t_list **stack_a, t_list **stack_b);
void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size);
void	merge(t_list **stack_a, t_list **stack_b);
void	insert(t_list **stack_a, t_list **stack_b);
void	rotate_i(t_list **stack_a, size_t n);
void	sort(t_list **stack_a, t_list **stack_b, size_t n);

int	main(int argc, char *argv[])
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;
	int		*tmp;
	t_list	*new_node;

	i = 1;
	stack_a = ft_calloc(1, sizeof(t_list *));
	stack_b = ft_calloc(1, sizeof(t_list *));
	while (i < argc)
	{
		tmp = ft_calloc(1, sizeof(int));
		*tmp = ft_atoi(argv[i]);
		new_node = ft_lstnew(tmp);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	print_list(stack_a, stack_b);
	init(stack_a, stack_b);
	print_list(stack_a, stack_b);
	sort(stack_a, stack_b, 4);
	return (1);
}


void	init(t_list **stack_a, t_list **stack_b)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_lstsize(*stack_a);
	while (i < len)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
		push_bloc(stack_a, stack_b, 2);
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
		merge(stack_a, stack_b);
		push_bloc(stack_b, stack_a, 4);
		rotate_i(stack_a, 4);
		i += 4;
	}
	return ;
}

void	push_bloc(t_list **stack_a, t_list **stack_b, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		pb(stack_a, stack_b);
		i++;
	}
	return ;
}

void	merge(t_list **stack_a, t_list **stack_b)
{
	size_t	len;
	size_t	i;

	len = ft_lstsize(*stack_b);
	i = 0;
	while (i < len)
	{
		insert(stack_a, stack_b);
		i++;
	}
	return ;
}

void	insert(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(*stack_b);
	print_list(stack_a, stack_b);
	while (*(int *)(*stack_a)->content > *(int *)(*stack_b)->content)
	{
		if (*(int *)(*stack_b)->content > *(int *)(*stack_b)->next->content)
		{
			rb(stack_b);
			break ;
		}
		rb(stack_b);
		i++;
	}
	pb(stack_a, stack_b);
	print_list(stack_a, stack_b);
	if (2 * i > len)
	{
		while (i < len + 1)
		{
			rb(stack_b);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rrb(stack_b);
			i--;
		}
	}
	return ;
}

void	rotate_i(t_list **stack_a, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ra(stack_a);
		i++;
	}
	return ;
}

void	sort(t_list **stack_a, t_list **stack_b, size_t n)
{
	printf("coucou running with n = %zu\n", n);
	if ((int)n > ft_lstsize(*stack_a))
		return ;
	push_bloc(stack_a, stack_b, n);
	merge(stack_a, stack_b);
	push_bloc(stack_b, stack_a, 2 * n);
	return (sort(stack_a, stack_b, 2 * n));
}
