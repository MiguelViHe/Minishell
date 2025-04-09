/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_collect_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:49:02 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 10:29:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mthash_collect_types
	- Recolecta nodos de un tipo específico desde una tabla hash.
 * @ht: Tabla hash a procesar.
 * @type: Tipo de dato que se desea recolectar.
 *
 * Return: Lista enlazada de nodos recolectados.
 */
t_mt	*ft_mthash_collect_data_types(t_hash_table *ht, t_data_type type)
{
	size_t	i;
	t_mt	*collected;
	t_mt	*current;
	t_mt	*temp;

	if (!ht)
		return (NULL);
	i = 0;
	collected = NULL;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		temp = ft_mtcollect_data_type(current, type);
		ft_mtaddlast_right(&collected, temp);
		temp = NULL;
		i++;
	}
	return (collected);
}

t_mt	*ft_mthash_collect_node_types(t_hash_table *ht, t_node_type type)
{
	size_t	i;
	t_mt	*collected;
	t_mt	*current;
	t_mt	*temp;

	if (!ht)
		return (NULL);
	i = 0;
	collected = NULL;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		temp = ft_mtcollect_node_type(current, type);
		ft_mtaddlast_right(&collected, temp);
		temp = NULL;
		i++;
	}
	return (collected);
}
