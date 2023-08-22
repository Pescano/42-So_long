/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:08 by paescano          #+#    #+#             */
/*   Updated: 2023/08/22 11:12:02 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Error\nNo map provided\n");
	if (argc > 2)
		ft_error("Error\nToo many arguments (use ./so_long map.ber)\n");
	if (ft_strncmp(argv[1] + (int)ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Error\nWrong file extension (use files .ber)\n");
}
