/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:20:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:13:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

// hash function for the hash table
// returns the hash of the key
size_t	ft_mthash(const char *key, size_t bucket_count)
{
	size_t	hash;

	hash = 0;
	while (*key)
		hash = (hash * 31) + *(key++);
	return (hash % bucket_count);
}

// string "hola" -> hash 1234
