/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:41:04 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:59:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtutils.h"

t_cords	ft_mtcords_sum(t_cords a, t_cords b)
{
	t_cords	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_cords	ft_mtcords_sum_direction(t_cords cords, int direction)
{
	t_cords	result;
	t_cords	dir[6];

	dir[0] = ft_mtcords(1, 0, 0);
	dir[1] = ft_mtcords(-1, 0, 0);
	dir[2] = ft_mtcords(0, 1, 0);
	dir[3] = ft_mtcords(0, -1, 0);
	dir[4] = ft_mtcords(0, 0, 1);
	dir[5] = ft_mtcords(0, 0, -1);
	result.x = cords.x + dir[direction].x;
	result.y = cords.y + dir[direction].y;
	result.z = cords.z + dir[direction].z;
	return (result);
}

t_direction	ft_mtget_direction_by_cords(t_cords cords)
{
	if (cords.x == 1)
		return (RIGHT);
	if (cords.x == -1)
		return (LEFT);
	if (cords.y == 1)
		return (UP);
	if (cords.y == -1)
		return (DOWN);
	if (cords.z == 1)
		return (FRONT);
	if (cords.z == -1)
		return (BACK);
	return (-1);
}

t_cords	ft_mtget_cords_by_direction(t_direction direction)
{
	t_cords	result;
	t_cords	dir[6];

	dir[0] = ft_mtcords(1, 0, 0);
	dir[1] = ft_mtcords(-1, 0, 0);
	dir[2] = ft_mtcords(0, 1, 0);
	dir[3] = ft_mtcords(0, -1, 0);
	dir[4] = ft_mtcords(0, 0, 1);
	dir[5] = ft_mtcords(0, 0, -1);
	result = dir[direction];
	return (result);
}
