/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:06:26 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/19 12:06:34 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->window_height)
	{
		j = 0;
		while (j < data->window_width)
		{
			ft_img_pix_put(&data->img, j++, i, color);
		}
		++i;
	}
}

void	ft_render_map(t_data *data)
{
	int		i;
	int		j;
	int		k;
	t_rect	rect;

	i = 0;
	while (i < data->nblines)
	{
		j = 0;
		while (j < data->sizeline)
		{
			rect.x = j * data->tile_size;
			rect.y = i * data->tile_size;
			rect.width = data->tile_size;
			rect.height = data->tile_size;
			k = ft_text_num(data, i, j);
			ft_render_map_pix(data, rect, k);
			j++;
		}
		i++;
	}
}

void	ft_render_player(t_data *data)
{
	t_rect	player_rect;

	player_rect.x = data->player.x;
	player_rect.y = data->player.y;
	player_rect.width = data->player.width;
	player_rect.height = data->player.height;
	ft_render_map_pix(data, player_rect, 4);
}
