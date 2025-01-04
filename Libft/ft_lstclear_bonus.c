/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:12:32 by aybouatr          #+#    #+#             */
/*   Updated: 2024/11/14 11:50:05 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*help;

	if ((!lst) || (!del))
		return ;
	help = *lst;
	while (help)
	{
		temp = help;
		help = help->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
