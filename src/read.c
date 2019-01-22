/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:16:22 by mmasyush          #+#    #+#             */
/*   Updated: 2018/12/19 15:33:19 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	map(t_write *out, int fd)
{
	char	*line;
	char	**temp;
	int		ret;
	int		coord[2];

	coord[0] = 0;
	out->map = ft_memalloc(sizeof(int*) * out->height);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		coord[1] = 0;
		temp = ft_strsplit(line, ' ');
		out->map[coord[0]] = ft_memalloc(sizeof(int) * out->width);
		while (temp[coord[1]] != NULL)
		{
			out->map[coord[0]][coord[1]] = ft_atoi(temp[coord[1]]);
			free(temp[coord[1]]);
			coord[1]++;
		}
		free(temp);
		free(line);
		coord[0]++;
	}
	if (ret == -1)
		return (0);
	return (1);
}

int	check(char *line, t_write *out)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			line[i]++;
		else if (line[i] != '-' && (line[i] < '0' || line[i] > '9'))
		{
			free(line);
			return (0);
		}
		i++;
	}
	return (1);
}

int	count(t_write *out, int fd)
{
	char	**temp;
	char	*line;
	int		ret;
	int		i;

	out->width = 0;
	out->height = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		temp = ft_strsplit(line, ' ');
		i = -1;
		while (temp[++i])
			free(temp[i]);
		free(temp);
		if (!(check(line, out)))
			return (0);
		free(line);
		if (out->height == 0)
			out->width = i;
		else if (i != out->width)
			return (0);
		out->height++;
	}
	return (1);
}

int	read_file(t_write *out, char *file)
{
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (get_next_line(fd, &line) < 1)
		return (0);
	free(line);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(count(out, fd)))
		return (0);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(map(out, fd)))
		return (0);
	close(fd);
	return (1);
}
