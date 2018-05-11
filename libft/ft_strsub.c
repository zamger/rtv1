/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:59:27 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/25 18:59:28 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (s)
	{
		new = malloc(len + 1);
		if (!new)
			return (NULL);
		i = 0;
		while (len)
		{
			new[i] = s[start + i];
			i++;
			len--;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
