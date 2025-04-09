/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:31:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 11:58:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the data and the node of the list.
void	freedom(void **data)
{
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}
