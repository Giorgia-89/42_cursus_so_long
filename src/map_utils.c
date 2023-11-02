/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:58:22 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 15:16:05 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*this function allocates memory for the map, opens the map file and checks
that the fd was correctly created. If so, fd is returned*/
int	ft_map_alloc(char **argv, t_data *data)
{
	int		fd;

	data->map.map = ft_calloc(data->height + 1, sizeof(char *));
	if (data->map.map == NULL)
		ft_print_error(data, 6);
	fd = open(argv[1], O_RDONLY);
	ft_check_fd(fd);
	return (fd);
}

/*this function fills the whole screen with background*/
void	ft_put_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_put_image_to_window(data->mlx, data->win, \
			data->img.background, x, y);
			x += IMG_SIZE;
		}
		y += IMG_SIZE;
	}
}

void	ft_put_images(t_data *data, int new_x, int new_y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img.background, \
	data->p_x * IMG_SIZE, data->p_y * IMG_SIZE);
	data->p_x = new_x;
	data->p_y = new_y;
	mlx_put_image_to_window(data->mlx, data->win, data->img.plyr, \
	data->p_x * IMG_SIZE, data->p_y * IMG_SIZE);
	if (data->map.map[new_y][new_x] == 'C')
	{
		data->map.map[new_y][new_x] = '0';
		data->collected++;
	}
	data->counter++;
}

int	ft_check_char(int x, int y, t_data *data)
{
	if (data->map.map[y][x] != '1' && data->map.map[y][x] != '0' \
	&& data->map.map[y][x] != 'P' && data->map.map[y][x] != 'E' \
	&& data->map.map[y][x] != 'C')
		return (1);
	if (data->map.map[y][x] == 'C')
		data->map.collectible++;
	return (0);
}
