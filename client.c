/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:16:28 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/09 13:12:07 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	j = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	while (str[i] <= 32)
		i++;
	return (res * j);
}

void	biting(int get_id, char *s)
{
	int		j;
	int		i;
	char	c;

	j = 0;
	while (s[j])
	{
		i = 0;
		c = s[j];
		while (i < 8)
		{
			if (c & 1 << i)
				kill(get_id, SIGUSR1);
			else
				kill(get_id, SIGUSR2);
			usleep(100);
		i++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	get_id;

	get_id = 0;
	if (ac == 3)
	{
		get_id = ft_atoi(av[1]);
		biting(get_id, av[2]);
	}
	return (0);
}
