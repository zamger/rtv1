/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 20:14:30 by akryvenk          #+#    #+#             */
/*   Updated: 2016/09/06 19:03:08 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	char *beg;
	char *patt;

	if (!*to_find)
		return ((char*)str);
	while (*str)
	{
		beg = (char*)str;
		patt = (char*)to_find;
		while (*beg && *patt && !(*beg - *patt))
		{
			beg++;
			patt++;
		}
		if (!*patt)
			return ((char*)str);
		str++;
	}
	return (0);
}
