/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtcheck_priority.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:28:52 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/28 11:32:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtcheck_priority(t_mt *mt, int priority)
{
	if (!mt)
		return (0);
	return (mt->values.priority - priority);
}
