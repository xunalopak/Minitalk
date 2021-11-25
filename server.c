/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:46:39 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/23 15:46:39 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pid(void)
{
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

void	ft_write(int b_put)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (b_put << i++);
	if (i > 7)
	{
		if (c == '\n')
		{
			ft_putchar('\n');
			ft_putchar(c);
		}
		else
			ft_putchar(c);
		i = 0;
		c = 0;
	}
}

void	sig(int sign)
{
	if (sign == SIGUSR1)
		ft_write(0);
	else if (sign == SIGUSR2)
		ft_write(1);
}

void	ft_sig(void)
{
	if (signal(SIGUSR1, sig) == SIG_ERR)
		ft_error("SIGUSR1 ERROR");
	if (signal(SIGUSR2, sig) == SIG_ERR)
		ft_error("SIGUSR2 ERROR");
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		ft_error("No arguments needed");
	ft_pid();
	ft_sig();
	signal(SIGWINCH, SIG_IGN);
	while (42)
		pause();
	return (0);
}
