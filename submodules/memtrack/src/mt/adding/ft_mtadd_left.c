/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:09:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:09:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the beginning of the list.

void	ft_mtaddlast_left(t_mt **lst, t_mt *new)
{
	if (!lst || !new)
		return ;
	ft_mtaddlast(lst, new, LEFT);
}
