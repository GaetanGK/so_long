/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:05:12 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/12 12:05:15 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_rectangle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nblines)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->sizeline)
			return (0);
		i++;
	}
	return (1);
}

void	ft_verify_errors(t_data *recup)
{
	if (ft_map_rectangle(recup) == 0)
		ft_error(recup, "La map n´est pas rectangulaire\n");
	if (ft_murs(recup) == 1)
		ft_error(recup, "Map non entouree de 1\n");
	if (recup->depart == 'x')
		ft_error(recup, "Pas de joueur\n");
	if (recup->multijoueurs == 1)
		ft_error(recup, "Plus d'un joueur\n");
	if (recup->lignevide == 1)
		ft_error(recup, "Ligne vide dans la map\n");
	if (recup->wrongcharmap == 2)
		ft_error(recup, "Caractere incorrect dans la map\n");
	if (ft_c_e_ckeck(recup, 'C') == 0)
		ft_error(recup, "Pas de collectible\n");
	if (ft_c_e_ckeck(recup, 'E') == 0)
		ft_error(recup, "Pas d´ Exit\n");
}

void	ft_error(t_data *recup, char *str)
{
	int	i;

	i = -1;
	recup->indicateur3 = 1;
	if (str[0] != 'B')
		write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (recup->map)
	{
		while (++i < recup->nblines)
			free(recup->map[i]);
	}
	if (recup->map)
		free(recup->map);
	ft_exit(recup);
}

int	ft_exit(t_data *recup)
{
	if (recup->indicateur3 == 0)
		ft_error(recup, "Exit");
	if (recup->img.mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->img.mlx_img);
	if (recup->texture[0].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[0].mlx_img);
	if (recup->texture[1].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[1].mlx_img);
	if (recup->texture[2].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[2].mlx_img);
	if (recup->texture[3].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[3].mlx_img);
	if (recup->texture[4].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[4].mlx_img);
	if (recup->win_ptr)
		mlx_destroy_window(recup->mlx_ptr, recup->win_ptr);
	exit(0);
}
