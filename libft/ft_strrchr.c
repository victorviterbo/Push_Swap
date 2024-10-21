/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:15:17 by vviterbo          #+#    #+#             */
/*   Updated: 2024/10/13 13:16:26 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (*(s + i))
		i++;
	if (uc == '\0')
		return ((char *)(s + i));
	while (i > 0)
	{
		i--;
		if ((unsigned char)*(s + i) == uc)
			return ((char *)(s + i));
	}
	return (NULL);
}