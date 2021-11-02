/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:47:07 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/19 15:47:14 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_normalize_angle(float *angle)
{
	*angle = remainder(*angle, MY_TWO_PI);
	if (*angle < 0)
	{
		*angle = *angle + MY_TWO_PI;
	}
}

int	ft_map_has_wall_at(t_data *data, float x, float y)
{
	int	map_grid_x;
	int	map_grid_y;

	if (x < 0 || x >= data->sizeline || y < 0
		|| y >= data->nblines)
		return (1);
	map_grid_x = x;
	map_grid_y = y;
	return (data->map[map_grid_y][map_grid_x] == '1');
}

void	ft_textures_path(t_data *data)
{
	data->e_s = "./textures/e_s.xpm";
	data->w = "./textures/w.xpm";
	data->c = "./textures/c.xpm";
	data->e = "./textures/e.xpm";
	data->p = "./textures/p.xpm";
}

void	ft_get_textures_adress(t_data *data)
{
	data->texture[0].addr = mlx_get_data_addr(data->texture[0].mlx_img,
			&data->texture[0].bpp, &data->texture[0].line_len,
			&data->texture[0].endian);
	data->texture[1].addr = mlx_get_data_addr(data->texture[1].mlx_img,
			&data->texture[1].bpp, &data->texture[1].line_len,
			&data->texture[1].endian);
	data->texture[2].addr = mlx_get_data_addr(data->texture[2].mlx_img,
			&data->texture[2].bpp, &data->texture[2].line_len,
			&data->texture[2].endian);
	data->texture[3].addr = mlx_get_data_addr(data->texture[3].mlx_img,
			&data->texture[3].bpp, &data->texture[3].line_len,
			&data->texture[3].endian);
	data->texture[4].addr = mlx_get_data_addr(data->texture[4].mlx_img,
			&data->texture[4].bpp, &data->texture[4].line_len,
			&data->texture[4].endian);
}

void	ft_get_textures(t_data *data)
{
	ft_textures_path(data);
	data->texture[0].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->e_s,
			&(data->texture[0].width), &(data->texture[0].height));
	if (data->texture[0].mlx_img == NULL)
		ft_error(data, "Texture empty space\n");
	data->texture[1].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->w,
			&(data->texture[1].width), &(data->texture[1].height));
	if (data->texture[1].mlx_img == NULL)
		ft_error(data, "Texture wall\n");
	data->texture[2].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->e,
			&(data->texture[2].width), &(data->texture[2].height));
	if (data->texture[2].mlx_img == NULL)
		ft_error(data, "Texture exit\n");
	data->texture[3].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->c,
			&(data->texture[3].width), &(data->texture[3].height));
	if (data->texture[3].mlx_img == NULL)
		ft_error(data, "Texture Collectibles\n");
	data->texture[4].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->p,
			&(data->texture[4].width), &(data->texture[4].height));
	if (data->texture[4].mlx_img == NULL)
		ft_error(data, "Texture Player\n");
	ft_get_textures_adress(data);
}
