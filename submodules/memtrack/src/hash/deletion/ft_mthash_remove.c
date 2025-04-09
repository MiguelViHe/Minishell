/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:47 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:12:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mthash_remove - Elimina un nodo de la tabla hash basado en la clave.
 * @ht: Tabla hash.
 * @key: Clave del nodo a eliminar.
 *
 * Retorna 0 si tuvo éxito, -1 si falló (clave no encontrada).
 */

// falta actualizar para eliminar en cualquier parte de la lista
// elimina un nodo de la tabla hash basado en la clave

// DFS, BFS, A* o IDA* (Algoritmos de Búsqueda).

int	ft_mthash_remove_node(t_hash_table *ht, const char *key)
{
	t_mt	*current;
	int		index;

	if (!ht || !key)
		return (-1);
	index = ft_mthash_get_index(ht, key);
	if (index == -1)
		return (-1);
	current = ft_mtsearch_key(ht->buckets[index], key);
	if (!current)
		return (-1);
	ft_mtremove(&ht->buckets[index], current);
	return (1);
}
