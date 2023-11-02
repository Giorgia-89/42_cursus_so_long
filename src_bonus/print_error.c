/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:34:28 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 16:24:17 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// print error based on numeric code
void	ft_print_error(t_data *data, int code)
{
	if (code == 6)
		ft_printf("Error\nFailed to allocate memory for map\n");
	else
	{
		if (code == 1)
			ft_printf("Error\nFailed to load player image\n");
		else if (code == 2)
			ft_printf("Error\nFailed to load background image\n");
		else if (code == 3)
			ft_printf("Error\nFailed to load wall image\n");
		else if (code == 4)
			ft_printf("Error\nFailed to load exit image\n");
		else if (code == 5)
			ft_printf("Error\nFailed to load collectible image\n");
		else if (code == 8)
			ft_printf("Error\nFailed to load enemy image\n");
		else if (code == 7)
			ft_printf("Error\nProgram init failed\n");
		ft_free_memory(data);
	}
	exit(EXIT_FAILURE);
}
