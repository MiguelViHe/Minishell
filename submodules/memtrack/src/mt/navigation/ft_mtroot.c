/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtroot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:50:34 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 13:17:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_first_parent - Returns the first parent node of the list.
 * @lst: List of nodes.
 * Return: The first parent node of the list.
 */

static int	match_root(t_mt *mt, void *param)
{
	(void)param;
	if (mt->values.node_type == ROOT)
		return (1);
	return (0);
}

t_mt	*ft_mtroot(t_mt *lst)
{
	if (!lst)
		return (NULL);
	return (ft_mtsearch(lst, NULL, match_root));
}
