/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:48:01 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:18:27 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phiosophers.h"

long long	get_time()
{
	struct timeval cur_time;
	long long		time_ms;
	gettimeofday(&cur_time, NULL);
	time_ms = (cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000);
	return (time_ms);
}

void	philo_sleep_time(t_info *info)
{
	long long 	tts;
	long long	start;
	long long	cur;

	tts = (long long)(info->tts);
	start = get_time();
	while (!(info->die))
	{
		cur = get_time();
		if ((cur - start) >= tts)
			break;
		usleep(10);
	}
}

void	philo_eat_time(t_info *info)
{
	long long 	tte;
	long long	start;
	long long	cur;

	tte = (long long)(info->tte);
	start = get_time();
	while (!(info->die))
	{
		cur = get_time();
		if ((cur - start) >= tte)
			break;
		usleep(10);
	}
}