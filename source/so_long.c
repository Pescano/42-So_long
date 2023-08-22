/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:36:07 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:22:01 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_mlx(t_game *game)
{
	game->mlxpointer = mlx_init();
	game->winpointer = mlx_new_window(game->mlxpointer, (game->width_map * 64),
			(game->height_map * 64), "so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv);
	ft_bzero(&game, sizeof(t_game));
	ft_map_set_up(&game, argv);
	ft_check_map(&game);
	ft_init_mlx(&game);
	ft_load_textures(&game);
	ft_load_graphics(&game);
	mlx_key_hook(game.winpointer, ft_game_controls, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
