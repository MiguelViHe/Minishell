/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:51:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/04 11:30:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtdup(t_mt *src)
{
	t_mt	*dst;

	if (!src)
		return (NULL);
	dst = ft_mtnew(src->key, NULL, src->values.data_type);
	if (!dst)
		return (NULL);
	if (src->values.data_type != STRING)
	{
		dst->data = src->data;
		dst->values.to_free = 0;
		dst->free_data = src->free_data;
		return (dst);
	}
	dst->data = ft_strdup(src->data);
	return (dst);
}
