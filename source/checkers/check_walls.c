/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:19:48 by paescano          #+#    #+#             */
/*   Updated: 2023/08/16 17:44:56 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_horizontal(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width_map)
	{
		if (!(game->map[0][i] == '1'
			&& game->map[game->height_map - 1][i] == '1'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_vertical(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height_map)
	{
		if (!(game->map[i][0] == '1'
			&& game->map[i][game->width_map - 1] == '1'))
			return (0);
		i++;
	}
	return (1);
}
