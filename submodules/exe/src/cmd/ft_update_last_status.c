/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_last_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:04:58 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/02/26 19:10:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
/*
Actualiza el estado de salida del último proceso hijo que terminó.
Devuelve el estado de salida del proceso hijo.

if (WIFEXITED(status)) // El proceso terminó normalmente
else if (WIFSIGNALED(status)) // El proceso fue terminado por una señal
return (128 + WTERMSIG(status)); // Suma 128 al número de la señal
return (1); // Caso genérico de error inesperado
*/
int	update_last_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (1);
}
