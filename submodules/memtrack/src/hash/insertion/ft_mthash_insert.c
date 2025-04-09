/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:22:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/05 12:35:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash_insert - Inserta un nodo en la tabla hash.
 * @ht: Tabla hash.
 * @key: Clave del nodo.
 * @data: Datos a almacenar.
 * @size: Tamaño de los datos.
 *
 * Retorna 0 si tuvo éxito, -1 si falló.
 */

// inserta un nodo en la tabla hash y remplace si ya existe
int	ft_mthash_insert(t_hash_table *ht, const char *key, void *data,
		t_data_type type)
{
	size_t	index;
	t_mt	*current;
	t_mt	*new_node;

	if (!ht || !key)
		return (-1);
	if (ft_mthash_exists(ht, key))
	{
		current = ft_mthash_find_node(ht, key);
		ft_replace_data(current, data, type);
		return (0);
	}
	index = ft_mthash(key, ht->bucket_count);
	new_node = ft_mtnew(key, data, type);
	if (!new_node)
		return (-1);
	ft_mtaddlast_right(&ht->buckets[index], new_node);
	return (0);
}
