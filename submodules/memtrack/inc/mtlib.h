/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:24 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:22:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTLIB_H
# define MTLIB_H

# include "libft.h"
# include "mtstructs.h"

// Function declarations and other definitions for the mtlib library

void	freedom(void **data);
t_mt	*ft_splitmt(const char *s, char c);

#endif // MTLIB_H