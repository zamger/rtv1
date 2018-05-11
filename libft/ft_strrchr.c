/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:57:09 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/23 17:57:10 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char	*temp_s;
	int		i;

	i = 0;
	temp_s = (char*)s;
	while (temp_s[i])
		i++;
	if (!i)
		return (NULL);
	while (i >= 0)
	{
		if (temp_s[i] == (char)c)
			return (&temp_s[i]);
		i--;
	}
	return (NULL);
}
