/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:09 by mimoreir          #+#    #+#             */
/*   Updated: 2023/02/25 12:14:01 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>

void	sig_handler(int sig)
{
	static int	received = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
	{
		c |= 1 << (7 - received);
		received++;
	}
	else
	{
		received++;
	}
	if (received == 8)
	{
		if (c == 0)
		{
			ft_putchar_fd('\n', 1);
		}
		else
			ft_putchar_fd(c, 1);
		c = '\0';
		received = 0;
	}
}

int	main(void)
{
	int					p_id;
	struct sigaction	sigact;

	sigact.sa_flags = 0;
	sigact.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	p_id = (int)getpid();
	ft_printf("%d\n", p_id);
	while (1)
		pause();
	return (0);
}
