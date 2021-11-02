/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:41:28 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/17 17:41:34 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error(data, "Mlx init impossible\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width,
			data->window_height, "So_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->window_width,
			data->window_height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (1);
}

void	ft_setup(t_data *data)
{
	data->player.x = data->dy * data->tile_size;
	data->player.y = data->dx * data->tile_size;
	data->player.width = data->tile_size;
	data->player.height = data->tile_size;
	data->player.walk_direction = 0;
	data->player.walk_speed = 1;
	data->player.rotation_angle = (3 * MY_PI) / 2;
	data->player.walk_speed = 1;
	data->player.walk_side = 0;
	data->moov_count = 0;
	data->tile_size = 32;
	data->window_width = data->tile_size * data->sizeline;
	data->window_height = data->tile_size * data->nblines;
	ft_get_textures(data);
}
