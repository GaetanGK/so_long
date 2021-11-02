/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:35:40 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/17 15:35:47 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_player(t_data *data)
{
	float	new_player_dx;
	float	new_player_dy;

	new_player_dx = 0;
	new_player_dy = 0;
	new_player_dx = data->dy + data->player.walk_side;
	new_player_dy = data->dx + data->player.walk_direction;
	if (!ft_map_has_wall_at(data, new_player_dx, new_player_dy))
	{
		data->player.x = new_player_dx * data->tile_size;
		data->player.y = new_player_dy * data->tile_size;
		ft_move_count(data, new_player_dx, new_player_dy);
		data->dy = new_player_dx;
		data->dx = new_player_dy;
	}
}

void	ft_map_change(t_data *data)
{
	if (data->map[data->dx][data->dy] == 'C')
		data->map[data->dx][data->dy] = '0';
	else if (data->map[data->dx][data->dy] == 'E')
		ft_error(data, "Bye Bye !\n");
}

void	ft_update(t_data *data)
{
	ft_move_player(data);
	ft_map_change(data);
}

int	ft_render(t_data *data)
{
	if (data->win_ptr == 0)
		return (0);
	ft_render_background(data, 0X424242);
	ft_render_map(data);
	ft_render_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	if (data->win_ptr == 0)
		return (0);
	else
		ft_update(data);
	return (0);
}

int	ft_mlx(t_data *data)
{
	ft_verify_errors(data);
	data->tile_size = 32;
	data->window_width = data->tile_size * data->sizeline;
	data->window_height = data->tile_size * data->nblines;
	ft_init(data);
	ft_setup(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask,
		&ft_handle_keyrelease, data);
	mlx_hook(data->win_ptr, DestroyNotify, LeaveWindowMask,
		&ft_handle_destroynotify, data);
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
