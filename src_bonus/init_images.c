/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:15:15 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 16:24:19 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*this function initialises the images to use in the mlx window. It checks that
images were allocated correctly, and if not, it prints an error and exits the
game.*/
void	set_images(t_data *data)
{
	int	img_w;
	int	img_h;

	data->img.plyr = mlx_xpm_file_to_image(data->mlx, \
	"textures/player.xpm", &img_w, &img_h);
	data->img.background = mlx_xpm_file_to_image(data->mlx, \
	"textures/space.xpm", &img_w, &img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, \
	"textures/wall.xpm", &img_w, &img_h);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, \
	"textures/exit.xpm", &img_w, &img_h);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx, \
	"textures/collectible.xpm", &img_w, &img_h);
	data->img.enemy = mlx_xpm_file_to_image(data->mlx, \
	"textures/enemy.xpm", &img_w, &img_h);
	data->counter = 0;
	data->collected = 0;
}

void	check_images(t_data *data)
{
	if (data->img.plyr == NULL)
		ft_print_error(data, 1);
	if (data->img.background == NULL)
		ft_print_error(data, 2);
	if (data->img.wall == NULL)
		ft_print_error(data, 3);
	if (data->img.exit == NULL)
		ft_print_error(data, 4);
	if (data->img.collectible == NULL)
		ft_print_error(data, 5);
	if (data->img.enemy == NULL)
		ft_print_error(data, 8);
}


