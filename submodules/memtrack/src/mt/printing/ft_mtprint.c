/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:46:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtprint(t_mt *lst, int b, char *c)
{
	if (!lst)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	while (lst)
	{
		if (b == 1 && lst->data)
			ft_printf("%s", (char *)lst->data);
		else if (b == 0 && lst->data)
			ft_printf("%p", lst->data);
		else if (b == 2 && lst->data)
			ft_printf("%d", *(int *)lst->data);
		else if (!lst->data)
			ft_printf("(NULL)");
		if (lst->vect[RIGHT])
			ft_printf("%s", c);
		lst = lst->vect[RIGHT];
	}
	printf("\n");
}
