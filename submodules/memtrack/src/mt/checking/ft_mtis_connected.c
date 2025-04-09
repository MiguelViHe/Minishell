/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtis_connected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:47:26 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/24 17:49:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtis_connected - Checks if a node is connected to the tree.
 *
 * @first: First node of the tree.
 * @node: Node to check.
 *
 * Returns 1 if the node is connected, 0 otherwise.
 */

static int	ft_mtmatch_node(t_mt *node, void *param)
{
	return (node == param);
}

int	ft_mtis_connected(t_mt **first, t_mt *node)
{
	t_mt	*found;

	if (!first || !*first || !node)
		return (0);
	if (node == *first)
		return (1);
	found = ft_mtsearch(*first, node, ft_mtmatch_node);
	if (found)
		return (1);
	return (0);
}
