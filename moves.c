/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:08:09 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/10 11:08:10 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static long int	g_counter;

void	check_pos_player(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{	
			if (game->map[i][j] == 'P')
			{
				game->pos_x = i;
				game->pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	check_moves_up_and_down(int key, t_game *game)
{
	int	x;
	int	y;
	int	j;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	j = 0;
	if (key == 'w' && game->map[x - 1][y] != '1' && game->map[x - 1][y] != 'E')
	{
		if (game->map[x - 1][y] == 'C')
			j = 1;
		game->map[x][y] = '0';
		game->map[x - 1][y] = 'P';
		ft_printf("\033[34mNumero de movimentos:\033[0m %d\n", g_counter++);
	}
	if (key == 's' && game->map[x + 1][y] != '1' && game->map[x + 1][y] != 'E')
	{
		if (game->map[x + 1][y] == 'C')
			game->colect_count--;
		game->map[x][y] = '0';
		game->map[x + 1][y] = 'P';
		ft_printf("\033[34mNumero de movimentos:\033[0m %d\n", g_counter++);
	}
	return (j);
}

static int	check_moves_left_and_right(int key, t_game *game)
{
	int	x;
	int	y;
	int	j;

	check_pos_player(game);
	x = game->pos_x;
	y = game->pos_y;
	j = 0;
	if (key == 'a' && game->map[x][y - 1] != '1' && game->map[x][y - 1] != 'E')
	{
		if (game->map[x][y - 1] == 'C')
			j = 1;
		game->map[x][y] = '0';
		game->map[x][y - 1] = 'P';
		ft_printf("\033[34mNumero de movimentos:\033[0m %d\n", g_counter++);
	}
	if (key == 'd' && game->map[x][y + 1] != '1' && game->map[x][y + 1] != 'E')
	{
		if (game->map[x][y + 1] == 'C')
			game->colect_count--;
		game->map[x][y] = '0';
		game->map[x][y + 1] = 'P';
		ft_printf("\033[34mNumero de movimentos:\033[0m %d\n", g_counter++);
	}
	return (j);
}

static void	check_exit(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if ((key == 'W' || key == 'w') && game->map[x - 1][y] == 'E'
			&& !game->colect_count)
		victory(game);
	if ((key == 'S' || key == 's') && game->map[x + 1][y] == 'E'
			&& !game->colect_count)
		victory(game);
	if ((key == 'A' || key == 'a') && game->map[x][y - 1] == 'E'
			&& !game->colect_count)
		victory(game);
	if ((key == 'D' || key == 'd') && game->map[x][y + 1] == 'E'
			&& !game->colect_count)
		victory(game);
}

int	keypress(int key, t_game *game)
{
	if (key == 65307 || key == 81 || key == 113)
	{
		free_matrix(game->map);
		ft_destroy(game);
		ft_printf("\033[32mJanela fechada com sucesso!\n\033[0m");
		exit(EXIT_SUCCESS);
	}
	game->colect_count -= check_moves_up_and_down(key, game);
	game->colect_count -= check_moves_left_and_right(key, game);
	if (game->colect_count == 0)
		check_exit(key, game);
	show_map(game);
	return (0);
}
