/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:26:48 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/22 14:28:44 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new_mem;

	new_mem = (void*)malloc(size);
	if (!new_mem)
		return (NULL);
	ft_memset((void*)new_mem, 0, size);
	return (new_mem);
}
