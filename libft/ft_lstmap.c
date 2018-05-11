/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:50:20 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/28 11:50:21 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (lst)
	{
		new_list = f(ft_lstnew(lst->content, lst->content_size));
		new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}
