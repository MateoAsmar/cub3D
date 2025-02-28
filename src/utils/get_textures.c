/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:29:24 by masmar            #+#    #+#             */
/*   Updated: 2025/02/28 12:33:53 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	verify_texture_path(char *filename)
{
	char		*ext;
	size_t		len;
	size_t		ext_len;

	if (!filename)
		return (1);
	ext = ".xpm";
	len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (len < ext_len)
		return (1);
	if (ft_strncmp(filename + len - ext_len, ext, ext_len) != 0)
		return (1);
	if (access(filename, R_OK) == -1)
		return (1);
	return (0);
}

int	getnotexture(char *s, t_model *m)
{
	char	**line;
	char	*trimmed;

	if (m->ntex == 0)
	{
		line = ft_split(s, ' ');
		if (line[2])
			return (freetab(line), cerrorp("North texture config error!"));
		trimmed = ft_strtrim(line[1], " \n\t\r");
		if (!trimmed)
			return (freetab(line),
				cerrorp("North texture config error!"));
		if (verify_file_extension(trimmed, ".xpm") == -1)
			return (ftt(line, trimmed),
				cerrorp("Invalid North texture extension!"));
		if (verify_texture_path(trimmed) != 0)
			return (ftt(line, trimmed),
				cerrorp("Invalid North texture: file missing or unreadable!"));
		m->no = ft_strdup(trimmed);
		if (m->no)
			m->ntex = 1;
		return (ftt(line, trimmed), 0);
	}
	else
		return (cerrorp("North texture config error!"));
}

int	getsotexture(char *s, t_model *m)
{
	char	**line;
	char	*trimmed;

	if (m->stex == 0)
	{
		line = ft_split(s, ' ');
		if (line[2])
			return (freetab(line), cerrorp("South texture config error!"));
		trimmed = ft_strtrim(line[1], " \n\t\r");
		if (!trimmed)
			return (freetab(line),
				cerrorp("South texture config error!"));
		if (verify_file_extension(trimmed, ".xpm") == -1)
			return (ftt(line, trimmed),
				cerrorp("Invalid South texture extension!"));
		if (verify_texture_path(trimmed) != 0)
			return (ftt(line, trimmed),
				cerrorp("Invalid South texture: file missing or unreadable!"));
		m->so = ft_strdup(trimmed);
		if (m->so)
			m->stex = 1;
		return (ftt(line, trimmed), 0);
	}
	else
		return (cerrorp("South texture config error!"));
}

int	getwstexture(char *s, t_model *m)
{
	char	**line;
	char	*trimmed;

	if (m->wtex == 0)
	{
		line = ft_split(s, ' ');
		if (line[2])
			return (freetab(line), cerrorp("West texture config error!"));
		trimmed = ft_strtrim(line[1], " \n\t\r");
		if (!trimmed)
			return (freetab(line),
				cerrorp("West texture config error!"));
		if (verify_file_extension(trimmed, ".xpm") == -1)
			return (ftt(line, trimmed),
				cerrorp("Invalid West texture extension!"));
		if (verify_texture_path(trimmed) != 0)
			return (ftt(line, trimmed),
				cerrorp("Invalid West texture: file missing or unreadable!"));
		m->we = ft_strdup(trimmed);
		if (m->we)
			m->wtex = 1;
		return (ftt(line, trimmed), 0);
	}
	else
		return (cerrorp("West texture config error!"));
}

int	getestexture(char *s, t_model *m)
{
	char	**line;
	char	*trimmed;

	if (m->etex == 0)
	{
		line = ft_split(s, ' ');
		if (line[2])
			return (freetab(line), cerrorp("East texture config error!"));
		trimmed = ft_strtrim(line[1], " \n\t\r");
		if (!trimmed)
			return (freetab(line),
				cerrorp("East texture config error!"));
		if (verify_file_extension(trimmed, ".xpm") == -1)
			return (ftt(line, trimmed),
				cerrorp("Invalid East texture extension!"));
		if (verify_texture_path(trimmed) != 0)
			return (ftt(line, trimmed),
				cerrorp("Invalid East texture: file missing or unreadable!"));
		m->ea = ft_strdup(trimmed);
		if (m->ea)
			m->etex = 1;
		return (ftt(line, trimmed), 0);
	}
	else
		return (cerrorp("East texture config error!"));
}
