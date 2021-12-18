/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:55:37 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:21:29 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phiosophers.h"

void	eat_check(t_info *info, t_p *philo)
{
	int 	i;
	
	i = 0;
	while (info->noe != -1 && i < info->nop && philo[i].eat_cnt > info->noe)
		i++;
	if (i == info->nop)
		info->eat_check = 1;
}

int	check_value(t_info *info)
{
	return (info->nop >= 2 && info->nop <= 200 
		&& info->ttd >= 60 && info->tte >= 60 && info->tts >= 60);
}

void	die(char *str, t_info *info, int index)
{
	print(info, str, index);
	info->die = 1;
}

void	life(t_info *info, t_p *p)
{
	int	i;

	while (!(info->eat_check))
	{
		i = 0;
		while ((i < info->nop) && (!(info->die)))
		{
			if ((get_time() - p[i].check_d_time) > info->ttd)
				die("died", info, i);
			i++;
		}
		if (info->die)
			break;
		eat_check(info, info->philos);
	}
}