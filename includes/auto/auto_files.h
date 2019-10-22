/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_files.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:05:46 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 06:05:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_FILES_H
# define AUTO_FILES_H

void		ft_add_to_file(char *name, char *data);
int			ft_create_new_file(char *str);
ssize_t		ft_get_size_file(char *str);
char		*ft_read_file(int fd, int *size);

#endif
