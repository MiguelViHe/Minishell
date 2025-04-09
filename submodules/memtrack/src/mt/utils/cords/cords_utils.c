/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:58:46 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:46:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_cords	ft_mtcords(int x, int y, int z)
{
	t_cords	cords;

	cords.x = x;
	cords.y = y;
	cords.z = z;
	return (cords);
}

t_cords	ft_mtcords_diff(t_cords cords, int x, int y, int z)
{
	cords.x += x;
	cords.y += y;
	cords.z += z;
	return (cords);
}

static void	update_cords_recursive(t_mt *node, t_cords cords)
{
	t_cords	new_cords;
	int		i;

	i = 0;
	while (i < MAX_DIRECTIONS)
	{
		if (node->vect[i])
		{
			new_cords = cords;
			new_cords = ft_mtcords_sum_direction(new_cords, i);
			node->vect[i]->cords = new_cords;
			ft_mtupdate_cords(node->vect[i], new_cords);
		}
		i++;
	}
}

void	ft_mtupdate_cords(t_mt *node, t_cords cords)
{
	if (!node || node->ptr_aux == (void *)NODE_VISITED)
		return ;
	node->cords = cords;
	node->ptr_aux = (void *)NODE_VISITED;
	update_cords_recursive(node, cords);
	node->ptr_aux = NULL;
}

t_cords	ft_mtcordscpy(t_cords cords)
{
	return (ft_mtcords(cords.x, cords.y, cords.z));
}
