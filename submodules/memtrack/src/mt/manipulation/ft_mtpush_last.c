/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:40:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/28 09:40:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtpush_last(t_mt **dst, t_mt **src, t_direction direction)
{
	t_mt	*sub;

	if (!dst || !src || !(*src))
		return ;
	sub = NULL;
	sub = ft_mtsub(src, (*src));
	if (!sub)
		return ;
	ft_mtaddlast(dst, sub, direction);
}
