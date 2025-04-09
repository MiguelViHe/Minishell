/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtexchange_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:14:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/20 13:09:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/*
It exchanges the position of the current node with the node in the direction
specified. If the current node is the root or the node in the direction is the
root, it swaps the root with the node in the opposite direction.
*/
int	ft_mtexchange_dir(t_mt **lst, t_mt *cur, t_direction direction)
{
	t_mt	*prev;
	t_mt	*next;
	t_mt	*n_direc;
	int		oposite;

	if (!cur || !cur->vect[direction])
		return (1);
	n_direc = cur->vect[direction];
	if (*lst == cur || *lst == n_direc)
		ft_mtswap(lst, RIGHT);
	else
	{
		oposite = ft_mtoposite_direction(direction);
		next = n_direc->vect[direction];
		prev = cur->vect[oposite];
		cur->vect[direction] = next;
		n_direc->vect[direction] = cur;
		n_direc->vect[oposite] = prev;
		cur->vect[oposite] = n_direc;
		if (prev)
			prev->vect[direction] = n_direc;
		if (next)
			next->vect[oposite] = cur;
	}
	return (0);
}
