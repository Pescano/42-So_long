/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:12:10 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:26:44 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *string)
{
	ft_putstr_error(string);
	exit(0);
}

void	ft_error_free(char *string, char **map)
{
	ft_putstr_error(string);
	ft_free_map(map);
	exit(0);
}
