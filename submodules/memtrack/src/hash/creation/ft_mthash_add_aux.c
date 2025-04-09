/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_add_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:12:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:13:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mthash_add_aux(t_hash_table *ht, const char *key, t_mt *aux)
{
	t_mt	*parent;
	int		index;

	if (!ht || !key || !aux)
		return (0);
	parent = ft_mthash_find_node(ht, key);
	if (!parent)
	{
		index = ft_mthash(key, ht->bucket_count);
		parent = ft_mtnew(key, NULL, NONE);
		if (!parent)
			return (ft_mtdelete(&aux), 0);
		parent->values.node_type = BRANCH;
		ft_mtaddlast_right(&ht->buckets[index], parent);
		return (ft_mtaddlast_aux(parent, aux), 1);
	}
	return (ft_mtaddlast_aux(parent, aux), 1);
}
