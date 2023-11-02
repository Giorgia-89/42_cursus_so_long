/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:53:34 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 16:30:13 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*this function starts from the first row and frees memory
allocated for the map*/
void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map[i]);
	free(data->map.map);
}

/*this function destroys all the images created, frees memory for the map and
destroys the window and its pointer*/
void	ft_free_memory(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.background);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.plyr);
	mlx_destroy_image(data->mlx, data->img.collectible);
	mlx_destroy_image(data->mlx, data->img.exit);
	mlx_destroy_image(data->mlx, data->img.enemy);
	ft_free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
