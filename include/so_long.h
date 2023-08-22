/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:33:38 by paescano          #+#    #+#             */
/*   Updated: 2023/08/17 12:26:17 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct s_stats
{
	int		fd;
	int		height_map;
	int		width_map;
	int		players;
	int		chests;
	int		exits;
	int		player_x;
	int		player_y;
	int		moves;
	int		checkchest;
	int		checkexit;

	char	**map;

	void	*floor;
	void	*trees;
	void	*player;
	void	*exit;
	void	*chest;
	void	*mlxpointer;
	void	*winpointer;

}	t_game;

//utils functions
/**
 * @brief The bzero() function erases the data in the n bytes of the
 * memory starting at the location pointed to by s, by writing zeros
 * (bytes containing '\0') to that area.
 * 
 * @param s pointer to the memory area to zero
 * @param n bytes to set zero
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief write a message to the error output.
 * 
 * @param string string to print
 */
void	ft_putstr_error(char *string);
/**
 * @brief prints the number n to the standard output.
 * 
 * @param n number to print
 */
void	ft_putnbr(int n);
/**
 * @brief write a message to the standard error output
 *  and terminate the program.
 * 
 * @param string message to print
 */
void	ft_error(char *string);
/**
 * @brief write a message to the standard error output and erase the memory
 * allocated for the map.
 * 
 * @param string 
 * @param map 
 */
void	ft_error_free(char *string, char **map);
/**
 * @brief erase the memory allocated for the map.
 * 
 * @param map matrix with the map
 */
void	ft_free_map(char **map);
/**
 * @brief erase the memory allocated for the map, mlx and win pointers.
 *  after terminate the program.
 * 
 * @param game struct with all the information
 */
void	ft_finish_game(t_game *game);
/**
 * @brief write a message to the standard output and terminate the program.
 * 
 * @param game struct with all the information
 */
void	ft_win_game(t_game *game);
/**
 * @brief replace some characters in the map, 0 for f, P -for p,
 * C for c and E for e.
 * 
 * @param game struct with all the information
 */
void	ft_replace_chars(t_game *game);
/**
 * @brief replace some characters in the map, f for 0, p -for P,
 * c for C and e for E.
 * 
 * @param game struct with all the information
 */
void	ft_unreplace_chars(t_game *game);
/**
 * @brief check if the string is the same as the string passed as a parameter
 * but only the first n bytes.
 * 
 * @param s1 string to compare
 * @param s2 string to compare
 * @param n bytes to compare
 * @return int return 0 if the strings are the same, otherwise return the 
 * difference
 */
int		ft_strncmp(const char *s1, const char *s2, int n);

//controllers functions
/**
 * @brief read the map and save it in a matrix
 * 
 * @param game struct with all the information
 * @param argv arguments
 */
void	ft_map_set_up(t_game *game, char **argv);
/**
 * @brief read the map and use the textures to draw the map
 * 
 * @param game struct with all the information
 */
void	ft_load_graphics(t_game *game);
/**
 * @brief load the textures from xpm files into the struct.
 * 
 * @param game struct with all the information
 */
void	ft_load_textures(t_game *game);
/**
 * @brief update the position of the player in the map and update the
 * number of moves.
 * 
 * @param game 
 * @param x 
 * @param y 
 */
void	ft_update_position(t_game *game, int x, int y);
/**
 * @brief set the controls to move the player, update the map
 * with the new position of the player, draw the map after the
 * movement and check if the player win.
 * 
 * @param game struct with all the information
 */
int		ft_game_controls(int event, t_game *game);

//check functions
/**
 * @brief check number of arguments and if the file is a .ber file
 * 
 * @param argc number of arguments
 * @param argv arguments
 */
void	ft_check_args(int argc, char **argv);
/**
 * @brief check if the map is a valid map check is surrounded by walls,
 * is posible to reach the exit or collectables, have only valid 
 * characters and have the correct number of collectables, player and exit.
 * 
 * @param game struct with all the information
 */
void	ft_check_map(t_game *game);
/**
 * @brief check if is posible to reach the exit and all collectables
 * 
 * @param game struct with all the information
 */
void	ft_check_routes(t_game *game);
/**
 * @brief check if the map have only valid characters
 * 
 * @param game struct with all the information
 */
void	ft_check_characters(t_game *game);
/**
 * @brief check if the map is surrounded by walls horizontally
 * 
 * @param game struct with all the information
 * @return int boolean
 */
int		ft_check_horizontal(t_game *game);
/**
 * @brief check if the map is surrounded by walls vertically
 * 
 * @param game struct with all the information
 * @return int boolean
 */
int		ft_check_vertical(t_game *game);

#endif
