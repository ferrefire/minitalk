/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 13:42:19 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 15:53:03 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!((c > 64 && c < 91) || (c > 96 && c < 123)))
		return (0);
	return (1);
}
