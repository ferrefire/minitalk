/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 15:12:34 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/07 16:17:10 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars	g_vars;

int	num_pow(int num)
{
	int	result;

	result = 1;
	while (num-- > 0)
		result *= 2;
	return (result);
}

void	print_byte(int bits[])
{
	int	ascii;
	int	i;

	ascii = 0;
	i = BIT_SIZE + 1;
	while (--i > 0)
		ascii += num_pow(BIT_SIZE - i) * bits[i - 1];
	g_vars.str = comb(g_vars.str, ft_strdup((char *)&ascii));
	if (ascii == 0)
	{
		if (g_vars.client_pid == -1)
		{
			g_vars.client_pid = ft_atoi(g_vars.str);
			free(g_vars.str);
			g_vars.str = ft_strdup("");
			kill(g_vars.client_pid, SIGUSR1);
		}
		else
		{
			g_vars.client_pid = -1;
			ft_printf("%s", g_vars.str);
			free(g_vars.str);
			g_vars.str = ft_strdup("");
		}
	}
}

void	add_bit(int signal)
{
	if (signal == SIGUSR1)
		g_vars.byte[g_vars.index] = 1;
	else if (signal == SIGUSR2)
		g_vars.byte[g_vars.index] = 0;
	else
		return ;
	g_vars.index++;
	if (g_vars.index >= BIT_SIZE)
	{
		g_vars.index = 0;
		print_byte(g_vars.byte);
	}
	if (g_vars.client_pid != -1)
		kill(g_vars.client_pid, SIGUSR1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	g_vars.client_pid = -1;
	g_vars.str = ft_strdup("");
	signal(SIGUSR1, add_bit);
	signal(SIGUSR2, add_bit);
	while (1)
		sleep(1);
	if (*g_vars.str)
		free(g_vars.str);
	exit(0);
	return (0);
}
