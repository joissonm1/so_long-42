/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:16:20 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/16 12:16:21 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_blank_lines(t_game game, int i, int j, char *str)
{
	i = 0;
	while (game.map[i])
	{
		if (game.map[i][j] >= 32 && game.map[i][j] <= 126)
		{
			free_matrix(game.map);
			free(str);
			ft_printf("\033[31mError: O mapa contém linhas em branco!\033[0m\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static int	check_borders(char **map)
{
	int		i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	if (!check_line(map[0]) || !check_line(map[i - 1]))
		return (0);
	return (1);
}

int	validate_map(char **argv)
{
	t_game	game;
	char	*str;

	str = read_mapa(argv[1]);
	game.map = matriz(str);
	if (!check_borders(game.map))
	{
		free_matrix(game.map);
		free(str);
		ft_printf("\033[31mError: O mapa tem elemento fora do limite!\033[0m\n");
		exit(EXIT_FAILURE);
	}
	free_matrix(game.map);
	free(str);
	return (1);
}

static int	count_elements(char *str, int *player_nbr,
	int *exit_nbr, int *colect_count)
{
	int	i;

	i = 0;
	*player_nbr = 0;
	*exit_nbr = 0;
	*colect_count = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			(*colect_count)++;
		else if (str[i] == 'P')
			(*player_nbr)++;
		else if (str[i] == 'E')
			(*exit_nbr)++;
		i++;
	}
	return (1);
}

int	check(char *argv, t_game *game)
{
	char	*str;
	int		player_nbr;
	int		exit_nbr;
	int		colect_count;

	str = read_mapa(argv);
	if (!str)
		return (0);
	if (!count_elements(str, &player_nbr, &exit_nbr, &colect_count))
	{
		free(str);
		return (0);
	}
	game->colect_count = colect_count;
	if (colect_count < 1 || exit_nbr != 1 || player_nbr != 1)
	{
		free(str);
		ft_printf("\033[31mError!\n\033[0m");
		return (0);
	}
	free(str);
	return (1);
}
