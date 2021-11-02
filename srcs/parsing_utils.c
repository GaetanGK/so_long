/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:38:51 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/11 10:38:53 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_murs_util(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	ft_initialisation(t_data *data)
{
	data->map = NULL;
	data->depart = 'x';
	data->nblines = 0;
	data->sizeline = 0;
	data->dx = 0;
	data->dy = 0;
	data->lignevide = 0;
	data->img.mlx_img = NULL;
	data->texture[0].mlx_img = NULL;
	data->texture[1].mlx_img = NULL;
	data->texture[2].mlx_img = NULL;
	data->texture[3].mlx_img = NULL;
	data->win_ptr = NULL;
	data->e_s = NULL;
	data->w = NULL;
	data->c = NULL;
	data->e = NULL;
	data->p = NULL;
	data->wrongcharmap = 0;
	data->insidemap = 0;
	data->indicateur3 = 0;
	data->multijoueurs = 0;
}

int	ft_lignevide(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
			&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_depart(char c, t_data *data, int i, int j)
{
	if (c == 'P')
	{
		if (data->depart != 'x')
			data->multijoueurs = 1;
		data->depart = c;
		data->dx = i;
		data->dy = j;
		return (1);
	}
	return (0);
}
