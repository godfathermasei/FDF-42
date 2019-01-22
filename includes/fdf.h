/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:40:43 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/05 12:40:06 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define W_X 2000
# define W_Y 1395

typedef struct			s_write
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	int					**map;
	int					x0;
	int					x1;
	int					y0;
	int					y1;
	int					fenter;
	int					color;
	int					per;
	float				updown;
	float				shift;
	float				x_step;
	float				y_step;
	float				start_x;
	float				start_y;
}						t_write;

typedef struct			s_alg
{
	int					sigx;
	int					sigy;
	int					dx;
	int					dy;
	int					f;
	int					x;
	int					y;
}						t_alg;
/*
**main
*/
int						main(int argc, char **argv);
int						stop(void);
/*
**read
*/
int						read_file(t_write *out, char *file);
int						count(t_write *out, int fd);
int						check(char *line, t_write *out);
int						map(t_write *out, int fd);
/*
**write
*/
void					draw_scene(t_write *out);
void					x_line(t_write *out, t_alg *so);
void					y_line(t_write *out, t_alg *so);
void					chose_line(t_write *out);
/*
**keys
*/
int						start(t_write *out);
int						key_press(int keycode, t_write *out);
void					string(int keycode, t_write *out);
int						mouse_press(int button, int x, int y, \
							t_write *out);
/*
**adds
*/
void					x_count_one(t_write *out, int x, int y, int i);
void					y_count_one(t_write *out, int x, int y, int i);
void					x_count_two(t_write *out, int x, int y);
void					y_count_two(t_write *out, int x, int y);
void					mas_menos(int keycode, t_write *out);
void					color(int x, int y, t_write *out);
void					perspect(int keycode, t_write *out);
void					move(int keycode, t_write *out);
void					fill(t_write *out);

#endif
