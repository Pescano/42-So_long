/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:04:34 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:05:01 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->chests == 0)
			ft_win_game(game);
		game->player_x = x;
		game->player_y = y;
		game->moves++;
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->moves++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->chests--;
		game->moves++;
	}
}
