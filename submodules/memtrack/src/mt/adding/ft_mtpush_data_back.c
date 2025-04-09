/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:13:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:07:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'data' at the end of the list.
void	ft_mtpush_data_right(t_mt **lst, const char *key, void *data,
		t_data_type type)
{
	t_mt	*new;

	if (!lst)
		return ;
	new = ft_mtnew(key, data, type);
	if (!new)
		return ;
	ft_mtaddlast_right(lst, new);
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpush_data_right(&stacka, "pi");
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> "pi"
