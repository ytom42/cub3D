/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:35:12 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/01/30 17:51:22 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_all *s, int h, int w)
{
	if (s->fill_map[h][w] == 1)
		return ;
	if ((h + 1) == s->map_height || (w + 1) == s->map_width)
		end(s, 1, -1);
	else if ((h - 1) < 0 || (w - 1) < 0)
		end(s, 1, -1);
	if (s->fill_map[h + 1][w] == -1 || s->fill_map[h][w + 1] == -1)
		end(s, 1, -1);
	else if (s->fill_map[h - 1][w] == -1 || s->fill_map[h][w - 1] == -1)
		end(s, 1, -1);
	s->fill_map[h][w] = 1;
	flood_fill(s, (h + 1), w);
	flood_fill(s, h, (w + 1));
	flood_fill(s, (h - 1), w);
	flood_fill(s, h, (w - 1));
}

void	check_map(t_all *s)
{
	int i;
	int j;
	int h;
	int w;

	i = 0;
	s->fill_map = (int**)malloc(sizeof(int*) * (s->map_height + 1));
	while (i < s->map_height)
	{
		j = 0;
		s->fill_map[i] = ((int*)malloc(sizeof(int) * (s->map_width + 1)));
		while (j < s->map_width)
		{
			s->fill_map[i][j] = s->map[i][j];
			j++;
		}
		i++;
	}
	h = (int)s->pos_x;
	w = (int)s->pos_y;
	flood_fill(s, h, w);
}
