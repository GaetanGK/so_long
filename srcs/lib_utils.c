/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:08:37 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/12 12:08:38 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_dir_rony_check(char *fichier, t_data *recup)
{
	int	fd;

	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_error(recup, "Invalide : is a directory\n");
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Fichier .ber invalide\n");
	return (fd);
}

void	ft_map_copy(t_data *recup, char *str)
{
	if (recup->insidemap == 1)
	{
		recup->count++;
		ft_copy_map(str, recup);
	}
}

int	ft_gnl_cpy(int ret, char *buff, char **line)
{
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!ft_copy(line, &buff))
			return (1);
	}
	return (0);
}
