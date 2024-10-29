/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:25:50 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/28 22:19:40 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stddef.h>



#include <libc.h>





void	print_list(t_list **lst1, t_list **lst2);
int		minichecker(t_list **stack_a, t_list **stack_b);

char	*init(t_list **stack_a, t_list **stack_b);
char	*merge(t_list **stack_a, t_list **stack_b);
char	*insert(t_list **stack_a, t_list **stack_b);
char	*sort(t_list **stack_a, t_list **stack_b, size_t n);

void	push(t_list **stack_a, t_list **stack_b);
char	*pa(t_list **stack_a, t_list **stack_b);
char	*pb(t_list **stack_a, t_list **stack_b);
char	*push_bloc(t_list **stack_a, t_list **stack_b, size_t size, int dir);

void	revrotate(t_list **stack);
char	*rra(t_list **stack_a);
char	*rrb(t_list **stack_b);
char	*rrr(t_list **stack_a, t_list **stack_b);

void	rotate(t_list **stack);
char	*ra(t_list **stack_a);
char	*rb(t_list **stack_b);
char	*rr(t_list **stack_a, t_list **stack_b);
char	*rotate_i(t_list **stack_a, size_t n);

void	swap(t_list **stack);
char	*sa(t_list **stack_a);
char	*sb(t_list **stack_b);
char	*ss(t_list **stack_a, t_list **stack_b);

int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
char	*reset_a(t_list **stack_a);
char	*reset_b(t_list **stack_b);
t_list	**parse_input(int argc, char *argv[]);

char	*simplify(char *s, size_t last_size);
char	*cut(char *s, size_t start, size_t end, int ip);
int		gotonext(char *s, int i);

#endif