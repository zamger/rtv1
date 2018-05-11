/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:30:01 by akryvenk          #+#    #+#             */
/*   Updated: 2016/09/07 20:50:11 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	i = 0;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (temp_s1[i] == temp_s2[i] && temp_s1[i] != '\0' && temp_s2[i] != '\0')
		i++;
	return (temp_s1[i] - temp_s2[i]);
}
