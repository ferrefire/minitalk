/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 15:12:46 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/07 16:24:21 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received;

int	num_pow(int num)
{
	int	result;

	result = 1;
	while (num-- > 0)
		result *= 2;
	return (result);
}

void	receive_signal(int signal)
{
	if (signal != SIGUSR1)
		return ;
	if (g_received == 0)
		g_received = 1;
}

void	send_byte(int num, int pid)
{
	int	i;

	i = BIT_SIZE - 1;
	while (i >= 0)
	{
		if (g_received == 1)
			g_received = 0;
		if (num >= num_pow(i))
		{
			num -= num_pow(i);
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		i--;
		if (g_received == -1)
			usleep(500);
		while (g_received == 0)
			sleep(1);
	}
}

void	send_client_pid(int pid)
{
	char	*client_pid;
	int		i;

	i = 0;
	signal(SIGUSR1, receive_signal);
	client_pid = ft_itoa(getpid());
	while (*(client_pid + i))
	{
		send_byte(*(client_pid + i), pid);
		i++;
		usleep(500);
	}
	free(client_pid);
	send_byte(0, pid);
	g_received = 0;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	g_received = -1;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	send_client_pid(pid);
	i = 1;
	while (++i < argc)
	{
		j = 0;
		while (*(argv[i] + j))
		{
			send_byte(*(argv[i] + j), pid);
			j++;
		}
	}
	g_received = -1;
	send_byte(0, pid);
	exit(0);
	return (0);
}
