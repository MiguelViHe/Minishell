/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:45:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/07 10:01:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @brief intercambia los dos primeros nodos, a la direccion indicada
 *
 */

void	ft_mtswap(t_mt **lst, t_direction direction)
{
	t_mt	*sub;
	t_mt	*next;
	int		oposite;

	if (!lst || !(*lst))
		return ;
	next = (*lst)->vect[direction];
	if (!next)
		return ;
	sub = NULL;
	sub = ft_mtsub(lst, next);
	if (sub)
	{
		oposite = ft_mtoposite_direction(direction);
		ft_mtaddfirst(lst, sub, oposite);
	}
}
