/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:36:11 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 11:36:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns the last element of the list in the direction specified.

t_mt	*ft_mtlast(t_mt *lst, t_direction direction)
{
	if (!lst)
		return (NULL);
	while (lst->vect[direction])
		lst = lst->vect[direction];
	return (lst);
}
