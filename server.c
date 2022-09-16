/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:52:55 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/09 13:10:19 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	leangt(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = leangt(n);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
	{
		ptr[len - 1] = write(1, "0", 1);
		return (ptr);
	}
	while (n != 0)
	{
		ptr[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (ptr);
}

void	ft_putstr(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	myhandler(int sigtype)
{
	static char	bit;
	static int	octet;

	if (sigtype == SIGUSR1)
	{
		bit |= (1 << octet);
		octet++;
	}
	else
		octet++;
	if (octet == 8)
	{
		write (1, &bit, 1);
		octet = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid_t;
	char				*pid;

	pid_t = getpid();
	pid = ft_itoa(pid_t);
	ft_putstr("SERVER PID : ");
	ft_putstr(pid);
	free(pid);
	action.sa_handler = myhandler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
