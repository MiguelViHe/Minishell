/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:08:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/05 12:35:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// reemplaza un nodo en la tabla hash
void	ft_mthash_replace_node(t_hash_table *ht, const char *key, t_mt *node)
{
	size_t	index;

	if (!ht || !key || !node)
		return ;
	index = ft_mthash(key, ht->bucket_count);
	if (!ft_mthash_exists(ht, key))
	{
		ft_mtaddlast_right(&ht->buckets[index], node);
		return ;
	}
	ft_mtreplace(&ht->buckets[index], ft_mthash_find_node(ht, key), node);
}
// This function replaces the node with the key 'key' with the
// node 'node' in the hash table 'ht'. If the node does not exist
// it adds the node to the hash table.