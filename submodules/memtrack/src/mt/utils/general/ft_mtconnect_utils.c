/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:43:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdisconnect(t_mt *node, t_direction direction)
{
	int	opposite;

	opposite = ft_mtoposite_direction(direction);
	if (node->vect[direction])
	{
		node->vect[direction]->vect[opposite] = NULL;
		node->vect[direction] = NULL;
	}
}

void	ft_mtconnect(t_mt *node, t_mt *node_to_connect, t_direction direction)
{
	if (!node || !node_to_connect)
		return ;
	node->vect[direction] = node_to_connect;
	node_to_connect->vect[ft_mtoposite_direction(direction)] = node;
}

int	ft_mtoposite_direction(int direction)
{
	int	opposite;

	if (direction < 0)
		return (-1);
	if (direction % 2 == 0)
		opposite = (direction + 1) % 6;
	else
		opposite = (direction - 1) % 6;
	return (opposite);
}
