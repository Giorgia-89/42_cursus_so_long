/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:48:29 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 15:07:43 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*This function opens the map file, checks if the input map is valid, and if
so it counts the number of rows and columns and places them in structure*/
void	ft_get_size(t_data *data, char **argv)
{
	int	fd;

	if (!(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))))
	{
		ft_printf("Error\nMap must be in .ber format\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	ft_check_fd(fd);
	data->width = ft_linelen(fd) * IMG_SIZE;
	data->height = ft_countlines(fd) * IMG_SIZE;
	check_dim(data->width, data->height, fd);
}

/*this function transforms the .ber map into a 2-d array of characters.
It takes as arguments the map and the data structure. It creates a fd to
read byte by byte the mapfile until the end of the buffer;
chars are gradually joined together to form each row (data->map.map).
Every time a newline is encountered, the row of the matrix increases.
Use buffer size 2 to include null char at the end*/
int	ft_parse_map(char **argv, t_data *data)
{
	int		fd;
	char	buffer[2];
	int		byte;
	int		i;

	fd = ft_map_alloc(argv, data);
	buffer[1] = '\0';
	byte = 1;
	i = 0;
	while (byte == 1)
	{
		byte = read(fd, buffer, 1);
		if (byte != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			data->map.map[i] = ft_strjoin(data->map.map[i], buffer);
		else
			i++;
	}
	close(fd);
	if (ft_check_borders(data) == -1 || ft_check_contents(data) == -1)
		return (-1);
	return (0);
}

/* this function puts the player in the current position and updates
the player position in the structure*/
void	ft_put_player(t_data *data)
{
	data->p_x = data->map.x;
	data->p_y = data->map.y;
	mlx_put_image_to_window(data->mlx, data->win, data->img.plyr, \
	(data->p_x * IMG_SIZE), (data->p_y * IMG_SIZE));
}

/*this function puts the given object to the current position */
void	ft_put_object(t_data *data, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img, \
	(data->map.x * IMG_SIZE), (data->map.y * IMG_SIZE));
}

/*this function goes through the map char by char, calling the function
to place in the map the corresponding object*/
void	ft_draw_map(t_data *data)
{
	data->map.x = 0;
	data->map.y = 0;
	while (data->map.y < (data->height / IMG_SIZE))
	{
		if (data->map.map[data->map.y][data->map.x] == 'P')
			ft_put_player(data);
		if (data->map.map[data->map.y][data->map.x] == '1')
			ft_put_object(data, data->img.wall);
		else if (data->map.map[data->map.y][data->map.x] == 'C')
			ft_put_object(data, data->img.collectible);
		else if (data->map.map[data->map.y][data->map.x] == 'E')
			ft_put_object(data, data->img.exit);
		if (data->map.x < (data->width / IMG_SIZE))
			data->map.x++;
		else
		{
			data->map.y++;
			data->map.x = 0;
		}
	}
}
