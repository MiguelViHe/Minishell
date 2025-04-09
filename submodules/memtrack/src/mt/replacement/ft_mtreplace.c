/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:32:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/03 06:55:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the node 'node' with 'new_node' in the list 'list'.

void	ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node)
{
	t_mt	*temp;

	if (!node || !new_node)
		return ;
	temp = node->vect[LEFT];
	if (temp)
		temp->vect[RIGHT] = new_node;
	else
		*list = new_node;
	new_node->vect[LEFT] = temp;
	new_node->vect[RIGHT] = node->vect[RIGHT];
	if (node->vect[RIGHT])
		node->vect[RIGHT]->vect[LEFT] = new_node;
	ft_mtdelete(&node);
}
