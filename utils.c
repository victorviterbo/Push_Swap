/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:47 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/04 20:12:48 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	reset(t_list **stack, char ab);
t_list	**parse_input(int argc, char *argv[]);
void	add_to_stack(t_list **stack, char *str);

void	reset(t_list **stack, char ab)
{
	int		target;

	if (ab == 'a')
		target = ft_lstmin(stack);
	else
		target = ft_lstmax(stack);
	while (*(int *)(*stack)->content != target)
	{
		if (ab == 'a')
			ra(stack);
		else
			rb(stack);
	}
	return ;
}

t_list	**parse_input(int argc, char *argv[])
{
	size_t	i;
	t_list	**stack_a;
	char	**arguments;

	i = 0;
	stack_a = ft_calloc(1, sizeof(t_list *));
	if (!stack_a)
		return (NULL);
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		arguments = ft_strarray_mapi(argv, ft_strdup);
		i = 1;
	}
	while (arguments[i])
	{
		add_to_stack(stack_a, arguments[i]);
		i++;
	}
	return (stack_a);
}

void	add_to_stack(t_list **stack, char *str)
{
	int		*tmp;
	t_list	*new_node;

	if (ft_strchr(str, ' '))
		add_to_stack(stack, str);
	else
	{
		if (!ft_isnumber(str))
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		tmp = ft_calloc(1, sizeof(int));
		if (!tmp)
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		*tmp = ft_atoi(str);
		if (ft_lst_isin(stack, tmp, sizeof(int)))
		{
			free(tmp);
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		}
		new_node = ft_lstnew(tmp);
		if (!new_node)
			exit_gracefully(stack, NULL, NULL, EXIT_FAILURE);
		ft_lstadd_back(stack, new_node);
	}
}
