/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:08:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:08:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the beginning of the list, in the UP direction.

void	ft_mtaddlast_up(t_mt **lst, t_mt *new)
{
	if (!lst || !new)
		return ;
	ft_mtaddlast(lst, new, UP);
}
