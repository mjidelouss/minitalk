/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:02:47 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/17 20:41:32 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_handler(int mysig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	x;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		x = 0;
		i = 0;
		pid = 0;
	}
	mysig -= SIGUSR1;
	x = x << 1 | mysig;
	i++;
	if (i == 8)
	{
		ft_putchar(x);
		i = 0;
		x = 0;
		pid = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &my_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		sleep(1);
}
