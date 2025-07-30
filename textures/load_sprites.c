/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:33:54 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/30 14:10:36 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game)
{
	game->tx_floor = mlx_load_png("/home/luviso-p/Documents/github/mi_so_long/assets/floor.png");
	game->tx_collectible = mlx_load_png("/home/luviso-p/Documents/github/mi_so_long/assets/collectible.png");
	game->tx_exit = mlx_load_png("/home/luviso-p/Documents/github/mi_so_long/assets/exit.png");
	game->tx_wall_horizontal = mlx_load_png("/home/luviso-p/Documents/github/mi_so_long/assets/wall_horizontal.png");
	game->tx_wall_vertical = mlx_load_png("/home/luviso-p/Documents/github/mi_so_long/assets/wall_vertical.png");
	game->tx_player = mlx_load_png("/home/luviso-p/Documents/github/mi_so_long/assets/player.png");
	if (!game->tx_floor || !game->tx_wall_horizontal || !game->tx_wall_vertical 
		|| !game->tx_player || !game->tx_collectible || !game->tx_exit)
        ft_error(6);
	game->img_floor = mlx_texture_to_image(game->mlx, game->tx_floor);
    game->img_wall_horizontal = mlx_texture_to_image(game->mlx, game->tx_wall_horizontal);
	game->img_wall_vertical = mlx_texture_to_image(game->mlx, game->tx_wall_vertical);
    game->img_player = mlx_texture_to_image(game->mlx, game->tx_player);
    game->img_collectible = mlx_texture_to_image(game->mlx, game->tx_collectible);
    game->img_exit = mlx_texture_to_image(game->mlx, game->tx_exit);
    if (!game->img_floor || !game->img_wall_horizontal || !game->img_wall_vertical 
		|| !game->img_player || !game->img_collectible || !game->img_exit)
        ft_error(6);
}
