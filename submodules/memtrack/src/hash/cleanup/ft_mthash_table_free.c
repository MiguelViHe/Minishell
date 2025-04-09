/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_table_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:08:22 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 13:19:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// libera la tabla hash
void	ft_mthash_table_free(void **ht)
{
	t_mt			*current;
	t_hash_table	*tmp;
	size_t			i;

	if (!ht)
		return ;
	i = 0;
	tmp = (t_hash_table *)*ht;
	while (i < tmp->bucket_count)
	{
		current = tmp->buckets[i];
		ft_mtclear(&current);
		i++;
	}
	free(tmp->buckets);
	free(tmp);
	tmp = NULL;
	*ht = NULL;
}
// si funciona
