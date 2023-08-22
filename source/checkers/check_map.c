/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:07:06 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 17:04:22 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_special_elements(t_game *game)
{
	if (game->players != 1)
		ft_error_free("Error\nMap must have one player\n", game->map);
	if (game->chests < 1)
		ft_error_free("Error\nMap must have at least one chest\n", game->map);
	if (game->exits != 1)
		ft_error_free("Error\nMap must have one exit\n", game->map);
}

static void	ft_surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height_map - 1)
	{
		if ((int)ft_strlen(game->map[i]) - 1 != game->width_map)
			ft_error_free("Error\nMap is not surrounded by walls\n", game->map);
		i++;
	}
	if ((int)ft_strlen(game->map[i]) != game->width_map)
		ft_error_free("Error\nMap is not surrounded by walls\n", game->map);
	if (!ft_check_vertical(game) || !ft_check_horizontal(game))
		ft_error_free("Error\nMap is not surrounded by walls\n", game->map);
}

void	ft_check_map(t_game *game)
{
	ft_surrounded_by_walls(game);
	ft_check_characters(game);
	ft_check_special_elements(game);
	ft_replace_chars(game);
	ft_check_routes(game);
	ft_unreplace_chars(game);
}
