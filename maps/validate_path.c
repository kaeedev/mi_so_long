/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:54:19 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/28 13:51:54 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		j;
	int		k;

	map_copy = ft_calloc((game->map_height + 1), sizeof(char *));
	if (!map_copy)
		ft_error(6);
	j = 0;
	while (j < game->map_height - 1)
	{
		map_copy[j] = ft_strdup(game->map[j]);
		if (!map_copy[j])
		{
			k = 0;
			while (k < j)
			{
				free(map_copy[k]);
				k ++;
			}
			free(map_copy);
			ft_error(6);
		}
		j ++;
	}
	return (map_copy);
}

void	flood_fill(char **map_copy, int x, int y, t_game *game)
{
	char	current_pos;

	current_pos = map_copy[y][x];
	if ( x < 0 || y < 0 || x >= game->map_width || y >= game->map_height 
		|| map_copy[y][x] == '1')
			return ;
	map_copy[y][x] = '1';
	if (current_pos == 'E')
		return ;
	flood_fill(map_copy, x + 1, y, game);
	flood_fill(map_copy, x - 1, y, game);
	flood_fill(map_copy, x, y + 1, game);
	flood_fill(map_copy, x, y - 1, game);
}