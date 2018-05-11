/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:12:34 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/26 19:30:13 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	register unsigned char	*temp_s1;
	register unsigned char	*temp_s2;

	if (!n)
		return (0);
	i = 0;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (*temp_s1 == *temp_s2 && *temp_s1 &&
			*temp_s2 && ++i < n)
	{
		temp_s1++;
		temp_s2++;
	}
	return (*temp_s1 - *temp_s2);
}
