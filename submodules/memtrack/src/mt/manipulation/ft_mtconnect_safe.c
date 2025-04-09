/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtconnect_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:22:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:46:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_mtconnect_neighbours(t_mt ***neighbours, t_mt *new)
{
	t_mt	*neighbour;
	int		direction;

	direction = 0;
	neighbour = 0;
	while (direction < MAX_DIRECTIONS)
	{
		neighbour = (*neighbours)[direction];
		if (neighbour)
		{
			ft_mtaddlast(&new, neighbour, direction);
			(*neighbours)[direction] = NULL;
		}
		direction++;
	}
}

static void	ft_mtget_neighbourds(t_mt *lst, t_mt ***neighbours,
		t_direction direction)
{
	int	i;

	i = 0;
	while (i < MAX_DIRECTIONS)
	{
		if (i != ft_mtoposite_direction(direction))
		{
			(*neighbours)[i] = lst->vect[i];
			if ((*neighbours)[i])
				ft_mtdisconnect(lst, i);
		}
		i++;
	}
}

void	ft_mtconnect_safe(t_mt **lst, t_mt *new, t_direction direction)
{
	t_mt	**neighbours;
	int		i;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	neighbours = malloc(sizeof(t_mt *) * MAX_DIRECTIONS);
	if (!neighbours)
		return ;
	i = -1;
	while (++i < MAX_DIRECTIONS)
		neighbours[i] = 0;
	ft_mtget_neighbourds(*lst, &neighbours, direction);
	ft_mtaddlast(lst, new, direction);
	ft_mtconnect_neighbours(&neighbours, new);
	free(neighbours);
}
