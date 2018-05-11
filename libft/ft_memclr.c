/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:03:22 by akryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 19:12:23 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memclr(void *memptr, size_t memlen)
{
	size_t i;

	if (memptr)
	{
		i = -1;
		while (++i < memlen)
			((char *)memptr)[i] = 0;
	}
	free(memptr);
}
