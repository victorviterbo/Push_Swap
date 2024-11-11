/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/11 15:16:35 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"


#include <libc.h>

void	print_list(t_list **lst1, t_list **lst2);
int		minichecker(t_list **stack_a, t_list **stack_b);

void	print_list(t_list **lst1, t_list **lst2)
{
	t_list	*current1;
	t_list	*current2;

	if (!lst1 || !lst2)
		return ;
	current1 = *lst1;
	current2 = *lst2;
	return ;
	printf("---------------------------\n");
	while ((current1 && current1->content) || (current2 && current2->content))
	{
		if ((current1 && current1->content) && !(current2 && current2->content))
		{
			printf("%i\t\n", *((int *)current1->content));
			current1 = current1->next;
		}
		else if (!(current1 && current1->content) && (current2 && current2->content))
		{
			printf("\t%i\n", *((int *)current2->content));
			current2 = current2->next;
		}
		else
		{
			printf("%i\t%i\n", *((int *)current1->content), *((int *)current2->content));
			current1 = current1->next;
			current2 = current2->next;
		}
	}
	printf("---------------------------\n");
	return ;
}
