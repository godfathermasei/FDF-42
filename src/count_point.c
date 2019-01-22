/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:54:17 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/05 13:54:19 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	x_count_one(t_write *out, int x, int y, int i)
{
	out->x0 = out->start_x + (x * out->x_step) + \
		(y * out->shift);
	out->y0 = out->start_y + (y * out->y_step * 2) - \
		(i * out->y_step) - out->map[y][x] * out->updown;
	out->x1 = out->start_x + ((x + 1) * out->x_step) + \
		(y * out->shift);
	out->y1 = out->start_y + (y * out->y_step * 2) - \
		((i + 1) * out->y_step) - out->map[y][x + 1] * out->updown;
	color(x, y, out);
	chose_line(out);
}

void	y_count_one(t_write *out, int x, int y, int i)
{
	out->x0 = out->start_x + (x * out->x_step) + \
		(y * out->shift);
	out->y0 = out->start_y + (y * out->y_step * 2) - \
		(i * out->y_step) - out->map[y][x] * out->updown;
	out->x1 = out->start_x + (x * out->x_step) + \
		((y + 1) * out->shift);
	out->y1 = out->start_y + ((y + 1) * out->y_step * 2) - \
		(i * out->y_step) - out->map[y + 1][x] * out->updown;
	color(x, y, out);
	chose_line(out);
}

void	x_count_two(t_write *out, int x, int y)
{
	out->x0 = out->start_x + (x * out->x_step) -
	(y * out->shift * 2);
	out->y0 = out->start_y + (y * out->y_step) -
	out->map[y][x] * out->updown;
	out->x1 = out->start_x + ((x + 1) * out->x_step) -
	(y * out->shift * 2);
	out->y1 = out->start_y + (y * out->y_step) -
	out->map[y][x + 1] * out->updown;
	color(x, y, out);
	chose_line(out);
}

void	y_count_two(t_write *out, int x, int y)
{
	out->x0 = out->start_x + (x * out->x_step) -
	(y * out->shift * 2);
	out->y0 = out->start_y + (y * out->y_step) -
	out->map[y][x] * out->updown;
	out->x1 = out->start_x + (x * out->x_step) -
	((y + 1) * out->shift * 2);
	out->y1 = out->start_y + ((y + 1) * out->y_step) -
	out->map[y + 1][x] * out->updown;
	color(x, y, out);
	chose_line(out);
}
