/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:46:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * traverse_node - Valida y recorre un nodo si no ha sido visitado.
 * @node: Nodo a validar y recorrer.
 * @param: Parámetro adicional para pasar a la función aplicada.
 * @func: Función a aplicar en el nodo.
 */

static void	traverse_node(t_mt *node, void *param, void (*func)(t_mt *, void *))
{
	int	i;

	if (!node || node->ptr_aux == (void *)NODE_VISITED)
		return ;
	i = 0;
	if (node->ptr_aux != (void *)NODE_VISITED)
	{
		func(node, param);
		node->ptr_aux = (void *)NODE_VISITED;
	}
	while (i < MAX_DIRECTIONS)
	{
		if (node->aux && node->aux->ptr_aux != (void *)NODE_VISITED && i == 0)
			traverse_node(node->aux, param, func);
		if (node->vect[i] && node->vect[i]->ptr_aux != (void *)NODE_VISITED)
			traverse_node(node->vect[i], param, func);
		i++;
	}
	node->ptr_aux = NULL;
}

/**
 * ft_mtiter - Aplica una función a cada nodo de la estructura `t_mt`.
 * @lst: Nodo inicial para el recorrido.
 * @param: Parámetro adicional que se pasa a la función `func`.
 * @func: Función que se aplica a cada nodo visitado.
 */

void	ft_mtiter(t_mt *lst, void *param, void (*func)(t_mt *, void *))
{
	if (!lst || !func)
		return ;
	traverse_node(lst, param, func);
}
