/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_count_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:42:05 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:44:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mthash_count_type - Cuenta nodos de un tipo específico en la tabla hash.
 * @ht: Tabla hash en la que buscar.
 * @type: Tipo de dato que se desea contar.
 *
 * Return: Cantidad de nodos que son del tipo especificado.
 */

int	ft_mthash_count_data_type(t_hash_table *ht, t_data_type type)
{
	size_t	i;
	int		count;

	if (!ht)
		return (0);
	i = 0;
	count = 0;
	while (i < ht->bucket_count)
	{
		count += ft_mtcount_data_type(ht->buckets[i], type);
		i++;
	}
	return (count);
}

int	ft_mthash_count_node_type(t_hash_table *ht, t_node_type type)
{
	size_t	i;
	int		count;

	if (!ht)
		return (0);
	i = 0;
	count = 0;
	while (i < ht->bucket_count)
	{
		count += ft_mtcount_node_type(ht->buckets[i], type);
		i++;
	}
	return (count);
}
