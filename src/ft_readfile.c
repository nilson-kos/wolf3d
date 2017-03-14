/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:34:57 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/13 15:11:52 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		print_error(void)
{

	ft_putstr("can not open file\n");
	exit(0);
}

void		ft_count(t_wf *wf)
{
	char	*line;

	if ((wf->read.fd = open("maps/1lvl.map", O_RDONLY)) == -1)
		print_error();
	while (get_next_line(wf->read.fd, &line) > 0)
	{
		while (line[wf->read.w])
		{
			if (wf->count == 0)
				wf->read.w++;
		}
		wf->count++;
		free(line);
	}
	close(wf->read.fd);
}

char		**ft_readfile(t_wf *wf)
{
	char	*line;
	char	**mass;

	ft_count(wf);
	if ((wf->read.fd = open("maps/1lvl.map", O_RDONLY)) == -1)
		print_error();
	mass = (char **)malloc(sizeof(char*) * (wf->count + 1));
	while (get_next_line(wf->read.fd, &line) > 0)
	{
		//mb +1 ne nado
		mass[wf->read.i] = ((char *)malloc(sizeof(char) * (wf->read.w + 1)));
		while (line[wf->read.c] != '\0')
		{
			mass[wf->read.i][wf->read.j] = line[wf->read.c];
			wf->read.c++;
			wf->read.j++;
		}
		mass[wf->read.i][wf->read.j] = '\0';
		wf->read.j = 0;
		wf->read.c = 0;
		wf->read.i++;
		free(line);
	}
	mass[wf->count] = 0;
	close(wf->read.fd);
	return (mass);
}
