/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:35:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:07:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list in whatever direction.
void	ft_mtaddlast(t_mt **lst, t_mt *new, t_direction direction)
{
	t_mt	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->values.data_type = LEAF;
		last = ft_mtlast(*lst, direction);
		ft_mtconnect(last, new, direction);
	}
}
