/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:02:03 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 14:54:24 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*this function exits the game if args are not 2*/
void	ft_check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error: usage must be './so_long maps/mapname.ber'\n");
		exit(EXIT_FAILURE);
	}
}

/*this function checks that the file was opened correctly*/
void	ft_check_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

/*this function counts and compares the length of each row*/
void	compare_length(int len, int next_len, int fd)
{
	ft_printf("len is %d\nNext len is %d", len, next_len);
	if (len != next_len)
	{
		close(fd);
		ft_printf("Error\nMap is not rectangular\n");
		exit(EXIT_FAILURE);
	}
}

/*this function opens the file and intiates the rows checks*/
void	ft_check_rows(int fd, int len)
{
	char	buffer[1];
	int		byte;
	int		next_len;

	next_len = 0;
	byte = read(fd, buffer, 1);
	while (byte == 1)
	{
		if (buffer[0] != '\n' && buffer[0] != '\0')
			next_len++;
		else if (buffer[0] == '\n')
		{
			compare_length(len, next_len, fd);
			next_len = 0;
		}
		byte = read(fd, buffer, 1);
	}
}

/*this function checks that the map meets the minimum size requirements*/
void	check_dim(int width, int height, int fd)
{
	width = width / IMG_SIZE;
	height = height / IMG_SIZE;
	if (width == 0 || height == 0)
	{
		close(fd);
		ft_printf("Error\nMap cannot be empty\n");
		exit(EXIT_FAILURE);
	}
	else if (width < 3 || height < 3)
	{
		close(fd);
		ft_printf("Error\nMap too small\n");
		exit(EXIT_FAILURE);
	}
}
