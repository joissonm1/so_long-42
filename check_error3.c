/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:20:28 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/19 09:20:31 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, t_point size)
{
	int	y;

	y = 0;
	while (y < size.y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

static void	flood_fill(char **map, int x, int y, int *reachable)
{
	if (x < 0 || x >= width(map) / 50 || y < 0 || y >= height(map) / 50)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		(*reachable)++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, reachable);
	flood_fill(map, x - 1, y, reachable);
	flood_fill(map, x, y + 1, reachable);
	flood_fill(map, x, y - 1, reachable);
}

void	find_player_and_fill(char **map_copy, t_point size, int *reachable)
{
	int	y;
	int	x;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map_copy[y][x] == 'P')
			{
				flood_fill(map_copy, x, y, reachable);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	check_collectibles_accessibility(char **map_copy, t_point size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map_copy[y][x] == 'C')
			{
				if (map_copy[y][x] != 'F')
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

int	is_collectible_accessible(t_game *game)
{
	t_point	size;
	int		reachable;
	int		result;

	size.x = width(game->map) / 50;
	size.y = height(game->map) / 50;
	reachable = 0;
	find_player_and_fill(game->map_copy, size, &reachable);
	result = check_collectibles_accessibility(game->map_copy, size);
	free_map(game->map_copy, size);
	return (result);
}
