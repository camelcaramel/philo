/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:16:04 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:21:26 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phiosophers.h"

int main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 5 || argc == 6 )
	{
		info.nop = ft_atoi(argv[1]);
		info.ttd = ft_atoi(argv[2]);
		info.tte = ft_atoi(argv[3]);
		info.tts = ft_atoi(argv[4]);
		info.noe = -1;
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (error("Error!\n"));
		info.noe = ft_atoi(argv[5]);
	}
	if (argc != 5 && argc != 6)
		return (error("Error!\n"));
	if (init(&info) == -1)
		return (error("Error!\n"));
	philo_start(&info, info.philos);
	while(1);
	return (0);
}