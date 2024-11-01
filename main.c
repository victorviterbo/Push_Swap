/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:24:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/01 18:00:01 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int		main(int argc, char *argv[]);
char	*init(t_list **stack_a);
char	*merge(t_list **stack_a, t_list **stack_b);
char	*insert(t_list **stack_a, t_list **stack_b);
char	*sort(t_list **stack_a, t_list **stack_b, size_t n);

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*instructions;

	instructions = ft_calloc(1, 1);
	stack_a = parse_input(argc, argv);
	if (!stack_a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_b = ft_calloc(1, sizeof(t_list *));
	printf("1\n");
	print_list(stack_a, stack_b);
	instructions = ft_strjoin_ip(instructions, init(stack_a), 1);
	printf("2\n");
	print_list(stack_a, stack_b);
	instructions = ft_strjoin_ip(instructions, sort(stack_a, stack_b, 2), 1);
	printf("3\n");
	print_list(stack_a, stack_b);
	instructions = ft_strjoin_ip(instructions, reset(stack_a, 'a'), 1);
	printf("4\n");
	print_list(stack_a, stack_b);
	instructions = simplify(instructions, ft_strlen(instructions) + 1);
	printf("5\n");
	//write(1, instructions, ft_strlen(instructions));
	print_list(stack_a, stack_b);
	return (1);
}

char	*init(t_list **stack_a)
{
	size_t	i;
	size_t	len;
	char	*ret;

	ret = ft_calloc(1, 1);
	if (!ret)
		return (NULL);
	len = ft_lstsize(*stack_a);
	i = len % 2;
	while (i < len)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			ret = ft_strjoin_ip(ret, sa(stack_a), 1);
		ret = ft_strjoin_ip(ret, rotate_i(stack_a, 2), 1);
		i += 2;
	}
	ret = ft_strjoin_ip(ret, rotate_i(stack_a, len % 2), 1);
	return (ret);
}

char	*merge(t_list **stack_a, t_list **stack_b)
{
	size_t	len;
	size_t	i;
	char	*ret;

	ret = ft_calloc(1, 1);
	len = (size_t)ft_lstsize(*stack_b);
	if (len > (size_t)ft_lstsize(*stack_a))
		len = (size_t)ft_lstsize(*stack_a);
	i = 0;
	while (i < len)
	{
		ret = ft_strjoin_ip(ret, insert(stack_a, stack_b), 1);
		i++;
	}
	ret = ft_strjoin_ip(ret, reset(stack_b, 'b'), 1);
	return (ret);
}

char	*insert(t_list **stack_a, t_list **stack_b)
{
	int		sta;
	char	*ret;

	ret = ft_calloc(1, 1);
	sta = *(int *)(*stack_a)->content;
	if (sta <= get_min(stack_b))
	{
		ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
		ret = ft_strjoin_ip(ret, rb(stack_b), 1);
		return (ret);
	}
	else if (sta >= get_max(stack_b))
	{
		ret = ft_strjoin_ip(ret, reset(stack_b, 'b'), 1);
		ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
		return (ret);
	}
	while (!((*(int *)(*stack_b)->content) <= sta
		&& (sta <= *(int *)ft_lstlast(*stack_b)->content)))
		ret = ft_strjoin_ip(ret, rb(stack_b), 1);
	ret = ft_strjoin_ip(ret, pb(stack_a, stack_b), 1);
	return (ret);
}

char	*sort(t_list **stack_a, t_list **stack_b, size_t n)
{
	char	*ret;
	size_t	i;
	size_t	len;
	size_t	lencopy;
	size_t	sorted;

	ret = ft_calloc(1, 1);
	i = 0;
	len = (size_t)ft_lstsize(*stack_a);
	while (n <= len)
	{
		lencopy = len;
		while (lencopy >= 2 * n)
		{
			printf("3.1 for n = %zu\n", n);
			print_list(stack_a, stack_b);
			ret = ft_strjoin_ip(ret, push_bloc(stack_a, stack_b, n, 1), 1);
			printf("3.2 for n = %zu\n", n);
			print_list(stack_a, stack_b);
			ret = ft_strjoin_ip(ret, merge(stack_a, stack_b), 1);
			printf("3.3 for n = %zu\n", n);
			print_list(stack_a, stack_b);
			ret = ft_strjoin_ip(ret, reset(stack_b, 'b'), 1);
			printf("3.4 for n = %zu\n", n);
			print_list(stack_a, stack_b);
			sorted = ft_lstsize(*stack_b);
			ret = ft_strjoin_ip(ret, push_bloc(stack_a, stack_b,
						sorted, -1), 1);
			printf("3.5 for n = %zu\n", n);
			print_list(stack_a, stack_b);
			ret = ft_strjoin_ip(ret, rotate_i(stack_a, sorted), 1);
			printf("3.6 for n = %zu\n", n);
			print_list(stack_a, stack_b);
			lencopy -= sorted;
		}
		ret = ft_strjoin_ip(ret, rotate_i(stack_a, lencopy), 1);
		n *= 2;
	}
	return (ret);
}
