/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:08:33 by jmiguel           #+#    #+#             */
/*   Updated: 2024/08/07 13:08:35 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_space_line(char *line, char *map, int fd)
{
	if (line[0] == '\n')
	{
		free(line);
		free(map);
		close(fd);
		ft_printf("\033[31mErro: Mapa contém uma linha vazia!\n\033[0m");
		exit(EXIT_FAILURE);
	}
}

char	*read_mapa(char *src)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_strdup("");
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_space_line(line, map, fd);
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
