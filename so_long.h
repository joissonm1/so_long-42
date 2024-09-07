/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:08:10 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/07 13:08:12 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy;
	char	**map_copy_copy;
	int		player;
	int		colect_count;
	int		player_count;
	int		exit_count;
	int		img_heigth;
	int		img_width;
	int		pos_x;
	int		pos_y;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	char	*path_wall;
	char	*path_floor;
	char	*path_player;
	char	*path_colect;
	char	*path_exit;
}			t_game;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

int			width(char **matriz);
int			height(char **matriz);
int			ft_linelen(char *str);
char		**matriz(char *str);

char		*read_mapa(char *src);
void		show_map(t_game *game);
void		show_images(t_game *game);
int			count_players(t_game *game);

int			ft_destroy(t_game *game);
void		free_matrix(char **mtr);
void		destroy_images(t_game *game);

int			check_error(char **argv);
int			check_map_format(char **argv);
int			check_wall(char **argv);
int			check_line(char *str);
int			validate_map(char **argv);
void		check_blank_lines(t_game game, int i, int j, char *str);
char		**read_map_2(char *src);

int			keypress(int key, t_game *game);
void		check_pos_player(t_game *game);
int			col_count(t_game *game);
int			players_exit_counter(t_game *game, char c);
void		update_collect_count(t_game *game);
void		victory(t_game *game);

int			check(char *argv, t_game *game);
int			is_collectible_accessible(t_game *game);
void		find_player_and_fill(char **map_copy, t_point size, int *reachable);
int			is_exit_accessible(t_game *game);
void		free_map(char **map, t_point size);
#endif
