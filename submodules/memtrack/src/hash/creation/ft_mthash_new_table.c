/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_new_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:21:40 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:35:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_new_hash_table - Crea una nueva tabla hash.
 * @bucket_count: Número de buckets.
 *
 * Retorna un puntero a la nueva tabla hash.
 */

// crea una nueva tabla hash

static void	set_methods(t_hash_table *ht)
{
	ht->methods.insert = ft_mthash_insert;
	ht->methods.search = ft_mthash_find_node;
	ht->methods.search_data = ft_mthash_find_data;
	ht->methods.remove = ft_mthash_remove_node;
	ht->methods.free_table = ft_mtfree_hash_table;
	ht->methods.print = ft_mtprint_hash_table;
	ht->methods.add_aux = ft_mthash_add_aux;
	ht->methods.replace_key = ft_mthash_replace_key;
	ht->methods.replace_data = ft_mthash_replace_data;
	ht->methods.replace_node = ft_mthash_replace_node;
	ht->methods.add = ft_mthash_add_node;
	ht->methods.set_free_func = ft_mthash_set_free_func;
}

t_hash_table	*ft_mthash_new_table(size_t bucket_count, char *name)
{
	t_hash_table	*ht;

	ht = malloc(sizeof(t_hash_table));
	if (!ht)
		return (NULL);
	ht->name = name;
	ht->bucket_count = bucket_count;
	ht->buckets = (t_mt **)ft_calloc(bucket_count, sizeof(t_mt *));
	if (!ht->buckets)
		return (free(ht), NULL);
	set_methods(ht);
	return (ht);
}
// si funciona
// tiene funciones como un menu
