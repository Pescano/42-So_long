/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:58:19 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:46:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_keyboard_s(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	ft_update_position(game, x, y);
	if (game->map[y + 1][x] != 'E')
		game->map[y + 1][x] = '0';
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}

static int	ft_keyboard_w(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	ft_update_position(game, x, y);
	if (game->map[y - 1][x] != 'E')
		game->map[y - 1][x] = '0';
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}

static int	ft_keyboard_a(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	ft_update_position(game, x, y);
	if (game->map[y][x + 1] != 'E')
		game->map[y][x + 1] = '0';
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}

static int	ft_keyboard_d(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	ft_update_position(game, x, y);
	if (game->map[y][x - 1] != 'E')
		game->map[y][x - 1] = '0';
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	return (1);
}

int	ft_game_controls(int event, t_game *game)
{
	int	update;

	if (event == 53)
		ft_finish_game(game);
	if (event == 13)
		update = ft_keyboard_s(game, game->player_x, game->player_y - 1);
	if (event == 1)
		update = ft_keyboard_w(game, game->player_x, game->player_y + 1);
	if (event == 0)
		update = ft_keyboard_a(game, game->player_x - 1, game->player_y);
	if (event == 2)
		update = ft_keyboard_d(game, game->player_x + 1, game->player_y);
	if (update)
		ft_load_graphics(game);
	return (1);
}
