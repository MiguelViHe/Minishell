/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_add_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:07:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:12:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Añade el nodo a la tabla hash
void	ft_mthash_add_node(t_hash_table *ht, t_mt *node)
{
	size_t	index;

	if (!ht || !node)
		return ;
	if (ft_mthash_exists(ht, node->key))
		node->key = ft_mthash_new_original_key(node->key, ht);
	index = ft_mthash(node->key, ht->bucket_count);
	ft_mtaddlast_right(&ht->buckets[index], node);
}
