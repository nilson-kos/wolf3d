/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:55:39 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/07 15:41:08 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main(void)
{
	t_wf	*wf;

	wf = ft_init_wf();
	mlx_loop_hook(wf->mlx, ft_zaloop_hook, wf);
	mlx_loop(wf->mlx);
	return (0);
}
