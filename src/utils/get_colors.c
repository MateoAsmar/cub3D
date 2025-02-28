/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:59:48 by masmar            #+#    #+#             */
/*   Updated: 2025/02/27 16:29:00 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	getsize(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (map[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	getceilingrgb(char *s, t_model *m)
{
	char	**line;
	int		size;

	if (m->c == 0)
	{
		line = ft_split(s + 1, ',');
		size = getsize(line);
		if (size != 3)
			return (freetab(line), cerrorp("Floor colors config error!"));
		if (convertcrgb(line, &m->ceiling) < 0)
		{
			freetab(line);
			return (cerrorp("Ceiling colors config error!"));
		}
		m->c = 1;
		freetab(line);
		return (0);
	}
	else
		return (cerrorp("Ceiling colors config error!"));
}

int	getfloorrgb(char *s, t_model *m)
{
	char	**line;
	int		size;

	if (m->f == 0)
	{
		line = ft_split(s + 1, ',');
		size = getsize(line);
		if (size != 3)
			return (freetab(line), cerrorp("Floor colors config error!"));
		if (convertfrgb(line, &m->floor) < 0)
		{
			freetab(line);
			return (cerrorp("Floor colors config error!"));
		}
		m->f = 1;
		freetab(line);
		return (0);
	}
	else
		return (cerrorp("Floor colors config error!"));
}
