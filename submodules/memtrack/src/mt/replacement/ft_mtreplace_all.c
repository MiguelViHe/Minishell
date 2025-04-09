/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:33:33 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 09:33:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtreplace_all(t_mt **list, t_mt **replace)
{
	if (!list || !replace || !*list || !*replace)
		return ;
	ft_mtclear(list);
	*list = *replace;
	*replace = NULL;
}
