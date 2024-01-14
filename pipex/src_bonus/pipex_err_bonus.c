/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_err_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:03:17 by achahid-          #+#    #+#             */
/*   Updated: 2024/01/13 18:03:21 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

/**
 * ft_error_print - print an error message to stderr
 * @msg: message to print
 * Return: exit program execution with status of 1.
*/
int	ft_error_print(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

/**
 * ft_exit_failure - exit the program execution with error
 * Return: exit status
*/
int	ft_error_exit(void)
{
	perror("\033[31mError pipex");
	exit(1);
}
