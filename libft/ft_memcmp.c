/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:29:33 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/21 18:35:26 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	temp_s1;
	unsigned char	temp_s2;

	while (n-- > 0)
	{
		temp_s1 = *(unsigned char *)s1;
		temp_s2 = *(unsigned char *)s2;
		if (temp_s1 != temp_s2)
		{
			return (temp_s1 - temp_s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
