/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_count_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:30:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:04:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static size_t	ft_count_in_children(t_mt *parent, const char *key)
{
	t_mt	*child;
	size_t	result;

	child = (t_mt *)parent->data;
	result = 0;
	while (child)
	{
		if (ft_mtcmp_key(child, key, ft_strlen(key)))
			result += 1;
		if (child->values.node_type == BRANCH)
		{
			result += ft_count_in_children(child, key);
			if (result)
				return (result);
		}
		child = child->vect[RIGHT];
	}
	return (result);
}

size_t	ft_mtcount_key_mt(t_mt *root, const char *key)
{
	size_t	count;

	if (!root || !key)
		return (0);
	count = 0;
	if (ft_mtcmp_key(root, key, ft_strlen(key)))
		count++;
	if (root->values.node_type == BRANCH)
		count += ft_count_in_children(root->data, key);
	return (count);
}

size_t	ft_mtcount_key_list(t_mt *head, const char *key)
{
	size_t	count;

	if (!head || !key)
		return (0);
	count = 0;
	while (head)
	{
		count += ft_mtcount_key_mt(head, key);
		head = head->vect[RIGHT];
	}
	return (count);
}

size_t	ft_mthash_count_key(t_hash_table *ht, const char *key)
{
	size_t	i;
	t_mt	*current;
	size_t	count;

	if (!ht || !key)
		return (0);
	i = 0;
	count = 0;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		count += ft_mtcount_key_list(current, key);
		i++;
	}
	return (count);
}
