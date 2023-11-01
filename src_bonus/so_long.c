/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:25:20 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 16:31:45 by gd-innoc         ###   ########.fr       */
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
	if (data->img.plyr == NULL)
		ft_print_error(data, 1);
	data->img.background = mlx_xpm_file_to_image(data->mlx, \
	"textures/space.xpm", &img_w, &img_h);
	if (data->img.background == NULL)
		ft_print_error(data, 2);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, \
	"textures/wall.xpm", &img_w, &img_h);
	if (data->img.wall == NULL)
		ft_print_error(data, 3);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, \
	"textures/exit.xpm", &img_w, &img_h);
	if (data->img.exit == NULL)
		ft_print_error(data, 4);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx, \
	"textures/collectible.xpm", &img_w, &img_h);
	if (data->img.collectible == NULL)
		ft_print_error(data, 5);
	data->counter = 0;
	data->collected = 0;
}

// close function to be called by mlx_hook
int	ft_close(t_data *data)
{
	ft_free_memory(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_render_next_frame(t_data *data)
{
	set_images(data);
	ft_put_background(data);
	ft_draw_map(data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_key_hook(data->win, ft_actions, data);
	return (0);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	ft_check_args(argc);
	ft_get_size(data(), argv);
	if (ft_parse_map(argv, data()) == -1)
	{
		ft_free_map(data());
		exit(EXIT_FAILURE);
	}
	if (init_flood(data()) == 1)
	{
		ft_printf("Error\nMap does not contain a valid path\n");
		ft_free_map(data());
		exit(EXIT_FAILURE);
	}
	data()->mlx = mlx_init();
	if (!data()->mlx)
		ft_print_error(data(), 7);
	data()->win = mlx_new_window(data()->mlx, data()->width, \
	data()->height, "./so_long");
	ft_render_next_frame(data());
	mlx_loop(data()->mlx);
	exit(EXIT_FAILURE);
}
