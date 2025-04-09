/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_new_original_key.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:45:41 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:04:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*ft_mthash_new_original_key(char *key, t_hash_table *ht)
{
	size_t	i;
	t_mt	*current;
	char	*tmp;

	if (!key || !ht)
		return (NULL);
	i = 0;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		while (current)
		{
			tmp = ft_mtnew_original_key(key, current);
			if (tmp)
				return (tmp);
			current = current->vect[RIGHT];
		}
		i++;
	}
	return (NULL);
}
