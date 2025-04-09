/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:28:12 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/25 14:32:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "global_signal.h"

static int	error_here_doc(char *msg, char *buffer, t_env *env)
{
	perror(msg);
	free(buffer);
	return (env->last_status = 1, 1);
}

static void	close_here_doc(int fdhd[2], char *buffer)
{
	free(buffer);
	close(fdhd[WRITE_END]);
}

static int	dup_heredoc_stdin(int fdhd[2], t_env *env)
{
	if (dup2(fdhd[READ_END], STDIN_FILENO) == -1)
		return (ft_error("Error redirecting standard input.\n", 0), -1);
	env->redirect.is_red_in = 1;
	close(fdhd[READ_END]);
	return (env->last_status = 0, 0);
}

int	exit_sigint_here_doc(int fdhd[2], t_env *env)
{
	g_sig_received = 0;
	close(fdhd[WRITE_END]);
	return (env->last_status = 130, 1);
}

int	redirect_heredoc(t_mt *node, t_env *env)
{
	int		fdhd[2];
	char	*bf;

	restore_stdin(env);
	if (pipe(fdhd) == -1)
		return (-1);
	while (1)
	{
		bf = advanced_readline("> ");
		if (!bf)
		{
			if (g_sig_received == SIGINT)
				return (exit_sigint_here_doc(fdhd, env));
			(ft_printf(SYNTAX_ERROR4, node->aux->key), close(fdhd[WRITE_END]));
			return (dup_heredoc_stdin(fdhd, env));
		}
		if (!ft_pmatch_str(bf, node->aux->key, ft_strlen(node->aux->key)))
			return (close_here_doc(fdhd, bf), dup_heredoc_stdin(fdhd, env), 0);
		bf = ft_expand(bf, ft_check_eof(node->aux->key), env, 1);
		if (write(fdhd[WRITE_END], bf, ft_strlen(bf)) != (ssize_t)ft_strlen(bf)
			|| write(fdhd[WRITE_END], "\n", 1) != 1)
			return (error_here_doc("Error writing heredoc", bf, env));
		free(bf);
	}
}
