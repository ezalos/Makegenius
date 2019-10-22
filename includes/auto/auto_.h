/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:05:46 by ldevelle          #+#    #+#             */
/*   Updated: 2019/10/22 06:05:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO__H
# define AUTO__H

void		refresh_package(t_god *god, int nb_finish);
int			get_len_path(t_god *god);
void		add_path_to_set(t_god *god, int path);
void		save_actual_set(t_god *god, int nb_paths, int nb_of_turn);
int			find_link(t_lemin *tmp);
int			find_pv_link(t_god *god, t_lemin *tmp, t_piles *stack);
int			is_it_connected(t_god *god, int room1, int room2);
void		creat_surcharged_link(t_god *god, int room1, int room2);
int			which_link_is_surcharged(t_god *god, t_ints path);
void		add_gone(t_god *god, int nb_paths);
void		gone_is_zero(t_god *god, t_piles *stack, t_ints new_p, int id);
void		gone_is_one(t_god *god, t_piles *stack, t_ints new_p, int id);
void		init_stack(int size, t_piles *stack, int id);
int			reset_this_set(t_god *god, int nb_finish);
void		sort_t_ints(t_ints *set_of_paths, int nb_of_paths);
int			send_using_n_path(t_god *god, t_ints *set_of_paths, int quant);
int			ft_evaluate_set_of_path(t_god *god, int nb_paths);
int			evaluate_set_of_path(t_god *god, t_ints *set_of_paths, int nb_paths);
void		clean_final_path(t_god *god);
t_print			*init_print(void);
void		print_whole_buffer(t_print *print);
void		add_to_buffer(t_print *print, char *str);
void		print_buffer_with_refresh(t_print *print);
void		fill_line_buffer(t_print *print, char *nb, char *name);
int			get_len_actual_path(t_visu *visu, int i);
void		calculate_coord_last_room(t_visu *visu);
void		calculate_coord(t_visu *visu, int i, int j);
void		calculate_coord_firsts_rooms(t_visu *visu);
void		init_new_coord(t_visu *visu);
void		clear_data(t_god *god);
void		clean_surcharged_tab(t_ints tab);
void		clear_gone(t_god *god);
void		full_clear(t_god *god);
int			moove_one_turn(t_god *god, t_print *print);
int			push_ants(t_god *god, int *genome,
		int *waiting_ant, t_print *print);
int			*init_waiting_tab(t_god *god);
int			display_result_suit(t_god *god, int *tmp, int *t_ants);
int			display_result(t_god *god);
void		add_buffer(t_print *print, char *str);
void		display_all_in_one(t_god *god, int t_ants);
		int *const flags);
int			get_rid_of_dead_ends(t_god *god);
size_t		hash(char *key, size_t key_length);
void		hashtable_deinit(t_hashtable *hashtable);
void		hashtable_expand_append(t_hashtable *hashtable,
		t_hashelement *element);
void		hashtable_expand(t_hashtable *hashtable);
t_hashtable		*hashtable_init(void);
t_hashelement		*hashelement_init_param(void *data,
		void *key, size_t key_length);
void		hashtable_append(t_hashtable *hashtable,
		void *data, void *key, size_t key_length);
void		*hashtable_value(t_hashtable
		*hashtable, void *key, size_t key_length);
void		init_used_tab(t_god *god);
int			init_suit(t_god *god, t_print *print);
int			init(t_god *god);
int			is_it_link_part(char *str);
int			check_room_parsing_suit(char *str, int i, int step);
int			check_room_parsing(t_print *print, char *str);
int			check_link_parsing(t_print *print, char *str);
int			order_my_little_connexions(t_god *god);
void		get_rooms_in_tab(t_god *god);
int			link_rooms(t_tab *lem_in, char *line,
int			parse_links(t_god *god, t_print *print, char *line);
int			parse_rooms(t_god *god, t_print *print, char *line);
int			parse_extremity(t_god *god, t_print *print, int place, char *line);
int			parse_ants(t_god *god, t_print *print);
int			add_rooms(t_god *god, int place, char *line);
void		clear_links(t_god *god);
void		clear_tmp_links(t_god *god);
void		set_link(t_god *god, int r1, int r2);
void		add_surcharged_link(t_god *god);
void		refresh_tmp_links(t_god *god);
int			traversal_tree_search(t_god *god, t_data *daddy, int depth);
int			update_last_room(t_god *god, t_data *here);
int			ultimate_dispatch_room(t_god *god);
void		choose_best_solution(t_god *god);
void		loulou(t_god *god);
t_data		*create_branch(t_lemin *room);
void		add_to_tree(t_data *daddy, t_data *baby, int mode);
void		save_to_tree(t_data *daddy, t_lemin *room, int mode);
void		free_elmnt(t_data *branch);
void		free_tree(t_data *daddy);
int			is_room_searched(t_data *baby, int id);
int			is_room_valid_base(t_god *god, t_lemin *room, t_data *baby);
int			is_used_room_valid(t_god *god, t_lemin *room, t_data *baby);
int			is_unused_room_valid(t_god *god, t_lemin *room, t_data *baby);
int			is_connec_available(t_lemin *room, int connec);
int			room_compare(t_lemin *one, t_lemin *two);
void		room_connexions_sort(t_lemin *here);
t_ints		*malloc_paths(t_god *god);
int			write_path(t_god *god, t_lemin *here, t_ints path);
void		save_solution(t_god *god, t_data *daddy);
void		block_path_connections(t_god *god, t_ints path);
void		extract_paths(t_god *god);
int			search_unused_rooms(t_god *god, t_data *possibility_tree);
int			search_used_rooms(t_god *god, t_data *possibility_tree);
int			special_cases(t_god *god, t_data *possibility_tree);
int			search_a_path(t_god *god, t_data *possibility_tree);
void		clean_search(t_god *god);
void		clean_gone(t_god *god);
void		reset_all(t_god *god);
void		save_yoyo(t_god *god);
int			find_connec_id(t_god *god, int from, int to);
int			clean_error(void);
double		total_time_prog(void);
void		create_data(t_god *god);
void		check_possible_trigger(t_god *god,
		t_ints last_p, t_piles *stack);
int			get_next_rooms(t_god *god, t_piles *stack,
		t_ints lp, t_ints new_p);
int			get_faster_path(t_god *god);
int			breadth_first_search(t_god *god, int *stat);
int			next_is_it_trigger(t_god *god, int room);
int			basic_test_do_trigger(t_god *god, t_lemin *room, int j);
void		do_the_trigger(t_lemin *room, t_ints tab, int j);
int			test_g_one(t_god *god, t_lemin *room, int j);
int			zero_tst(t_god *god, t_lemin *room, int j);
int			how_many_entries_exits(t_god *god);
void		print_room_infos(t_god *god);
void		print_this_path(t_god *god, t_ints path);
void		print_final_paths(t_god *god);
int			print_header_stat(char *name, int *tab, int size, int step);
int			print_step(int *x, int quant, int seuil, int len);
void		print_tab(char *name, int *tab, int step, int size);
int			check_start_to_end(t_god *god);
int			full_process(t_god *god);
void		init_paths(t_god *god);
int			lets_calcul(t_god *god);
long		ft_atol(char *src);
int			get_max_room_in_path(t_god *god);
int			init_visu_paths(t_god *god, t_visu *visu);
int			ft_setup_visu(t_god *god);

#endif
