/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:27:03 by paescano          #+#    #+#             */
/*   Updated: 2023/08/16 21:29:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_textures(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/floor.xpm", &i, &j);
	game->trees = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/exit.xpm", &i, &j);
	game->chest = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/item.xpm", &i, &j);
}
