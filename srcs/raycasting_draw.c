/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:10:57 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/19 12:11:06 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	if (y <= 0)
		y = 1;
	else if (x <= 0)
		x = 1;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	ft_draw_line(t_img *img, t_line	line)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = line.end_x - line.begin_x;
	delta_y = line.end_y - line.begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line.begin_x;
	pixel_y = line.begin_y;
	while (pixels)
	{
		ft_img_pix_put(img, pixel_x, pixel_y, line.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}

int	ft_text_num(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		return (1);
	else if (data->map[i][j] == 'C')
		return (3);
	else if (data->map[i][j] == 'E')
		return (2);
	else
		return (0);
}

int	ft_render_map_pix(t_data *data, t_rect rect, int m)
{
	int		k;
	int		l;
	char	*pixel;

	k = rect.y;
	while (k < rect.y + rect.height)
	{
		l = rect.x;
		while (l < rect.x + rect.width)
		{
			pixel = data->texture[m].addr + ((k % (int)data->tile_size)
					* data->texture[m].line_len + (l % (int)data->tile_size)
					* (data->texture[m].bpp / 8));
			ft_img_pix_put(&data->img, ++l, k, *(int *)pixel);
		}
		++k;
	}
	return (0);
}

void	ft_move_count(t_data *data, int new_player_dx, int new_player_dy)
{
	if (data->dy != new_player_dx || data->dx != new_player_dy)
	{
		data->moov_count += fabs((double) data->player.walk_side)
			+ fabs((double) data->player.walk_direction);
		printf("%d\n", data->moov_count);
	}
}
