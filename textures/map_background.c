/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:35:19 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/04 13:38:05 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game, int j, int i)
{
	mlx_image_to_window(game->mlx, game->img_floor, i * TILE_SIZE, j * TILE_SIZE);
	if (game->map[j][i] == '1')
	{
		if (i == 0)
			mlx_image_to_window(game->mlx, game->img_wall, i * TILE_SIZE, j * TILE_SIZE );
		else if (i == game->map_width - 1)
			mlx_image_to_window(game->mlx, game->img_wall, i * TILE_SIZE, j * TILE_SIZE);
		else if (j == game->map_height - 1)
			mlx_image_to_window(game->mlx, game->img_wall, i * TILE_SIZE, j * TILE_SIZE);
		else if (j == 0)
			mlx_image_to_window(game->mlx, game->img_wall, i * TILE_SIZE, j * TILE_SIZE);
		else
			mlx_image_to_window(game->mlx, game->img_i_wall, i * TILE_SIZE, j * TILE_SIZE);
	}	
	else
	{
		if (game->map[j][i] == 'C')
			mlx_image_to_window(game->mlx, game->img_collectible, i * TILE_SIZE, j * TILE_SIZE);
		else if (game->map[j][i] == 'P')
			mlx_image_to_window(game->mlx, game->img_player, i * TILE_SIZE, j * TILE_SIZE);
		else if (game->map[j][i] == 'E')
			mlx_image_to_window(game->mlx, game->img_exit, i * TILE_SIZE, j * TILE_SIZE);
	}
}

void	draw_map_sprites(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			render(game, j, i);
			i ++;
		}
		j ++;
	}
}
