/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:08:34 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:08:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list.

void	ft_mtaddlast_right(t_mt **lst, t_mt *new)
{
	if (!lst || !new)
		return ;
	ft_mtaddlast(lst, new, RIGHT);
}
