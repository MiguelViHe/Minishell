/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_abyacent_cords.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:52:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:46:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_connect_one_abyacent_cords(t_mt *last, t_mt *new,
		t_direction direction)
{
	t_mt	*found_in_last;
	t_cords	cords_to_find;

	cords_to_find = ft_mtget_cords_by_direction(direction);
	cords_to_find = ft_mtcords_sum(cords_to_find, new->cords);
	found_in_last = ft_mtsearch_cords(last, cords_to_find);
	if (found_in_last && !new->vect[direction])
		ft_mtconnect(new, found_in_last, direction);
}

void	ft_mtconnect_abyacent_cords(t_mt *last, t_mt *new)
{
	t_direction	direction;

	if (!last || !new || new->ptr_aux == (void *)NODE_VISITED)
		return ;
	direction = 0;
	new->ptr_aux = (void *)NODE_VISITED;
	while (direction < MAX_DIRECTIONS)
	{
		ft_connect_one_abyacent_cords(last, new, direction);
		if (new->vect[direction])
			ft_mtconnect_abyacent_cords(last, new->vect[direction]);
		direction++;
	}
	new->ptr_aux = NULL;
}
