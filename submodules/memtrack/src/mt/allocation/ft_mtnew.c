/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/23 15:41:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Creates a new node for a list.
t_mt	*ft_mtnew(const char *key, void *data, t_data_type type)
{
	t_mt	*node;

	node = ft_calloc(1, sizeof(t_mt));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), NULL);
	node->data = data;
	node->values.size = sizeof(data);
	node->values.count = 1;
	node->values.to_free = 1;
	node->values.data_type = type;
	node->values.node_type = ROOT;
	node->values.priority = -1;
	node->cords.x = -1;
	node->cords.y = -1;
	node->cords.z = -1;
	node->free_data = ft_mtget_free_data(type);
	return (node);
}
