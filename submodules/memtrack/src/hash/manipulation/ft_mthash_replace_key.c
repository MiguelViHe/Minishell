/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:45:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 13:17:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// reemplaza la clave de un nodo en la tabla hash
void	ft_mthash_replace_key(t_hash_table *ht, const char *old_key,
		const char *new_key)
{
	t_mt	*node;

	if (!ht || !old_key || !new_key)
		return ;
	node = ft_mthash_find_node(ht, old_key);
	if (!node)
		return ;
	free(node->key);
	node->key = ft_strdup(new_key);
}

// si funciona
// node->data = "hola";
// node->key = "key";
// node->type = LEAF;

// ft_mthash_replace_key(ht, "key", "new_key");
// node->key == "new_key";
// node->data == "hola";
// node->type == LEAF;
