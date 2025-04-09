/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/20 13:05:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

//Makes father process waiting for the children to ensure that all of them 
//finish correctly and avoid zombies process.
int	process_pipe_father(int pfd[2], int num_children, t_env *env)
{
	int	i;
	int	status;
	int	last_exit_status;

	close(pfd[0]);
	close(pfd[1]);
	i = 0;
	while (i < num_children)
	{
		if (wait(&status) == -1)
			return (perror("wait"), env->last_status = 1, 1);
		if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT
				|| WTERMSIG(status) == SIGQUIT))
			write(1, "\n", 1);
		last_exit_status = update_last_status(status);
		i++;
	}
	env->last_status = last_exit_status;
	return (0);
}

void	process_left_child(int pfd[2], t_mt *node, t_env *env)
{
	close(pfd[0]);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	ft_execute_tree(node->vect[LEFT], env, 1);
	exit(0);
}

void	process_right_child(int pfd[2], t_mt *node, t_env *env)
{
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	ft_execute_tree(node->vect[RIGHT], env, 1);
	exit(0);
}

void	perror_and_exit(char *msg)
{
	perror(msg);
	exit(1);
}

int	execute_pipe(t_mt *node, t_env *env)
{
	int		pfd[2];
	pid_t	pid_left;
	pid_t	pid_right;

	if (pipe(pfd) == -1)
		perror_and_exit("pipe");
	pid_left = fork();
	if (pid_left == -1)
		perror_and_exit("fork");
	if (pid_left == 0)
		process_left_child(pfd, node, env);
	pid_right = fork();
	if (pid_right == -1)
		perror_and_exit("fork");
	if (pid_right == 0)
		process_right_child(pfd, node, env);
	return (process_pipe_father(pfd, 2, env));
}
