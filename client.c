/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <mimoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/02/25 12:10:39 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	sendchar(pid_t pid, char c)
{
	int	sent;

	sent = 0;
	while (sent < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("Error sending signal\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("Error sending signal\n");
		}
		c <<= 1;
		usleep(300);
		sent++;
	}
}

void	sendstr(pid_t pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		sendchar(pid, str[i]);
		i++;
	}
	sendchar(pid, '\0');
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sendstr(pid, argv[2]);
	}
	else
	{
		ft_printf("How to Launch: ./client [PIDserver] \"[string to send]\"\n");
	}
	return (0);
}
