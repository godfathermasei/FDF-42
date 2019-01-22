/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:10:08 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/05 13:05:32 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_press(int button, int x, int y, t_write *out)
{
	mlx_clear_window(out->mlx_ptr, out->win_ptr);
	if (button == 5)
		out->updown += 1;
	if (button == 4)
		out->updown -= 1;
	draw_scene(out);
	return (0);
}

int		key_press(int keycode, t_write *out)
{
	if (keycode == 53)
		stop();
	mlx_clear_window(out->mlx_ptr, out->win_ptr);
	if (keycode == 117 && out->fenter != 0)
		out->fenter = 0;
	move(keycode, out);
	string(keycode, out);
	perspect(keycode, out);
	mas_menos(keycode, out);
	draw_scene(out);
	return (0);
}

void	string(int keycode, t_write *out)
{
	if (keycode == 4)
	{
		mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 30, \
			0x00FFFF, "+/- == zoom");
		mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 50, \
			0xFF00FF, "Arrows == move");
		mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 70, 0x00FFFF, \
			"Mouse wheel == increase/decrease attidute");
		mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 90, 0xFF00FF, \
			"Esc == exit");
		mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 110, 0x00FFFF, \
			"Delete == default settings");
		mlx_string_put(out->mlx_ptr, out->win_ptr, 10, 130, 0xFF00FF, \
			"1, 2 == change projection");
	}
}

int		start(t_write *out)
{
	out->per = 1;
	out->mlx_ptr = mlx_init();
	out->win_ptr = mlx_new_window(out->mlx_ptr, W_X, W_Y, "MLX");
	out->fenter = 0;
	draw_scene(out);
	mlx_hook(out->win_ptr, 2, 0, key_press, out);
	mlx_hook(out->win_ptr, 4, 0, mouse_press, out);
	mlx_hook(out->win_ptr, 17, 1L << 17, stop, 0);
	mlx_loop(out->mlx_ptr);
	return (1);
}
