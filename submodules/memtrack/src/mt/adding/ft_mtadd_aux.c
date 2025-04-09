/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:10:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:10:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtaddlast_aux(t_mt *node, t_mt *aux)
{
	if (!node || !aux)
		return ;
	if (node->aux)
		ft_mtaddlast_right(&node->aux, aux);
	else
		node->aux = aux;
}
