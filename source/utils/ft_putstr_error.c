/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:25:44 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:26:53 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_error(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		write(2, &string[i++], 1);
}
