/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 10:10:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// reemplaza los datos de un nodo en la tabla hash
// si el nodo no existe no hace nada
void	ft_mthash_replace_data(t_hash_table *ht, const char *key,
		void *new_data, t_data_type type)
{
	t_mt	*node;

	if (!ht || !key || !new_data)
		return ;
	node = ft_mthash_find_node(ht, key);
	if (!node)
		return ;
	ft_mtdel_by_type(&node->data, node->values.data_type);
	ft_replace_data(node, new_data, type);
}

// si funciona
// node->data = "hola";
// node->key = "key";
// node->type = LEAF;
// ft_mthash_replace_data(ht, "key", nodo, branch);
// node->data == nodo;
// node->type == branch;
