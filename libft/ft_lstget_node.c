/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:02:17 by akryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 19:52:23 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_node(t_list *start, size_t pos)
{
	size_t i;

	if (start)
	{
		i = 0;
		while (i != pos && start)
		{
			i++;
			start = start->next;
		}
	}
	return (start);
}
