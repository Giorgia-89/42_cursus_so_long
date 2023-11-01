/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:22:33 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 14:32:47 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_error(char *error)
{
	ft_printf("Error\n%s", error);
	return (-1);
}

/*this function checks that the map is surrounded by 1s on all sides*/
int	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->height / IMG_SIZE))
	{
		if ((int)ft_strlen(data->map.map[y]) != data->width / IMG_SIZE)
			return (ft_map_error("All rows must have the same length\n"));
		x = 0;
		while (x < (data->width / IMG_SIZE))
		{
			if ((y == 0 || x == 0) && data->map.map[y][x] != '1')
				return (ft_map_error("Map must be surrounded by walls\n"));
			else if ((y == (data->height / IMG_SIZE - 1) || \
			x == (data->width / IMG_SIZE - 1)) && data->map.map[y][x] != '1')
				return (ft_map_error("Map must be surrounded by walls\n"));
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_requisites(int collectible, int player, int exit)
{
	if (player != 1)
	{
		ft_printf("Error\nMap must contain one player\n");
		return (-1);
	}
	else if (exit != 1)
	{
		ft_printf("Error\nMap must contain one exit\n");
		return (-1);
	}
	if (collectible < 1)
	{
		ft_printf("Error\nMap must contain one player\n");
		return (-1);
	}
	return (0);
}

/*this function takes as argument the data structure and checks that it
contains only valid chars. Valid chars are 0, 1, P, E, C; P and E are
initialised here and passed to count function to cut down lines*/
int	ft_check_contents(t_data *data)
{
	int	y;
	int	x;
	int	plyr;
	int	exit;

	plyr = 0;
	exit = 0;
	x = 1;
	data->map.collectible = 0;
	while (x < data->width / IMG_SIZE - 1)
	{
		y = 1;
		while (y < data->height / IMG_SIZE - 1)
		{
			if (data->map.map[y][x] != '1' && data->map.map[y][x] != '0' \
			&& data->map.map[y][x] != 'P' && data->map.map[y][x] != 'E' \
			&& data->map.map[y][x] != 'C')
				return (ft_printf("Error\nMap contains invalid characters\n"));
			else if (data->map.map[y][x] == 'C')
				data->map.collectible++;
			y++;
		}
		x++;
	}
	return (ft_count_requisites(data, plyr, exit));
}
