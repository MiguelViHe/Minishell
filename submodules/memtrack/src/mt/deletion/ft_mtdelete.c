/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdelete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:15:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdelete(t_mt **mt)
{
	if (!mt || !*mt)
		return ;
	if ((*mt)->data)
		ft_mtdel_by_type(&(*mt)->data, (*mt)->values.data_type);
	if ((*mt)->aux)
		ft_mtclear(&(*mt)->aux);
	if ((*mt)->key)
		free((*mt)->key);
	free((*mt));
	(*mt) = NULL;
}
