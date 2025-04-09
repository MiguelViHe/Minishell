/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcollect_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:16:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:47:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * match_state - Compara el estado del nodo con el estado pasado como parámetro.
 * @node: Nodo a comparar.
 * @state: Estado de nodo a comparar.
 * Return: 1 si el nodo es del estado pasado, 0 en caso contrario.
 */
static int	match_state(t_mt *node, void *state)
{
	if (node->values.state == *(int *)state)
		return (1);
	return (0);
}

/**
 * ft_mtcollect_state
	- Recolecta nodos de un estado específico en un árbol/lista.
 * @mt: Nodo raíz o inicio de la lista de nodos a procesar.
 * @state: Estado de nodo que se desea recolectar.
 * utiliza ft_mtfilter para recolectar los nodos de un estado específico
 *
 */

t_mt	*ft_mtcollect_state(t_mt *mt, int state)
{
	t_mt	*collected;

	if (!mt || mt->ptr_aux)
		return (NULL);
	collected = NULL;
	ft_mtfilter(mt, &state, match_state, &collected);
	return (collected);
}
