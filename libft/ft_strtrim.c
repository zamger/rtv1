/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:00:56 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/25 17:00:57 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*trim_s;
	size_t		begin;
	size_t		end;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		begin = 0;
		end = ft_strlen(s) - 1;
		while ((s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
				&& begin < end + 1)
			begin++;
		while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
				&& &s[end] != s)
			end--;
		if (begin >= end || begin == ft_strlen(s))
			return (ft_strnew(1));
		if ((trim_s = ft_strnew(end - begin + 1)))
		{
			ft_strncpy(trim_s, (char*)s + begin, end - begin + 1);
			return (trim_s);
		}
	}
	return (NULL);
}
