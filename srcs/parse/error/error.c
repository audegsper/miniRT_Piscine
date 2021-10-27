/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:07:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 00:13:04 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_param(void)
{
	errno = 22;
	perror("errno 22");
	write(STDERR_FILENO, "Error\n", 6);
	exit(INVALID);
}

void	e_file_open(void)
{
	errno = 9;
	perror("errno 9");
	write(STDERR_FILENO, "Error\n", 6);
	exit(INVALID);
}

void	e_file_read(int fd)
{
	errno = 45;
	perror("errno 45");
	write(STDERR_FILENO, "Error\n", 6);
	close(fd);
	exit(INVALID);
}

void	e_identifier(void **ptr, int fd)
{
	errno = 79;
	perror("errno 79");
	write(STDERR_FILENO, "Error\n", 6);
	free_ptr(ptr);
	close(fd);
	exit(INVALID);
}

void	e_condition_value(void **ptr, int fd)
{
	errno = 79;
	perror("errno 79");
	write(STDERR_FILENO, "Error\n", 6);
	free_ptr(ptr);
	close(fd);
	exit(INVALID);
}
