/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:27:19 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/05 13:36:11 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
//funcion para cerrar el juego
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
//funcion para detectar los eventos de teclado
void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if(keydata.key == MLX_KEY_ESCAPE)
			close_game(param);
		else if (keydata.key == MLX_KEY_W)
			move_up(game);
		else if (keydata.key == MLX_KEY_A)
			move_left(game);
		else if (keydata.key == MLX_KEY_S)
			move_down(game);
		else if (keydata.key == MLX_KEY_D)
			move_right(game);
	}
}
//funcion para controlar la ventana. Abrirla o cerrarla y que se apliquen los eventos de teclado
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