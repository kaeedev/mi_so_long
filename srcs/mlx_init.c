/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:27:19 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/30 12:16:19 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_game	*game;
	int	i;

	if (!param)
		exit(0);
	game = (t_game *)param;
	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if(keydata.key == MLX_KEY_ESCAPE)
			close_game(param);
	}
}

void	init_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	game->mlx = mlx_init(window_width, window_height, "so_long", true);
	if (game->mlx == NULL)
		ft_error(11);
	mlx_key_hook(game->mlx, handle_keypress, game);
	mlx_close_hook(game->mlx, close_game, game);
}