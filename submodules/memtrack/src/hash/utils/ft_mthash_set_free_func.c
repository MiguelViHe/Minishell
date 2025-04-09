/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_set_free_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:03:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/04 10:05:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_set_free_func(t_hash_table *ht, char *key,
		void (*free_func)(void **))
{
	t_mt	*node;

	node = ht->methods.search(ht, key);
	if (node)
		ft_mtset_free_func(node, free_func);
}
