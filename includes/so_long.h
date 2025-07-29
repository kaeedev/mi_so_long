/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/29 13:08:45 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "mi_libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h> //para malloc, free y exit
# include <unistd.h> //para read, write y close
# include <fcntl.h> //para open
# include <stdio.h> // Para perror, errores descriptivos

// Tamaño de cada sprite en píxeles
# define TILE_SIZE 32

// Códigos de teclas para Linux
#define KEY_W MLX_KEY_W
#define KEY_A MLX_KEY_A  
#define KEY_S MLX_KEY_S
#define KEY_D MLX_KEY_D
#define KEY_ESC MLX_KEY_ESCAPE

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*win;
	char		**map;
	int			map_width; // numero de columnas. (ancho del mapa)
	int			map_height; //numero de filas. (altura del mapa)
	int			collectibles;
	int			player_x;
	int			player_y;
	int			moves;
	
	//Punteros a las texturas
	
} t_game;

void	ft_error(int i);
int		check_filename(const char *filename);
int		game_width(char *line, t_game *game);
t_list	*read_lines(int fd, t_game *game);
void	convert_list_to_array(t_list *map_list, t_game *game);
void	read_map_file(const char *filepath, t_game *game);
void	validate_walls(t_game *game);
void	count_components(t_game *game, int *c, int *p, int *e);
void	validate_contents(t_game *game);
char	**copy_map(t_game *game);
void	flood_fill(char **map_copy, int x, int y, t_game *game);
void	check_path_is_valid(char **map_copy, t_game *game);
void	validate_path(t_game *game);
void	close_game(void *param);
void	handle_keypress(mlx_key_data_t keydata, void *param);
void	init_mlx(t_game *game);
#endif