/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:46:41 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/23 15:46:41 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_getnbr(char *str)
{
	int	res;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	res = 0;
	while (*str)
	{
		res *= 10;
		res += *str - '0';
		str += 1;
	}
	return (res);
}

void	send_sign(int pid, int bit)
{
	if (bit == 0)
		if (kill(pid, SIGUSR1) == -1)
			ft_error("ERROR: Cannot send to SIGUSR1");
	if (bit == 1)
		if (kill(pid, SIGUSR2) == -1)
			ft_error("ERROR: Cannot send to SIGUSR2");
}

void	trad_sign(int pid, char to_send)
{
	char	c;
	int		bit;

	c = 0;
	while (c < 8)
	{
		bit = (to_send >> c++) & 1;
		usleep(500);
		send_sign(pid, bit);
	}
}

void	ft_treatchar(int pid, char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		trad_sign(pid, str[i]);
	trad_sign(pid, 0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		ft_error("HOW TO USE: Enter the PID in argument");
	if (verify_pid(av[1]) == 0)
		pid = ft_getnbr(av[1]);
	else
		ft_error("ERROR: Verify the PID");
	if (pid <= 1)
		ft_error("ERROR: Bad PID");
	ft_treatchar(pid, av[2]);
	return (0);
}
