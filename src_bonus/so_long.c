/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:25:20 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 16:16:03 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
