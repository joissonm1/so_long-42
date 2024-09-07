/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:08:55 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/07 13:08:57 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width(char **matriz)
{
	int	j;

	j = 0;
	while (matriz[0][j])
		j++;
	return (j * 50);
}

int	height(char **matriz)
{
	int	j;

	j = 0;
	while (matriz[j])
		j++;
	return (j * 50);
}

char	**matriz(char *str)
{
	return (ft_split(str, '\n'));
}

int	ft_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_colect);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix || !*matrix)
		return ;
	while (matrix[++i] != NULL)
		free(matrix[i]);
	free(matrix);
}
