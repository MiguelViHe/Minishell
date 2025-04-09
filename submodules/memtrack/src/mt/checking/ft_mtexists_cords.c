/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtexists_cords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:25:54 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/03 05:26:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtexists_cords - Comprueba si un nodo existe con las coordenadas dadas.
 *
 * Retorna 1 si el nodo existe, 0 si no.
 */

int	ft_mtexists_cords(t_mt *node, t_cords cords)
{
	if (ft_mtsearch_cords(node, cords))
		return (1);
	return (0);
}
