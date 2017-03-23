/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:55:39 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/23 17:11:06 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		print_map(t_wf *wf)
{
	int		i;

	i = 0;
	while (wf->tmp1[i] != 0)
	{
		ft_putendl(wf->lvl1[i]);
		i++;
	}
}

int			main(void)
{
	t_wf	*wf;

	wf = ft_init_wf();
	wf->lvl1 = ft_readfile(wf);
	wf->count = 0;
	wf = ft_init_flag_menu(wf);
	wf->tmp1 = ft_readfile(wf);
	print_map(wf);
	mlx_loop_hook(wf->mlx, ft_zaloop_hook, wf);
	mlx_loop(wf->mlx);
	return (0);
}
