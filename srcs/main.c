/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:01:31 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/21 12:10:46 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error(1);
	if (!check_filename(argv[1]))
		ft_error(2);
	
	//Validar y leer el mapa
    // init_game(&game);
    // read_map(argv[1], &game);
    // validate_map(&game);
	return (0);
}