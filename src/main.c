/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:36:46 by fdahouk           #+#    #+#             */
/*   Updated: 2025/02/26 14:13:00 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game.keys, 0, sizeof(game.keys));
	if (validate_arguments(argc, argv) != 0)
		return (-1);
	if (check_file_exists(argv[1]) != 0)
		return (-1);
	if (init_configuration(&game, argv[1]) != 0)
		return (-1);
	if (setup_game(&game) != 0)
		return (-1);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
