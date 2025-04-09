/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:23:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:46:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtreverse_rotate(t_mt **lst, t_direction direction)
{
	t_mt	*last;
	t_mt	*sub;
	int		oposite;

	if (!(*lst) || !lst)
		return ;
	last = NULL;
	last = ft_mtlast((*lst), direction);
	if (!last)
		return ;
	sub = NULL;
	sub = ft_mtsub(lst, last);
	if (!sub)
		return ;
	oposite = ft_mtoposite_direction(direction);
	ft_mtaddfirst(lst, sub, oposite);
}
