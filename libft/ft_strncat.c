/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:47:40 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/23 13:47:43 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, int n)
{
	char *temp_s1;
	char *temp_s2;

	temp_s1 = (char*)s1;
	temp_s2 = (char*)s2;
	while (*temp_s1)
	{
		temp_s1++;
	}
	while (*temp_s2 && n)
	{
		*temp_s1++ = *temp_s2++;
		n--;
	}
	*temp_s1 = '\0';
	return (s1);
}
