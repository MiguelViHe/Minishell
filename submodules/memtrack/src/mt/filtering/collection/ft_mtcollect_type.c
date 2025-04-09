/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcollect_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:58:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 12:03:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * match_node_type
 * Compara el tipo de nodo con el tipo pasado como parámetro.
 * @node: Nodo a comparar.
 * @type: Tipo de nodo a comparar.
 * Return: 1 si el nodo es del tipo pasado, 0 en caso contrario.
 */

static int	match_node_type(t_mt *node, void *type)
{
	if (node->values.node_type == *(int *)type)
		return (1);
	return (0);
}

/**
 * match_data_type
 * Compara el tipo de dato con el tipo pasado como parámetro.
 * @node: Nodo a comparar.
 * @type: Tipo de dato a comparar.
 * Return: 1 si el nodo es del tipo pasado, 0 en caso contrario.
 */

static int	match_data_type(t_mt *node, void *type)
{
	if (node->values.data_type == *(int *)type)
		return (1);
	return (0);
}

/**
 * ft_mtcollect_node_type
	- Recolecta nodos de un tipo específico en un árbol/lista.
 * @mt: Nodo raíz o inicio de la lista de nodos a procesar.
 * @type: Tipo de nodo que se desea recolectar.
 * utiliza ft_mtfilter para recolectar los nodos de un tipo específico
 *
 */

t_mt	*ft_mtcollect_node_type(t_mt *mt, t_node_type type)
{
	t_mt	*collected;

	if (!mt || mt->ptr_aux)
		return (NULL);
	collected = NULL;
	ft_mtfilter(mt, &type, match_node_type, &collected);
	return (collected);
}

/**
 * ft_mtcollect_data_type
 * Recolecta nodos de un tipo específico en un árbol/lista.
 * @mt: Nodo raíz o inicio de la lista de nodos a procesar.
 * @type: Tipo de dato que se desea recolectar.
 * utiliza ft_mtfilter para recolectar los nodos de un tipo específico
 */

t_mt	*ft_mtcollect_data_type(t_mt *mt, t_data_type type)
{
	t_mt	*collected;

	if (!mt || mt->ptr_aux)
		return (NULL);
	collected = NULL;
	ft_mtfilter(mt, &type, match_data_type, &collected);
	return (collected);
}
