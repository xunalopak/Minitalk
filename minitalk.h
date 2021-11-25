/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:10:56 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/24 20:10:56 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>

void	ft_error(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		verify_pid(char *pid);

#endif
