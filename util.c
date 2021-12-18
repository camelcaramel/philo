/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:23:58 by donghwik          #+#    #+#             */
/*   Updated: 2021/12/18 20:20:56 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phiosophers.h"

static int				is_space(char c)
{
	return (c == '\t' || c == '\n' ||
				c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

static int				ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int						ft_atoi(const char *str)
{
	const char		*sp;
	int				neg;
	int				ret;

	sp = str;
	ret = 0;
	neg = 0;
	while (is_space(*sp))
		sp++;
	if (*sp == '-')
	{
		neg = 1;
		sp++;
	}
	else
	{
		if (*sp == '+')
			sp++;
	}
	while (ft_isdigit(*sp))
		ret = 10 * ret + (*sp++ - '0');
	return (neg) ? (-1) * ret : ret;
}

void	print(t_info *info, char *str, int id)
{
	pthread_mutex_lock(&(info->print));
	if (!(info->die))
	{
		printf("%lld %d ", get_time() - info->start_time, id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(info->print));
}

int		error(char *str)
{
	printf("%s\n", str);
	return (-1);
}