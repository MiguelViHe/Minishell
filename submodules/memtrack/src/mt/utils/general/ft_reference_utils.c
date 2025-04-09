/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reference_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:10:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:42:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtupdate_ref(t_mt **ref, t_mt *node)
{
	int	i;

	i = 0;
	if (*ref == node)
	{
		while (i < MAX_DIRECTIONS)
		{
			if (node->vect[i])
			{
				*ref = node->vect[i];
				return ;
			}
			i++;
		}
		*ref = NULL;
	}
}
