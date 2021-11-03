/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:45:21 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/17 17:45:29 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_handle_keypress(int keysym, t_data *data)
{
	if (data->count2 == 0)
	{
		if (keysym == XK_Escape)
			ft_error(data, "Bye Bye !\n");
		if (keysym == XK_w || keysym == XK_W)
			data->player.walk_direction = -1;
		else if (keysym == XK_z || keysym == XK_Z)
			data->player.walk_direction = -1;
		else if (keysym == XK_s || keysym == XK_S)
			data->player.walk_direction = +1;
		else if (keysym == XK_d || keysym == XK_D)
			data->player.walk_side = +1;
		else if (keysym == XK_a || keysym == XK_A || keysym == XK_q
			|| keysym == XK_Q)
			data->player.walk_side = -1;
	}
	return (0);
}

int	ft_handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_z || keysym == XK_W
		|| keysym == XK_Z)
		data->player.walk_direction = 0;
	else if (keysym == XK_s || keysym == XK_S)
		data->player.walk_direction = 0;
	else if (keysym == XK_d || keysym == XK_D)
		data->player.walk_side = 0;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_q
		|| keysym == XK_Q)
		data->player.walk_side = 0;
	data->count2 = 0;
	return (0);
}

int	ft_handle_destroynotify(t_data *data)
{
	ft_error(data, "Bye Bye !\n");
	return (0);
}
