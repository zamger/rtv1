/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:29:20 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/24 15:29:22 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*result_str;
	int		i;

	i = 0;
	result_str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result_str)
		return (NULL);
	while (s1[i])
	{
		result_str[i] = s1[i];
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}
