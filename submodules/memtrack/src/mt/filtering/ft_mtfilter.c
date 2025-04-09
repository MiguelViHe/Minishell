/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfilter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:45:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	traverse_node(t_mt *lst, void *param, int (*predicate)(t_mt *,
			void *), t_mt **result)
{
	int	i;

	if (!lst || lst->ptr_aux == (void *)NODE_VISITED)
		return ;
	i = 0;
	lst->ptr_aux = (void *)NODE_VISITED;
	if (predicate(lst, param))
		ft_mtaddlast_right(result, ft_mtnew(lst->key, lst, NONE));
	while (i < MAX_DIRECTIONS)
	{
		traverse_node(lst->vect[i], param, predicate, result);
		i++;
	}
	lst->ptr_aux = NULL;
}

/**
 * ft_mtfilter - Filtra nodos de la estructura y los añade a una lista enlazada.
 * @lst: Nodo inicial para el recorrido.
 * @param: Parámetro adicional que se pasa a la función `predicate`.
 * @predicate: Función que determina si un nodo cumple con la condición.
 * @result: Puntero a la lista enlazada donde se agregarán los nodos filtrados.
 * usa ft_mtdup para duplicar los nodos que cumplan con la condición
 */

void	ft_mtfilter(t_mt *lst, void *param, int (*predicate)(t_mt *, void *),
		t_mt **result)
{
	if (!lst)
		return ;
	lst->ptr_aux = NULL;
	traverse_node(lst, param, predicate, result);
}
