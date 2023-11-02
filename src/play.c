/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:23:15 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 15:17:13 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_set_y(char direction, int new_y)
{
	if (direction == 'u')
		new_y--;
	else if (direction == 'd')
		new_y++;
	return (new_y);
}

int	ft_set_x(char direction, int new_x)
{
	if (direction == 'l')
		new_x--;
	else if (direction == 'r')
		new_x++;
	return (new_x);
}

void	ft_check_collected(t_data *data)
{
	if (data->collected == data->map.collectible)
	{
		ft_printf("You won!\n");
		ft_free_memory(data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("You need to eat all the mushrooms ");
		ft_printf("before you can exit the game!\n");
	}
}

/*this function checks that the new player position is valid. If so,
it places the background at the current position, then updates player
position and draws it at the new position*/
void	ft_move(t_data *data, char direction, int new_x, int new_y)
{
	int	curr;

	curr = data->counter;
	new_y = ft_set_y(direction, new_y);
	new_x = ft_set_x(direction, new_x);
	if (data->map.map[new_y][new_x] != '1' && \
	data->map.map[new_y][new_x] != 'E')
	{
		ft_put_images(data, new_x, new_y);
	}
	else if (data->map.map[new_y][new_x] == 'E')
		ft_check_collected(data);
	if (curr != data->counter)
		ft_printf("Moves: %d\n", data->counter);
}

/*this function checks which key was pressed and calls the corresponding
function. Y is the vertical, X is the horizontal axis. */
int	ft_actions(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->p_x;
	new_y = data->p_y;
	if (keycode == ESC)
		ft_close(data);
	if (keycode == W || keycode == UP)
		ft_move(data, 'u', new_x, new_y);
	else if (keycode == S || keycode == DOWN)
		ft_move(data, 'd', new_x, new_y);
	else if (keycode == A || keycode == LEFT)
		ft_move(data, 'l', new_x, new_y);
	else if (keycode == D || keycode == RIGHT)
		ft_move(data, 'r', new_x, new_y);
	return (0);
}
