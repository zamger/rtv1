/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:07:41 by akryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 14:07:41 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_file(int fd, int f_size)
{
	char	buf[f_size + 1];
	int		ret;

	if (fd && f_size)
	{
		ret = read(fd, buf, f_size);
		buf[ret] = '\0';
		close(fd);
		ft_putstr(buf);
	}
}
