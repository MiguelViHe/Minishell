/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:09:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:09:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash
int	ft_mtaddlast_child(t_mt *parent, t_mt *child)
{
	if (!parent || !child)
		return (0);
	if (!parent->vect[DOWN])
	{
		if (parent->values.node_type != ROOT)
			parent->values.node_type = BRANCH;
		child->values.node_type = LEAF;
		parent->vect[DOWN] = child;
		child->vect[UP] = parent;
		child->cords.x = parent->cords.x;
		child->cords.y = parent->cords.y + 1;
		child->cords.z = parent->cords.z;
		return (1);
	}
	if (parent->values.node_type != ROOT)
		parent->values.node_type = BRANCH;
	child->values.node_type = LEAF;
	ft_mtaddlast_right(&parent->vect[DOWN], child);
	return (1);
}
