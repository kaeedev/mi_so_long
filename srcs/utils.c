/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:05:27 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/21 17:27:42 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 0)
		ft_printf("Error\n");
	else if (i == 1)
		ft_printf("Error: Wrong number of arguments\n");
	else if (i == 2)
		ft_printf("Error: Map file must be a .ber file\n");
	else if (i == 3)
		ft_printf("Error: File cant open\n");
	else if (i == 4)
		ft_printf("Map is not rectangle\n");
	else if (i == 5)
		ft_printf("Map is empty\n");
	else if (i == 6)
		ft_printf("Error malloc\n");
	exit(1);
}

//Devuelve 1 si el archivo es un .ber. 0 si no lo es
int	check_filename(const char *filename)
{
	const char	*ult_oc;

	ult_oc = ft_strrchr(filename, '.');
	if (!ult_oc || ult_oc == filename)
		return (0);
	if (ft_strcmp(ult_oc, ".ber") == 0)
		return (1);
	return (0);
}