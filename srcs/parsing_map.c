/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:59:38 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/13 09:59:40 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_murs(t_data *recup)
{
	int	i;

	i = 0;
	while (i < recup->nblines)
	{
		if (recup->map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < recup->nblines)
	{
		if (recup->map[i][recup->sizeline - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	if (ft_murs_util(recup->map[0]) == 1)
		return (1);
	if (ft_murs_util(recup->map[recup->nblines - 1]) == 1)
		return (1);
	return (0);
}

int	ft_c_e_ckeck(t_data *recup, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < recup->nblines)
	{
		j = 0;
		while (j < recup->sizeline)
		{
			if (recup->map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_copy_map(char *str, t_data *recup)
{
	static int	i = 0;
	int			j;

	j = 0;
	recup->map[i] = NULL;
	recup->map[i] = malloc(sizeof(char) * recup->sizeline + 1);
	if (recup->map[i] == NULL)
		return (0);
	while (str[j] != '\0')
	{
		if (ft_depart(str[j], recup, i, j) == 1)
			recup->map[i][j] = '0';
		else
			recup->map[i][j] = str[j];
		j++;
	}
	recup->map[i][j] = '\0';
	i++;
	return (0);
}

int	ft_is_map(char *str, t_data *recup)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
				&& str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
			{
				recup->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	recup->wrongcharmap = 2;
	return (0);
}

void	ft_map(char *str, t_data *recup)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, recup) == 1)
	{
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	recup->nblines = snblines;
	recup->sizeline = ssizeline;
}
