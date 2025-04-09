/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_cords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:14:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/03 05:21:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtsearch_cords - Busca un nodo por sus coordenadas.
 *
 * Retorna el nodo encontrado o NULL si no lo encuentra.
 */

static int	match_cords(t_mt *node, void *cords)
{
	if (ft_cordscmp(node->cords, *(t_cords *)(cords)) == 0)
		return (1);
	return (0);
}

t_mt	*ft_mtsearch_cords(t_mt *node, t_cords cords)
{
	t_mt	*found;

	if (!node)
		return (NULL);
	found = ft_mtsearch(node, &cords, match_cords);
	return (found);
}
