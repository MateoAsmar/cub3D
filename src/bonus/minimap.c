/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:58:15 by masmar            #+#    #+#             */
/*   Updated: 2025/02/26 14:20:22 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
** init_linevars():
**   Helper to initialize dx, dy, sx, sy, and err for Bresenham's line.
**   Splitting it out ensures we keep draw_line() itself under 25 lines
**   and avoid excessive local variables.
*/
void	init_linevars(t_linevars *v, t_point start, t_point end)
{
	v->x = start.x;
	v->y = start.y;
	v->dx = end.x - start.x;
	if (v->dx < 0)
		v->dx = -v->dx;
	v->dy = end.y - start.y;
	if (v->dy < 0)
		v->dy = -v->dy;
	if (start.x < end.x)
		v->sx = 1;
	else
		v->sx = -1;
	if (start.y < end.y)
		v->sy = 1;
	else
		v->sy = -1;
	v->err = v->dx - v->dy;
}

/*
** draw_line():
**   Draws a line using Bresenham's algorithm.
**   - No ternaries
**   - 4 arguments: (t_game*, t_point, t_point, color)
**   - Well under 25 lines thanks to the init_linevars() helper.
*/
void	draw_line(t_game *game, t_point start, t_point end, int color)
{
	t_linevars	v;

	init_linevars(&v, start, end);
	while (1)
	{
		my_mlx_pixel_put(&game->img, v.x, v.y, color);
		if (v.x == end.x && v.y == end.y)
			break ;
		v.e2 = v.err * 2;
		if (v.e2 > -v.dy)
		{
			v.err -= v.dy;
			v.x += v.sx;
		}
		if (v.e2 < v.dx)
		{
			v.err += v.dx;
			v.y += v.sy;
		}
	}
}

/*
** get_map_height():
**   Returns how many rows your map has (null-terminated char**).
**   This function is small enough to stay under 25 lines & minimal locals.
*/
int	get_map_height(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}
