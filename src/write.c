/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:45:39 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/05 13:04:33 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	chose_line(t_write *out)
{
	t_alg *so;

	so = ft_memalloc(sizeof(t_write));
	so->dx = abs(out->x1 - out->x0);
	so->dy = abs(out->y1 - out->y0);
	so->sigx = out->x1 >= out->x0 ? 1 : -1;
	so->sigy = out->y1 >= out->y0 ? 1 : -1;
	mlx_pixel_put(out->mlx_ptr, out->win_ptr, out->x0, out->y0, out->color);
	so->x = out->x0;
	so->y = out->y0;
	if (so->dy <= so->dx)
		x_line(out, so);
	else
		y_line(out, so);
}

void	x_line(t_write *out, t_alg *so)
{
	so->f = -so->dx;
	while (so->x != out->x1 || so->y != out->y1)
	{
		mlx_pixel_put(out->mlx_ptr, out->win_ptr, so->x, so->y, out->color);
		so->x += so->sigx;
		so->f += 2 * so->dy;
		if (so->f > 0)
		{
			so->f -= 2 * so->dx;
			so->y += so->sigy;
		}
	}
	free(so);
}

void	y_line(t_write *out, t_alg *so)
{
	so->f = -so->dy;
	while (so->x != out->x1 || so->y != out->y1)
	{
		mlx_pixel_put(out->mlx_ptr, out->win_ptr, so->x, so->y, out->color);
		so->y += so->sigy;
		so->f += 2 * so->dx;
		if (so->f > 0)
		{
			so->f -= 2 * so->dy;
			so->x += so->sigx;
		}
	}
	free(so);
}

void	draw_scene(t_write *out)
{
	int x;
	int y;
	int i;

	y = -1;
	fill(out);
	mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 10, \
		0xFFD700, "Press 'H' to see hints");
	while (++y < out->height)
	{
		x = -1;
		i = 0;
		while (++x < out->width)
		{
			if (x < out->width - 1)
				out->per == 1 ? x_count_one(out, x, y, i) \
					: x_count_two(out, x, y);
			if (y < out->height - 1)
				out->per == 1 ? y_count_one(out, x, y, i) \
					: y_count_two(out, x, y);
			i++;
		}
	}
}
