/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcheck_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:16:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/10 18:55:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcheck_key(t_mt *mt, char *key)
{
	if (!mt)
		return (-1);
	return (ft_strncmp(mt->key, key, ft_strlen(key)));
}
