/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:51:53 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 09:37:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtpush_data(t_mt **lst, const char *key, void *data,
		t_data_type type)
{
	t_mt	*new;

	if (!data || !lst)
		return ;
	new = ft_mtnew(key, data, type);
	if (!new)
	{
		ft_mtdel_by_type(&data, type);
		return ;
	}
	ft_mtaddfirst(lst, new, LEFT);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpush_data(&stacka, ["pi"]);
// stacka = ["pi"] -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
