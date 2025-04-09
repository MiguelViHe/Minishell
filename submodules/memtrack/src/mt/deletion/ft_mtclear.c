/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:45:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * match_clear - Libera la memoria de un nodo.
 * @node: Nodo a liberar.
 * @param: Parámetro adicional que se pasa a la función.
 */

static void	match_clear(t_mt **node, void *param)
{
	(void)param;
	if (!(*node) || !node)
		return ;
	if ((*node)->values.to_free)
	{
		if ((*node)->free_data && (*node)->data)
			(*node)->free_data(&(*node)->data);
	}
	if ((*node)->aux)
		ft_mtclear(&(*node)->aux);
	if ((*node)->key)
		freedom((void **)&(*node)->key);
	freedom((void **)node);
}

static void	ft_mtclean_aux(t_mt *lst)
{
	int	i;

	i = 0;
	if (!lst || lst->ptr_aux == (void *)NODE_VISITED)
		return ;
	lst->ptr_aux = (void *)NODE_VISITED;
	while (i < MAX_DIRECTIONS)
	{
		if (lst->vect[i] && lst->vect[i]->ptr_aux == (void *)NODE_VISITED)
			ft_mtdisconnect(lst, i);
		ft_mtclean_aux(lst->vect[i]);
		i++;
	}
	lst->ptr_aux = NULL;
	match_clear(&lst, NULL);
}

/**
 * ft_mtclear - Libera la memoria de la lista.
 * @lst: Lista a liberar.
 * usa ft_mtiter para liberar la memoria de la lista
 */

void	ft_mtclear(t_mt **lst)
{
	if (!*lst || !lst)
		return ;
	ft_mtclean_aux(*lst);
	*lst = NULL;
}
