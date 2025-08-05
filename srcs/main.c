/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:01:31 by luviso-p          #+#    #+#             */
/*   Updated: 2025/08/05 13:33:06 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		ft_error(1);
	if (!check_filename(argv[1]))
		ft_error(2);
	ft_bzero(&game, sizeof(t_game)); //inicializo todos los campos de la estructura a 0
	read_map_file(argv[1], &game); //leer el archivo del mapa (.ber)
	validate_walls(&game); //validar si el mapa esta rodeado de muros
	validate_contents(&game); //validar los contenidos, si hay salida, player, al menos un colecionable...
	validate_path(&game); //validar si el camino es valido
	init_mlx(&game); //iniciar/cerrar la ventana del juego y controlar los eventos de teclado
	load_sprites(&game); //cargar sprites
	draw_map_sprites(&game); //dibujar los sprites en el mapa
	mlx_loop(game.mlx); //bucle infinito para que no se cierre el juego hasta q no se le de a ESC 
	return (0);
}
