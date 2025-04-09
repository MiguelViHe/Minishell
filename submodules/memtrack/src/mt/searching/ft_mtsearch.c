/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:50:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static t_mt	*traverse_node(t_mt *node, void *param, t_predicate predicate)
{
	t_mt	*found;
	int		i;

	if (!node || !predicate || node->ptr_aux == (void *)NODE_VISITED)
		return (NULL);
	node->ptr_aux = (void *)NODE_VISITED;
	if (predicate(node, param))
		return (node->ptr_aux = NULL, node);
	found = NULL;
	i = 0;
	while (i < MAX_DIRECTIONS && !found)
	{
		if (node->aux && !found && i == 0)
			found = traverse_node(node->aux, param, predicate);
		if (node->vect[i] && !found)
			found = traverse_node(node->vect[i], param, predicate);
		i++;
	}
	node->ptr_aux = NULL;
	return (found);
}

/**
 * ft_mtsearch
		- Busca un nodo en la estructura t_mt que cumpla con la condición.
 * @lst: Nodo inicial para comenzar la búsqueda.
 * @param: Parámetro adicional que se pasa a la función `predicate`.
 * @predicate: Función que determina si un nodo cumple con la condición.
 *
 * Return: El nodo que cumple con la condición, o NULL si no se encontró.
 */

t_mt	*ft_mtsearch(t_mt *lst, void *param, int (*predicate)(t_mt *, void *))
{
	t_mt	*found;

	if (!lst || !predicate || lst->ptr_aux)
		return (NULL);
	found = traverse_node(lst, param, predicate);
	return (found);
}
