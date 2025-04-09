/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:19:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtsize(t_mt *node)
{
	int	size;
	int	i;

	if (!node)
		return (0);
	i = 0;
	size = 1;
	while (i < MAX_DIRECTIONS)
		size += ft_mtsize(node->vect[i++]);
	return (size);
}
