/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:22:04 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/28 11:22:05 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_ls;

	new_ls = (t_list*)malloc(sizeof(t_list));
	if (!new_ls)
		return (NULL);
	if (content == NULL)
	{
		new_ls->content = NULL;
		new_ls->content_size = 0;
	}
	else
	{
		new_ls->content = malloc(content_size);
		new_ls->content_size = content_size;
		ft_memmove(new_ls->content, content, content_size);
	}
	new_ls->next = NULL;
	return (new_ls);
}
