/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:15:58 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:55:59 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_info
{
	int	nop;
	int	ttd;
	int	tte;
	int	tts;
	int	noe;
	int	die;
	int	eat_check;
	long long start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_p	*philos;
}	t_info;

typedef struct	s_p
{
	int			id;
	int			left_fork;
	int			right_fork;
	long long	check_d_time;
	int			eat_cnt;
	t_info		*info;
	pthread_t	thread_id;
}	t_p;

int			ft_atoi(const char *str);
void		print(t_info *info, char *str, int id);
long long	get_time(void);
void		philo_sleep_time(t_info *info);
void		philo_eat_time(t_info *info);
void		eat_check(t_info *info, t_p *philo);
int			check_value(t_info *info);
void		life(t_info *info, t_p *p);
int			error(char *str);
int			mutex_init(t_info *info);
int			destroy_all_mutex(t_info *info, int index);
int			philo_init(t_info *info);
int			init(t_info *info);
void		philo_eat(t_info *info, t_p *p);
int			philo_life(t_info *info, t_p *p);
void		*pthread_run(void *p);
void		philo_end(t_info *info, t_p *p, int index);
int			philo_start(t_info *info, t_p *philos);
#endif