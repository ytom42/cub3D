/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:35:12 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/01/14 11:35:50 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	end(t_all *s)
{
	printf("-----------\n---error---\n-----------\n");
	// free s->fill_map
	s->screenWidth = 1;
	exit(0);
}

void	flood_fill(t_all *s, int h, int w)
{
	if (s->fill_map[h][w] == 1)
		return ;
	if ((h + 1) == s->map_height || (w + 1) == s->map_width)
		end(s);
	else if ((h - 1) < 0 || (w - 1) < 0)
		end(s);
	if (s->fill_map[h + 1][w] == -1 || s->fill_map[h][w + 1] == -1)
		end(s);
	else if (s->fill_map[h - 1][w] == -1 || s->fill_map[h][w - 1] == -1)
		end(s);
	s->fill_map[h][w] = 1;
	flood_fill(s, (h + 1), w);
	flood_fill(s, h, (w + 1));
	flood_fill(s, (h - 1), w);
	flood_fill(s, h, (w - 1));
}

void	check_map(t_all *s, int map_height)
{
	int i;
	int j;
	int h;
	int w;

	i = 0;
	s->fill_map = (int**)malloc(sizeof(int*) * map_height);
	while (i < s->map_height)
	{
		j = 0;
		s->fill_map[i] = ((int*)malloc(sizeof(int*) * s->map_width));
		while (j < s->map_width)
		{
			s->fill_map[i][j] = s->map[i][j];
			j++;
		}
		i++;
	}
	printf("X->%f\nY->%f\n", s->posX, s->posY);
	h = (int)s->posX;
	w = (int)s->posY;
	printf("x->%d\ny->%d\n", h, w);
	flood_fill(s, h, w);
	// free s->fill_map
}