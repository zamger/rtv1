/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:31:52 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/21 17:37:55 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_src;
	char	*temp_dst;

	temp_src = (char*)src;
	temp_dst = (char*)dst;
	if (len)
	{
		if (temp_src < temp_dst)
		{
			temp_src += len;
			temp_dst += len;
			while (len--)
				*--temp_dst = *--temp_src;
		}
		else
		{
			while (len--)
				*temp_dst++ = *temp_src++;
		}
	}
	return (dst);
}
