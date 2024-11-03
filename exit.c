/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:33:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/03 16:56:35 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	exit_gracefully(t_list **stack_a, int status);

void	exit_gracefully(t_list **stack_a, int status)
{
	ft_lstclear(stack_a, free);
	if (status)
		write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
