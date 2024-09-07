/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:41:18 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/19 12:41:19 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit_accessibility(char **map_copy_copy, t_point size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map_copy_copy[y][x] == 'E')
			{
				if (map_copy_copy[y][x] != 'F')
				{
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	is_exit_accessible(t_game *game)
{
	t_point	size;
	int		reachable;
	int		result;

	size.x = width(game->map) / 50;
	size.y = height(game->map) / 50;
	reachable = 0;
	find_player_and_fill(game->map_copy_copy, size, &reachable);
	result = check_exit_accessibility(game->map_copy_copy, size);
	free_map(game->map_copy_copy, size);
	return (result);
}
