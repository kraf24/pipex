/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:01:20 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/05/06 21:52:49 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (temp == 0)
	{
		del(temp->content);
		temp = ft_lstmap(lst->next, f, del);
	}
	else
		temp->next = ft_lstmap(lst->next, f, del);
	return (temp);
}
