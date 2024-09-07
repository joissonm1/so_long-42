/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:03:33 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/08 16:03:35 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_images(t_game *game)
{
	destroy_images(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->img_width, &game->img_heigth);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&game->img_width, &game->img_heigth);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&game->img_width, &game->img_heigth);
	game->img_colect = mlx_xpm_file_to_image(game->mlx, "./assets/item.xpm",
			&game->img_width, &game->img_heigth);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&game->img_width, &game->img_heigth);
}

static void	render_player(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, j * 50, i * 50);
	}
}

static void	render_exit(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, j * 50, i * 50);
	}
}

static void	render_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, j * 50, i * 50);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, j * 50, i * 50);
	else if (game->map[i][j] == 'P')
		render_player(game, i, j);
	else if (game->map[i][j] == 'E')
		render_exit(game, i, j);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_colect, j * 50, i * 50);
		game->colect_count = col_count(game);
	}
	else
	{
		ft_printf("\033[31mError: Elemento inválido encontrado no mapa!\n\033[0m");
		free_matrix(game->map);
		ft_destroy(game);
		exit(EXIT_FAILURE);
	}
}

void	show_map(t_game *game)
{
	int	i;
	int	j;

	show_images (game);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			render_image(game, i, j);
			j++;
		}
		i++;
	}
	update_collect_count(game);
}
