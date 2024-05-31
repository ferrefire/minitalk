/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 15:10:22 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/07 16:20:49 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"
# define BIT_SIZE 8

typedef struct g_vars
{
	int		index;
	int		byte[BIT_SIZE];
	int		client_pid;
	char	*str;
}				t_vars;

#endif