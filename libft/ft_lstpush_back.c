/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:12:39 by akryvenk          #+#    #+#             */
/*   Updated: 2016/12/02 19:35:45 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **start, t_list *new_node)
{
	t_list *node_start;

	if (start)
	{
		if (*start)
		{
			node_start = *start;
			while (node_start->next)
				node_start = node_start->next;
			node_start->next = new_node;
		}
		else
			*start = new_node;
	}
}
