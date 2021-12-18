/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:35:38 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:47:10 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_info *info, t_p *p)
{
	print(info, "is eating", p->id);
	(p->eat_cnt)++;
	philo_eat_time(info);
}

int	philo_life(t_info *info, t_p *p)
{
	pthread_mutex_lock(&(info->forks[p->left_fork]));
	print(info, "has taken, a fork", p->id);
	pthread_mutex_lock(&(info->forks[p->right_fork]));
	print(info, "has taken, a fork", p->id);
	philo_eat(info, p);
	pthread_mutex_unlock(&(info->forks[p->left_fork]));
	pthread_mutex_unlock(&(info->forks[p->right_fork]));
	if (info->eat_check)
		return (-1);
	return (0);
}

void	*pthread_run(void *p)
{
	t_p		*rp;
	t_info	*info;

	rp = (t_p *)p;
	info = rp->info;
	if (rp->id % 2)
		usleep(10000);
	while (!(info->die))
	{
		if (philo_life(info, rp))
			break ;
		print(info, "is sleeping", rp->id);
		philo_sleep_time(info);
		print(info, "is thinking", rp->id);
	}
	return (0);
}

void	philo_end(t_info *info, t_p *p, int index)
{
	while (index-- >= 0)
		pthread_join(p[index].thread_id, NULL);
	destroy_all_mutex(info, info->nop);
	free(info->philos);
	free(info->forks);
	pthread_mutex_destroy(&(info->print));
}

int	philo_start(t_info *info, t_p *philos)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->nop)
	{
		philos[i].check_d_time = get_time();
		if (pthread_create(&(philos[i].thread_id), NULL,
			pthread_run, (void *)&(philos[i])))
		{
			philo_end(info, info->philos, i);
			return (-1);
		}
		i++;
	}
	life(info, info->philos);
	philo_end(info, info->philos, i);
	return (0);
}
