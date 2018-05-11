/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:01:24 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/25 16:05:25 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		num_of_words(char const *s, char c)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != '\0')
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			index++;
		}
	}
	return (index);
}

static int			str_len(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char			**new_arr(char const *s, char **str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] == c && s[i])
			i++;
		else if (s[i])
		{
			j = str_len(s, c);
			str[k] = ft_strnew(j + 1);
			str[k][j] = '\0';
			j = 0;
			while (s[i] != '\0' && s[i] != c)
				str[k][j++] = s[i++];
			k++;
		}
	}
	str[k] = NULL;
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(str) * (num_of_words(s, c) + 2))))
		return (NULL);
	return (new_arr(s, str, c));
}
