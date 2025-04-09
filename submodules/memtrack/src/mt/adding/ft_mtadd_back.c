/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:09:56 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:09:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list, in the BACK direction.

void	ft_mtaddlast_back(t_mt **lst, t_mt *new)
{
	if (!lst || !new)
		return ;
	ft_mtaddlast(lst, new, BACK);
}
