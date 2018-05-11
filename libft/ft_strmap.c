/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:02:37 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/25 14:02:38 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*c;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	c = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (c == NULL)
		return (NULL);
	while (s[i])
	{
		c[i] = f(s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
