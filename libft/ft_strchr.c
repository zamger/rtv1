/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:26:46 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/23 17:30:41 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char *temp_s;

	temp_s = (char*)s;
	while (*temp_s != c)
	{
		if (*temp_s == '\0')
			return (0);
		temp_s++;
	}
	return (temp_s);
}
