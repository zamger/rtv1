/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:27:14 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/25 13:27:15 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[12];
	char	*res;

	res = arr;
	res += 11;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n >= 0)
	{
		while (n != 0)
		{
			*--res = '0' + (n % 10);
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*--res = '0' - (n % 10);
			n /= 10;
		}
		*--res = '-';
	}
	ft_putstr_fd(res, fd);
}
