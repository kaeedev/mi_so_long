/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:25:24 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/05 13:36:53 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//mover hacia arriba con W
void	move_up(t_game *game)
{
	int		nuevo_y;
	char	next_position;

	nuevo_y = game->player_y - 1;
	next_position = game->map[nuevo_y][game->player_x];
	if (next_position == '1')
		return ;
	if (next_position == 'C')
	{
		game->collectibles --;
		game->map[nuevo_y][game->player_x] = '0';
	}
	if (next_position == 'E')
	{
		if (game->collectibles == 0)
			close_game(game);
		else
			return ;
	}
	game->map[game->player_y][game->player_x] = '0'; //pone la casilla anterior del jugador a 0 (suelo)
	game->player_y = nuevo_y; //nueva posicion y del player
	game->map[game->player_y][game->player_x] = 'P'; //colocar al player en la nueva posicion en el mapa
	game->moves ++;
	printf("Número de movimientos: %d\n", game->moves);
	draw_map_sprites(game);
}
//mover hacia abajo con S
void	move_down(t_game *game)
{
	int		nuevo_y;
	char	next_position;

	nuevo_y = game->player_y + 1;
	next_position = game->map[nuevo_y][game->player_x];
	if (next_position == '1')
		return ;
	if (next_position == 'C')
	{
		game->collectibles --;
		game->map[nuevo_y][game->player_x] = '0';
	}
	if (next_position == 'E')
	{
		if (game->collectibles == 0)
			close_game(game);
		else
			return ;
	}
	game->map[game->player_y][game->player_x] = '0'; //pone la casilla anterior del jugador a 0 (suelo)
	game->player_y = nuevo_y; //nueva posicion y del player
	game->map[game->player_y][game->player_x] = 'P'; //colocar al player en la nueva posicion en el mapa
	game->moves ++;
	printf("Número de movimientos: %d\n", game->moves);
	draw_map_sprites(game);
}
//mover a la izquierda con A
void	move_left(t_game *game)
{
	int		nuevo_x;
	char	next_position;

	nuevo_x = game->player_x - 1;
	next_position = game->map[game->player_y][nuevo_x];
	if (next_position == '1')
		return ;
	if (next_position == 'C')
	{
		game->collectibles --;
		game->map[game->player_y][nuevo_x] = '0';
	}
	if (next_position == 'E')
	{
		if (game->collectibles == 0)
			close_game(game);
		else
			return ;
	}
	game->map[game->player_y][game->player_x] = '0'; //pone la casilla anterior del jugador a 0 (suelo)
	game->player_x = nuevo_x; //nueva posicion y del player
	game->map[game->player_y][game->player_x] = 'P'; //colocar al player en la nueva posicion en el mapa
	game->moves ++;
	printf("Número de movimientos: %d\n", game->moves);
	draw_map_sprites(game);
}
//mover a la derecha con D
void	move_right(t_game *game)
{
	int		nuevo_x;
	char	next_position;

	nuevo_x = game->player_x + 1;
	next_position = game->map[game->player_y][nuevo_x];
	if (next_position == '1')
		return ;
	if (next_position == 'C')
	{
		game->collectibles --;
		game->map[game->player_y][nuevo_x] = '0';
	}
	if (next_position == 'E')
	{
		if (game->collectibles == 0)
			close_game(game);
		else
			return ;
	}
	game->map[game->player_y][game->player_x] = '0'; //pone la casilla anterior del jugador a 0 (suelo)
	game->player_x = nuevo_x; //nueva posicion y del player
	game->map[game->player_y][game->player_x] = 'P'; //colocar al player en la nueva posicion en el mapa
	game->moves ++;
	printf("Número de movimientos: %d\n", game->moves);
	draw_map_sprites(game);
}