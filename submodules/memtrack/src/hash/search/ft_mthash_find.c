/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:10:13 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:12:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_hash_find - Busca un nodo en la tabla hash.
 * @ht: Tabla hash.
 * @key: Clave del nodo.
 * @return NULL if is not found
 * 
**/
// busca un nodo en la tabla hash y retorna el nodo
void	*ft_mthash_find_node(t_hash_table *ht, const char *key)
{
	int		index;
	t_mt	*current;
	t_mt	*result;

	if (!ht || !key)
		return (NULL);
	index = ft_mthash_get_index(ht, key);
	if (index == -1)
		return (NULL);
	current = ht->buckets[index];
	result = ft_mtsearch_key(current, key);
	if (result)
		return (result);
	return (NULL);
}

// encuentra un nodo en la tabla hash y retorna los datos
void	*ft_mthash_find_data(t_hash_table *ht, const char *key)
{
	int		index;
	t_mt	*current;
	t_mt	*result;

	if (!ht || !key)
		return (NULL);
	index = ft_mthash_get_index(ht, key);
	if (index == -1)
		return (NULL);
	current = ht->buckets[index];
	result = ft_mtsearch_key(current, key);
	if (result)
		return (result->data);
	return (NULL);
}
