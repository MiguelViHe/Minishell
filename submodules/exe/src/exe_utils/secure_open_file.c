/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_open_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/14 12:27:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
// Open file_name in mode input or output depending of the value of in_out.
int	secure_open(char *file_name, int in_out)
{
	int	fd;

	if (in_out == 0)
		fd = open(file_name, O_RDONLY);
	else if (in_out == 1)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (in_out == 2)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}
