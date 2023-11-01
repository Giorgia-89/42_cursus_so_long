/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:40:31 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 16:18:11 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
/*This function rcursively replaces the contents of the map with a P
 if it encounters a 0 or C*/

void	flood_fill(t_check *check, int x, int y)
{
	check->map[y][x] = 'P';
	if (x - 1 > 0 && (check->map[y][x - 1] == '0' || \
	check->map[y][x - 1] == 'C'))
		flood_fill(check, x - 1, y);
	if (y - 1 > 0 && (check->map[y - 1][x] == '0' || \
	check->map[y - 1][x] == 'C'))
		flood_fill(check, x, y - 1);
	if (x + 1 < check->len_x - 1 && (check->map[y][x + 1] == '0' || \
	check->map[y][x + 1] == 'C'))
		flood_fill(check, x + 1, y);
	if (y + 1 < check->len_y + 1 && (check->map[y + 1][x] == '0' || \
	check->map[y + 1][x] == 'C'))
		flood_fill(check, x, y + 1);
	return ;
}

/*this functions creates a copy of the map to be used to check the path*/
t_check	*check_map_init(t_data *data)
{
	int				i;
	static t_check	check;

	check.len_y = -1;
	while (data->map.map[++check.len_y])
		;
	check.map = malloc(sizeof(char *) * (check.len_y + 1));
	check.len_x = -1;
	while (data->map.map[0][++check.len_x])
		;
	i = -1;
	while (++i < check.len_y)
	{
		check.map[i] = ft_strdup(data->map.map[i]);
		if (!check.map)
		{
			free_check_map(&check);
			ft_free_memory(data);
			exit(EXIT_FAILURE);
		}
	}
	check.map[i] = NULL;
	return (&check);
}

/*this function finds the initial position of the player to then
initiate the flood*/
void	ft_find_start(t_check *check)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (check->map[y])
	{
		x = 1;
		while (check->map[y][x])
		{
			if (check->map[y][x] == 'P')
			{
				check->p_x = x;
				check->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/*this function initiates the map checks*/
int	init_flood(t_data *data)
{
	t_check	*check;
	int		x;
	int		y;
	int		i;

	check = check_map_init(data);
	ft_find_start(check);
	x = check->p_x;
	y = check->p_y;
	flood_fill(check, x, y);
	y = -1;
	while (check->map[++y])
	{
		x = -1;
		while (check->map[y][++x])
		{
			i = check_path_map(check, x, y);
			if (i)
				return (i);
		}
	}
	free_check_map(check);
	return (0);
}
