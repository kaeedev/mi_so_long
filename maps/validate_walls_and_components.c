/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls_and_components.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:51:02 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/29 13:45:32 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
			ft_error(7);
		i ++;
	}
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[game->map_height - 1][i] != '1')
			ft_error(7);
		i ++;
	}
	j = 1;
	while (j < game->map_height - 1)
	{
		if (game->map[j][0] != '1' || game->map[j][game->map_width- 1] != '1')
			ft_error(7);
		j ++;
	}
}

void	count_components(t_game *game, int *c, int *p, int *e)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'P')
			{
				*p += 1;
				game->player_x = i;
				game->player_y = j;
			}
			else if (game->map[j][i] == 'E')
				*e += 1;
			else if (game->map[j][i] == 'C')
				*c += 1;
			else if (game->map[j][i] != '0' && game->map[j][i] != '1')
				ft_error(8);
			i ++;
		}
		j ++;
	}
}

void validate_contents(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_components(game, &collectible_count, &player_count, &exit_count);
	if (collectible_count < 1 || player_count != 1 || exit_count != 1)
		ft_error(9);
	game->collectibles = collectible_count;
}
