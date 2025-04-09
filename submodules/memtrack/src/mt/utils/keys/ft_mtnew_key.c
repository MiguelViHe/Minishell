/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:48:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 09:42:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*ft_mtnew_key(char *prefix, char *suffix)
{
	char	*new_key;

	if (!prefix || !suffix)
		return (NULL);
	new_key = ft_strjoin(prefix, suffix);
	return (new_key);
}
