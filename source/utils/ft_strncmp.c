/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:19:14 by paescano          #+#    #+#             */
/*   Updated: 2023/08/15 19:37:55 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] == s2[x] && (s1[x] || s2[x]))
			x++;
		else
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
	}
	return (0);
}
