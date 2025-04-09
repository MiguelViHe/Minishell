/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 17:28:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtremove_data(t_mt *lst, char *key)
{
	t_mt	*current;

	current = lst;
	if (!current || !key)
		return ;
	current = ft_mtsearch_key(current, key);
	if (!current)
		return ;
	ft_mtdel_by_type(&current->data, current->values.data_type);
	current->data = NULL;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtremove(&stacka, "le", ft_strncmp, 2);
// stacka = "miau" -> "guau" -> "mu" -> (NULL) -> "asd" -> "ñe" -> "sa"
