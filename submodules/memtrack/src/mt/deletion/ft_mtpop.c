/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/04 21:17:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the first element of the list.
void	ft_mtpop(t_mt **lst)
{
	t_mt	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	ft_mtremove(lst, tmp);
}
