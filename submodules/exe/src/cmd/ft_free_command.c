/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:22:11 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/27 16:31:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "exe_utils.h"

void	free_command(t_command *cmd)
{
	free(cmd->command);
	free(cmd->cmd_path);
	free_cmd_args2d(&(cmd->args));
	free(cmd);
}
