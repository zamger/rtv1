/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:46:09 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/21 17:58:50 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	register unsigned char	*sp;
	register size_t			i;

	if (n != 0)
	{
		sp = (unsigned char*)s;
		i = 0;
		while (i++ < n)
		{
			if ((*sp++) == (unsigned char)c)
				return ((void *)(sp - 1));
		}
	}
	return (NULL);
}
