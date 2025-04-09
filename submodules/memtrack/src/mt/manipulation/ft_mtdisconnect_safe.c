/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdisconnect_safe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/31 14:36:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtdisconnect_safe - Disconnects a node and reconnects the
 * opposites.
 *
 * @ref: Reference to the tree.
 * @node: Node to disconnect.
 *
 * Returns the node disconnected.
 */

static int	ft_is_all_connected(t_mt **neighbours, t_mt **ref)
{
	int		i;
	t_mt	*neighbour;

	if (!neighbours || !ref)
		return (0);
	i = 0;
	while (i < MAX_DIRECTIONS)
	{
		neighbour = neighbours[i];
		if (neighbour && !ft_mtis_connected(ref, neighbour))
			return (0);
		i++;
	}
	return (1);
}

static t_mt	*ft_get_nearly_avalible_neighbour(t_mt **neighbours,
		t_direction *direction)
{
	int		oposite;
	t_mt	*neighbour;

	(*direction) = 0;
	neighbour = NULL;
	while ((*direction) < MAX_DIRECTIONS)
	{
		neighbour = neighbours[(*direction)];
		oposite = ft_mtoposite_direction((*direction));
		if (neighbour && !neighbour->vect[oposite])
			return (neighbour);
		(*direction)++;
	}
	return (NULL);
}

static int	ft_mtadd_posible_neighbour(t_mt **neighbours, t_mt *node)
{
	t_mt	*neighbour;
	int		i;
	int		oposite;

	if (!node)
		return (0);
	i = -1;
	oposite = 0;
	while (++i < MAX_DIRECTIONS)
	{
		neighbour = neighbours[i];
		if (neighbour && neighbour != node)
		{
			oposite = ft_mtoposite_direction(i);
			if (!neighbour->vect[oposite] && !node->vect[i])
				return (ft_mtaddlast(&neighbour, node, oposite), 1);
			else if (!neighbour->vect[i] && !node->vect[oposite])
				return (ft_mtaddlast(&neighbour, node, i), 1);
		}
	}
	return (0);
}

static void	ft_mtreconnect_neighbours(t_mt **neighbours, t_mt **ref)
{
	t_direction	direction;
	t_mt		*avalible_neighbour;

	direction = 0;
	avalible_neighbour = NULL;
	while (direction < MAX_DIRECTIONS)
	{
		avalible_neighbour = ft_get_nearly_avalible_neighbour(neighbours,
				&direction);
		ft_mtadd_posible_neighbour(neighbours, avalible_neighbour);
		if (ft_is_all_connected(neighbours, ref))
			break ;
	}
}

t_mt	*ft_mtdisconnect_safe(t_mt **ref, t_mt *node)
{
	int		i;
	t_mt	**neighbours;

	if (!ref || !*ref || !node)
		return (NULL);
	i = -1;
	neighbours = ft_calloc(MAX_DIRECTIONS, sizeof(t_mt *));
	ft_mtupdate_ref(ref, node);
	while (++i < MAX_DIRECTIONS)
	{
		neighbours[i] = node->vect[i];
		ft_mtdisconnect(node, i);
	}
	if (ft_is_all_connected(neighbours, ref))
		return (free(neighbours), node);
	ft_mtreconnect_neighbours(neighbours, ref);
	return (free(neighbours), node);
}
