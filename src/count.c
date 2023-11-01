/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:25 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 14:45:59 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*count and return the length of the first line of an open fd
Initialise buffer of size 1 to read byte by byte while byte is
successfully read (== 1) and increase lenght until we find a \n*/
int	ft_linelen(int fd)
{
	char	buffer[1];
	int		byte;
	int		len;

	buffer[0] = '\0';
	byte = 1;
	len = 0;
	while (byte == 1)
	{
		byte = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

/*this function counts the number of line of an open fd*/
int	ft_countlines(int fd)
{
	int		n_lines;
	char	*line;

	n_lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		n_lines++;
	}
	return (n_lines);
}

/* This function counts the number of players, exits and collectibles
in the map, and passes them to a check function. To be valid, a map
must have one exit, one player and at least one collectible.*/
int	ft_count_requisites(t_data *data, int plyr, int exit)
{
	int	x;
	int	y;
	int	collectible;

	collectible = 0;
	x = 1;
	while (x < data->width / IMG_SIZE - 1)
	{
		y = 1;
		while (y < data->height / IMG_SIZE - 1)
		{
			if (data->map.map[y][x] == 'C')
				collectible++;
			else if (data->map.map[y][x] == 'P')
				plyr++;
			else if (data->map.map[y][x] == 'E')
				exit++;
			y++;
		}
		x++;
	}
	if (ft_check_requisites(collectible, plyr, exit) == -1)
		return (-1);
	return (0);
}
