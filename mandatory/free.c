/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:36:37 by abourdon          #+#    #+#             */
/*   Updated: 2023/03/01 11:52:08 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}

void	freechild(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->options[i])
	{
		free(pipex->options[i]);
		i++;
	}
	free(pipex->options);
	free(pipex->cmd);
}

void	end_pipeprocess(t_pipex *pipex)
{
	if (close(pipex->tube[0]) == -1)
		msg_perror("close Error\n");
	if (close(pipex->tube[1]) == -1)
		msg_perror("close Error\n");
}

void	freexit(t_pipex pipex)
{
	parent_free(&pipex);
	exit(EXIT_FAILURE);
}
