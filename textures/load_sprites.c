/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:33:54 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/05 13:37:56 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//funcion para cargar los sprites
void	load_sprites(t_game *game)
{
	game->tx_floor = mlx_load_png("assets/floor.png");
	game->tx_collectible = mlx_load_png("/assets/collectible.png");
	game->tx_exit = mlx_load_png("/assets/exit.png");
	game->tx_wall = mlx_load_png("/assets/wall.png");
	game->tx_i_wall = mlx_load_png("/assets/i_wall.png");
	game->tx_player = mlx_load_png("/assets/player.png");
	if (!game->tx_floor || !game->tx_wall || !game->tx_i_wall 
		|| !game->tx_player || !game->tx_collectible || !game->tx_exit)
        ft_error(6);
	game->img_floor = mlx_texture_to_image(game->mlx, game->tx_floor);
    game->img_wall = mlx_texture_to_image(game->mlx, game->tx_wall);
	game->img_i_wall = mlx_texture_to_image(game->mlx, game->tx_i_wall);
    game->img_player = mlx_texture_to_image(game->mlx, game->tx_player);
    game->img_collectible = mlx_texture_to_image(game->mlx, game->tx_collectible);
    game->img_exit = mlx_texture_to_image(game->mlx, game->tx_exit);
    if (!game->img_floor || !game->img_wall || !game->img_i_wall 
		|| !game->img_player || !game->img_collectible || !game->img_exit)
        ft_error(6);
}
