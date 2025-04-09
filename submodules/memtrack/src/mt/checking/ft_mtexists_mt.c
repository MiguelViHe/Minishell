/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtexists_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:33:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:07:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns 1 if the node with the key 'key' exists in the list 'lst'.
int	ft_mtexists_mt(t_mt *root, const char *key)
{
	t_mt	*current;

	if (!root || !key)
		return (0);
	current = ft_mtsearch_key(root, key);
	if (!current)
		return (0);
	return (1);
}
