/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsize_dimension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:22:48 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:44:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/*
static void	update_min_cord(t_mt *node, t_cords *min_cords)
{
	if (node->cords.x < min_cords->x)
		min_cords->x = node->cords.x;
	if (node->cords.y < min_cords->y)
		min_cords->y = node->cords.y;
	if (node->cords.z < min_cords->z)
		min_cords->z = node->cords.z;
}

static void	update_max_cord(t_mt *node, t_cords *max_cords)
{
	if (node->cords.x > max_cords->x)
		max_cords->x = node->cords.x;
	if (node->cords.y > max_cords->y)
		max_cords->y = node->cords.y;
	if (node->cords.z > max_cords->z)
		max_cords->z = node->cords.z;
}

static void	traverse_and_update(t_mt *node, t_cords *cords,
		void (*update_func)(t_mt *, t_cords *))
{
	int	i;

	if (!node || node->ptr_aux == NODE_VISITED)
		return ;
	node->ptr_aux = NODE_VISITED;
	update_func(node, cords);
	i = 0;
	while (i < MAX_DIRECTIONS)
	{
		if (node->vect[i])
			traverse_and_update(node->vect[i], cords, update_func);
		i++;
	}
	node->ptr_aux = NULL;
}

int	ft_mtsize_dimension(t_mt *node, char dimension, char min_max)
{
	t_cords	min_cords;
	t_cords	max_cords;

	min_cords = {INT_MAX, INT_MAX, INT_MAX};
	max_cords = {INT_MIN, INT_MIN, INT_MIN};
	if (!node)
		return (0);
	if (min_max == '-')
		traverse_and_update(node, &min_cords, update_min_cord);
	else
		traverse_and_update(node, &max_cords, update_max_cord);
	if (dimension == 'x' && min_max == '-')
		return (min_cords.x);
	else if (dimension == 'x' && min_max == '+')
		return (max_cords.x);
	if (dimension == 'y' && min_max == '-')
		return (min_cords.y);
	else if (dimension == 'y' && min_max == '+')
		return (max_cords.y);
	if (dimension == 'z' && min_max == '-')
		return (min_cords.z);
	else if (dimension == 'z' && min_max == '+')
		return (max_cords.z);
	return (0);
}
 */