/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_project_.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:53:26 by ldevelle          #+#    #+#             */
/*   Updated: 2020/02/29 18:53:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_PROJECT__H
# define AUTO_PROJECT__H

int		delete_stars_on_point(t_sudo *sudo, int lin, int col);
int		delete_stars_on_lin(t_sudo *sudo, int grid, int lin, int col);
int		delete_stars_on_col(t_sudo *sudo, int grid, int lin, int col);
int		delete_stars_on_sqr(t_sudo *sudo, int grid, int lin, int col);
int		delete_stars(t_sudo *sudo, int grid, int lin, int col);
int 		check_n_column(t_sudo *sudo, int nb, int grid, int col);
int 		check_n_line(t_sudo *sudo, int nb, int grid, int lin);
int 		check_n_square(t_sudo *sudo, int nb, int grid, int lin, int col);
int 		check_n(t_sudo *sudo, int nb, int grid, int lin, int col);
int		find_n_in_sqr(t_sudo *sudo, int nb, int grid, int lin, int col);
void print_victory(void);
void print_defeat(void);
void print_victory_or_defeat(int on);
int  main(int ac, char **av);
void		ft_putchar_color(char c);
void print_ghost_grid(t_sudo *sudo, int tri);
void print_grid(t_sudo *sudo, int grid);
void wait_pls(void);
void print_grids(t_sudo *sudo);
void		*malloc_sudo(t_sudo *sudo);
t_sudo		*read_sudo(char *av);
int		write_ghosts(t_sudo *s);
int		write_ghost(t_sudo *s, int grd);
int 		check_n_square_hv(t_sudo *sudo, int nb, int grid, int big_lin, int big_col);
int 		delete_aligned_stars(t_sudo *sudo, int grid, int hv, int star, int lin, int col);
int		clr_str(t_sudo *sudo, int grid);
int		clr_strs(t_sudo *sudo);
int		slv_sqr_str(t_sudo *sudo, int grid);
int		slv_sqr_strs(t_sudo *sudo);
int		slv_pos_strs(t_sudo *sudo);
int		new_nb(t_sudo *sudo, int nb, int lin, int col);
int		brain(t_sudo *sudo);
int		add_star(t_sudo *sudo, int grid);
int		add_stars(t_sudo *sudo);

#endif
