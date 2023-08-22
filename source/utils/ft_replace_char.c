/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:37:13 by paescano          #+#    #+#             */
/*   Updated: 2023/08/16 19:46:23 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_replace_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height_map)
	{
		j = 0;
		while (j < game->width_map)
		{
			if (game->map[i][j] == '0')
				game->map[i][j] = 'f';
			if (game->map[i][j] == 'P')
				game->map[i][j] = 'p';
			if (game->map[i][j] == 'E')
				game->map[i][j] = 'e';
			if (game->map[i][j] == 'C')
				game->map[i][j] = 'c';
			j++;
		}
		i++;
	}
}

void	ft_unreplace_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height_map)
	{
		j = 0;
		while (j < game->width_map)
		{
			if (game->map[i][j] == 'f')
				game->map[i][j] = '0';
			if (game->map[i][j] == 'p')
				game->map[i][j] = 'P';
			if (game->map[i][j] == 'e')
				game->map[i][j] = 'E';
			if (game->map[i][j] == 'c')
				game->map[i][j] = 'C';
			j++;
		}
		i++;
	}
}
