/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:45:21 by mmasyush          #+#    #+#             */
/*   Updated: 2018/12/18 19:47:04 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	stop(void)
{
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file;
	t_write	*out;

	out = ft_memalloc(sizeof(t_write));
	if (argc == 2)
	{
		file = argv[1];
		if (read_file(out, file) == 0)
		{
			ft_putstr("Wrong input");
			return (0);
		}
		if (start(out) == 0)
		{
			ft_putstr("Fail:(");
			return (0);
		}
	}
	ft_putstr("Error");
	return (0);
}
