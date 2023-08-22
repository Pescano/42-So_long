/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:34:21 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:20:45 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_texture(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->trees, x * 64, y * 64);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->chest, x * 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player, x * 64, y * 64);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, x * 64, y * 64);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, x * 64, y * 64);
}

void	ft_load_graphics(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height_map)
	{
		x = 0;
		while (x < game->width_map)
		{
			ft_put_texture(game, y, x);
			x++;
		}
		y++;
	}
}
