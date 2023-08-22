/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:05:32 by paescano          #+#    #+#             */
/*   Updated: 2023/08/16 17:44:46 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_map_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\n')
		width++;
	return (width);
}

static int	ft_add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height_map++;
	tmp = (char **)malloc(sizeof(char *) * (game->height_map + 1));
	if (!tmp)
		ft_error_free("Error\nMalloc failed\n", game->map);
	tmp[game->height_map] = NULL;
	while (i < game->height_map - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

void	ft_map_set_up(t_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		ft_error("Error\nMap not found\n");
	game->height_map = 0;
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!ft_add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->width_map = ft_get_map_width(game->map[0]);
}
