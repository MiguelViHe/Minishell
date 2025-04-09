/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:14:42 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/13 12:39:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @brief rotate the first node to behind the last node of the direction
 *
 *
 */

void	ft_mtrotate(t_mt **lst, t_direction direction)
{
	t_mt	*sub;

	if (!(*lst) || !lst)
		return ;
	sub = NULL;
	sub = ft_mtsub(lst, (*lst));
	if (!sub)
		return ;
	ft_mtaddlast(lst, sub, direction);
	ft_mtupdate_cords((*lst), ft_mtcords(0, 0, 0));
}
