/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:23:17 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/11/02 16:37:29 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_path_map(t_check *check, int x, int y)
{
	if (check->map[y][x] == 'C')
	{
		free_check_map(check);
		return (1);
	}
	if (check->map[y][x] == 'E' || check->map[y][x] == 'X')
	{
		if (check->map[y - 1][x] != 'P' && check->map[y][x - 1] != 'P' \
		&& check->map[y + 1][x] != 'P' && check->map[y][x + 1] != 'P')
		{
			free_check_map(check);
			return (1);
		}
	}
	return (0);
}

void	free_check_map(t_check *check)
{
	int	i;

	i = 0;
	if (check->map)
	{
		while (check->map[i])
		{
			free(check->map[i]);
			i++;
		}
		free(check->map);
	}
}

/* void ft_print_result(char const *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void ft_print_map(t_check *check)
{
	int i = 0;
	while (check->map[i])
	{
		ft_print_result(check->map[i]);
		write(1, "\n", 1);
		i++;
	}
} */
