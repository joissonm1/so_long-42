/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:26:28 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/07 15:26:30 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e'
		&& argv[1][i - 3] == 'b' && argv[1][i - 4] == '.')
		return (1);
	else
	{
		ft_printf("\033[31mError: Formato invalido!\033[0m");
		exit(EXIT_SUCCESS);
	}
}

int	check_map_format(char **argv)
{
	t_game	game;
	char	*str;
	int		i;
	int		j;

	str = read_mapa(argv[1]);
	game.map = matriz(str);
	i = width(game.map);
	j = height(game.map);
	if (i == j)
	{
		free_matrix(game.map);
		ft_printf("\033[31mError: Formato de mapa inválido!\033[0m");
		exit(EXIT_SUCCESS);
	}
	free_matrix(game.map);
	free(str);
	return (1);
}

static void	check_top_bottom_walls(t_game *game, int j)
{
	if (check_line(game->map[0]) == 0)
		exit(ft_printf("\033[31mError: Limites de mapa inválido!\033[0m"));
	if (check_line(game->map[j - 1]) == 0)
		exit(ft_printf("\033[31mLError: imites de mapa inválido!\033[0m"));
}

static void	check_left_right_walls(t_game *game, int i, int j)
{
	int	count_parede;

	count_parede = 0;
	while (count_parede != j)
	{
		if ((char)game->map[count_parede++][0] != '1')
			exit(ft_printf("\033[31mError: Limites de mapa inválido!\033[0m"));
		count_parede--;
		if ((char)game->map[count_parede++][i - 1] != '1')
			exit(ft_printf("\033[31mError: Limites de mapa inválido!\033[0m"));
	}
}

int	check_wall(char **argv)
{
	t_game	game;
	char	*str;
	int		i;
	int		j;

	str = read_mapa(argv[1]);
	game.map = matriz(str);
	i = width(game.map) / 50;
	j = height(game.map) / 50;
	check_top_bottom_walls(&game, j);
	check_left_right_walls(&game, i, j);
	check_blank_lines(game, j, i, str);
	free_matrix(game.map);
	//free(str);
	return (1);
}
