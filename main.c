/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:08:00 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/07 13:08:02 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory(t_game *game)
{
	ft_printf("\033[32m=======================================\033[0m\n");
	ft_printf("\033[32m==🎉🎉🎉Parabéns, você venceu!🎉🎉🎉==\033[0m\n");
	ft_printf("\033[32m=======================================\033[0m\n");
	keypress(81, game);
}

static void	check_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[31mError: O Mapa '%s' não existe.\033[0m\n", filename);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	initialize_game(t_game *game, char **argv, char *str)
{
	if (check_map_format(argv) && check_wall(argv))
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx,
				width(game->map), height(game->map), "so_long");
		show_map(game);
		free(str);
		mlx_key_hook(game->win, keypress, game);
		mlx_hook(game->win, 17, 1L << 0, ft_destroy, game);
		mlx_loop(game->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str;

	check_map_file(argv[1]);
	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		if (!check_error(argv) || !validate_map(argv) || !check(argv[1], &game))
			exit(1);
		str = read_mapa(argv[1]);
		game.map = matriz(str);
		game.map_copy = matriz(str);
		game.map_copy_copy = matriz(str);
		game.colect_count = col_count(&game);
		if (!is_collectible_accessible(&game) || !is_exit_accessible(&game))
		{
			ft_printf("\033[31mError: Coletável ou Saida inacessível\033[0m\n");
			exit(1);
		}
		initialize_game(&game, argv, str);
	}
	return (0);
}
