/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:47:55 by akryvenk          #+#    #+#             */
/*   Updated: 2016/11/28 11:47:57 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *alst;
	while (temp)
	{
		temp_next = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp_next;
	}
	*alst = NULL;
}
