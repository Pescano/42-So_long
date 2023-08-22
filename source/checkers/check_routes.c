/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:51:53 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 17:25:45 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_position(t_game *game, int player_y, int player_x)
{
	if (game->map[player_y][player_x] == 'f')
		game->map[player_y][player_x] = '0';
	if (game->map[player_y][player_x] == 'p')
		game->map[player_y][player_x] = 'P';
	if (game->map[player_y][player_x] == 'e')
	{
		game->map[player_y][player_x] = 'E';
		game->checkexit++;
	}
	if (game->map[player_y][player_x] == 'c')
	{
		game->map[player_y][player_x] = 'C';
		game->checkchest++;
	}
}

static void	ft_flood_fill(t_game *game, int player_y, int player_x)
{
	if (game->map[player_y][player_x] == 'f' ||
	game->map[player_y][player_x] == 'c' || game->map[player_y][player_x] == 'p'
	|| game->map[player_y][player_x] == 'e')
	{
		ft_check_position(game, player_y, player_x);
		ft_flood_fill(game, player_y, player_x + 1);
		ft_flood_fill(game, player_y, player_x - 1);
		ft_flood_fill(game, player_y + 1, player_x);
		ft_flood_fill(game, player_y - 1, player_x);
	}
}

void	ft_check_routes(t_game *game)
{
	game->checkchest = 0;
	game->checkexit = 0;
	ft_flood_fill(game, game->player_y, game->player_x + 1);
	ft_flood_fill(game, game->player_y, game->player_x - 1);
	ft_flood_fill(game, game->player_y + 1, game->player_x);
	ft_flood_fill(game, game->player_y - 1, game->player_x);
	if (game->checkchest != game->chests)
		ft_error_free("Error\nSome chest are out of the map\n",
			game->map);
	if (game->checkexit == 0)
		ft_error_free("Error\nExit is out of the map\n",
			game->map);
}
