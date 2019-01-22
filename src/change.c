/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:23:15 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/05 19:23:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mas_menos(int keycode, t_write *out)
{
	if (keycode == 78 && out->x_step / 1.5 > 1 && out->y_step / 1.5 > 1 &&
		(-out->shift / 1.5 >= 0 || out->shift / 1.5 >= 0))
	{
		out->x_step /= 1.5;
		out->y_step /= 1.5;
		out->shift /= 1.5;
	}
	if (keycode == 69 && out->x_step * 1.5 <= 1420 && out->y_step * 1.5 <= 1420)
	{
		out->x_step *= 1.5;
		out->y_step *= 1.5;
		out->shift *= 1.5;
	}
}

void	move(int keycode, t_write *out)
{
	if (keycode == 126)
		out->start_y -= 20;
	if (keycode == 125)
		out->start_y += 20;
	if (keycode == 124)
		out->start_x += 20;
	if (keycode == 123)
		out->start_x -= 20;
}

void	perspect(int keycode, t_write *out)
{
	if (keycode == 18 || keycode == 83)
		out->per = 1;
	if (keycode == 19 || keycode == 84)
		out->per = 2;
}

void	color(int x, int y, t_write *out)
{
	int i;

	i = out->updown;
	if (out->map[y][x] * i > 0 && out->map[y][x] * i < 200)
		out->color = 0x00FF00;
	else if (out->map[y][x] * i >= 200)
		out->color = 0xFF8000;
	else if (out->map[y][x] * i < 0 && out->map[y][x] * i > -100)
		out->color = 0xFFFF00;
	else if (out->map[y][x] * i <= -100)
		out->color = 0x00FFFF;
	else
		out->color = 0x404040;
}

void	fill(t_write *out)
{
	if (out->fenter++ == 0)
	{
		out->start_x = 500;
		out->start_y = 500;
		out->y_step = 20;
		out->x_step = 30;
		out->shift = 10;
		out->updown = 4;
	}
}
