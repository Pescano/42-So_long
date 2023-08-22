/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:25:13 by paescano          #+#    #+#             */
/*   Updated: 2023/08/16 21:06:50 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_valid_char(t_game *game, int i, int j)
{
	if (game->map[i][j] != '1' &&
		game->map[i][j] != '0' &&
		game->map[i][j] != 'P' &&
		game->map[i][j] != 'C' &&
		game->map[i][j] != 'E')
	{
		ft_error_free("Error\nInvalid character in map\n", game->map);
	}
	if (game->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		game->players++;
	}
	if (game->map[i][j] == 'C')
			game->chests++;
	if (game->map[i][j] == 'E')
			game->exits++;
}

void	ft_check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->players = 0;
	game->chests = 0;
	game->exits = 0;
	while (i < game->height_map)
	{
		j = 0;
		while (j < game->width_map)
		{
			ft_is_valid_char(game, i, j);
			j++;
		}
		i++;
	}
}
