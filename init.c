/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:18:02 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:20:59 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phiosophers.h"

int		mutex_init(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(info->print), NULL))
		return (-1);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nop);
	if (!(info->forks))
	{
		pthread_mutex_destroy(&(info->print));
		return (-1);
	}
	while (i < info->nop)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (destroy_all_mutex(info, i - 1));
		i++;
	}
	return (0);
}

int	destroy_all_mutex(t_info *info, int index)
{
	pthread_mutex_destroy(&(info->print));
	while (index >= 0)
		pthread_mutex_destroy(&(info->forks[--index]));
	return (-1);
}

int		philo_init(t_info *info)
{
	int i;

	i = 0;
	info->philos = malloc(sizeof(t_p) * (info->nop));
	if (info->philos == NULL)
		return (-1);
	while (i < info->nop)
	{
		info->philos[i].id = i;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->nop;
		if (i % 2 == 0)
		{
			info->philos[i].left_fork = (i + 1) % info->nop;
			info->philos[i].right_fork = i;
		}
		info->philos[i].check_d_time = 0;
		info->philos[i].eat_cnt = 0;
		info->philos[i].info = info;
		i++;		
	}
	return (0);
}

int init(t_info *info)
{
	info->die = 0;
	info->eat_check = 0;
	info->start_time = 0;
	if (check_value(info) == -1)
		return (-1);
	if (mutex_init(info) == -1)
		return (-1);
	if (philo_init(info) == -1)
		return (destroy_all_mutex(info, info->nop));
	return (0);
}
