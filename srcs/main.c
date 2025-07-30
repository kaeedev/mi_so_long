/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:01:31 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/30 13:47:11 by luviso-p         ###   ########.fr       */
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
	ft_bzero(&game, sizeof(t_game));
	read_map_file(argv[1], &game);
	validate_walls(&game);
	validate_contents(&game);
	validate_path(&game);
	init_mlx(&game);
	load_sprites(&game);
	draw_map_sprites(&game);
	mlx_loop(game.mlx);
	return (0);
}
