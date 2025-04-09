/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:19:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:45:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtfold - Recorre la estructura t_mt y aplica una función acumulativa.
 * @lst: Nodo inicial para comenzar el recorrido.
 * @param: Parámetro adicional que se pasa a la función acumulativa.
 * @func: Función que se aplica a cada nodo; debe retornar un entero.
 *
 * Return: La suma de los resultados devueltos por func en todos los
	nodos visitados.
 */

int	ft_mtfold(t_mt *lst, void *param, int (*func)(t_mt *, void *))
{
	int	result;
	int	i;

	if (!lst || !func || lst->ptr_aux == (void *)NODE_VISITED)
		return (0);
	result = 0;
	i = 0;
	lst->ptr_aux = (void *)NODE_VISITED;
	result += func(lst, param);
	while (i < MAX_DIRECTIONS)
	{
		if (lst->vect[i] && lst->vect[i]->ptr_aux != (void *)NODE_VISITED)
			result += ft_mtfold(lst->vect[i], param, func);
		if (lst->aux && lst->aux->ptr_aux != (void *)NODE_VISITED)
			result += ft_mtfold(lst->aux, param, func);
		i++;
	}
	return (lst->ptr_aux = NULL, result);
}
