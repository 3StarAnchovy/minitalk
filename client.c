/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:55:04 by jihong            #+#    #+#             */
/*   Updated: 2022/06/18 04:19:03 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test_handler(int sig)
{
	sig = 0;
	write(1, "ok!\n", 5);
}

void	null_str(int pid)
{
	int	byte;

	byte = 8;
	while (byte --)
	{
		kill(pid, SIGUSR2);
		usleep(800);
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	byte;

	signal(SIGUSR1, &test_handler);
	i = 0;
	if (argc < 3)
		return (write(1, "wrong input\n", 13), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (write(1, "wrong pid\n", 11), 0);
	while (argv[2][i])
	{
		byte = 8;
		while (byte --)
		{
			if (argv[2][i] & (1 << byte))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i ++;
	}
	null_str(pid);
}
