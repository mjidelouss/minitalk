/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:02:37 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/17 20:41:46 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_byte(char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int ac, char *av[])
{
	char	*str;
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr("INCORRECT ARGUMENTS");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	while (*str)
	{
		send_byte(*str, pid);
		str++;
	}
	send_byte(0, pid);
	return (0);
}
