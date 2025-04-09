/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpoplast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:59:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtpoplast(t_mt **lst, t_direction direction)
{
	t_mt	*tmp;

	if (!*lst)
		return ;
	tmp = ft_mtlast(*lst, direction);
	ft_mtremove(lst, tmp);
}
