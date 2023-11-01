/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:30:37 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/01 16:32:40 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*this function transforms the count of collectibles into a string, draws the
top left image and then the string is drawn over it*/
void	ft_draw_count(t_data *data)
{
	char	*str;

	str = ft_itoa(data->counter);
	ft_put_object(data, data->img.wall);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FFFFFF, str);
	free(str);
}
