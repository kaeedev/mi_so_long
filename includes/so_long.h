/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:00 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/21 12:09:38 by luviso-p         ###   ########.fr       */
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
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		collectibles;
	int		player_x;
	int		player_y;
	int		moves;
	
	//Punteros a las texturas
	
} t_game;

void	ft_error(int i);
int		check_filename(const char *filename);
#endif