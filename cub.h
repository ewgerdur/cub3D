#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./mlxlinux/mlx.h"
# define CUB 64

typedef struct s_iparc
{
	int				r_x;
	int				r_y;
	int				f1;
	int				f2;
	int				f3;
	int				c1;
	int				c2;
	int				c3;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			**map;
	char			direct;
	int				dr;
	int				dno;
	int				dso;
	int				dwe;
	int				dea;
	int				ds;
	int				df;
	int				dc;
}				t_iparc;

typedef struct s_spt
{
	void			*s_img;
	char			*s_addr;
	int				s_bits;
	int				s_len;
	int				s_endian;
	int				img_width;
	int				img_height;
	int				flag;
	double			s_x;
	double			s_y;
	double			cnt;
	double			left;
	double			right;
	double			centre;
	double			sum_width;
	double			d_x;
	double			d_y;
	double			c_x;
	double			c_y;
	double			len_to_spt;
}				t_spt;

typedef struct s_list
{
	t_spt			aaa;
	struct s_list	*next;

}				t_list;

typedef struct s_data
{
	void			*img;
	int				bits;
	int				len;
	int				end;
	char			*adr;
	void			*t_img;
	char			*t_adr;
	int				t_bits;
	int				t_len;
	int				img_width;
	int				img_height;
}				t_data;

typedef struct s_game
{
	void			*mlx;
	void			*mlxx;
	t_data			img;
	t_iparc			map;
	t_data			txt_no;
	t_data			txt_so;
	t_data			txt_we;
	t_data			txt_ea;
	t_spt			spt;
	t_list			*sprt;
	int				f_color;
	int				c_color;
	int				flag;
	double			delta;
	double			deg_spr;
	double			scr_size;
	double			vert_x;
	double			vert_y;
	double			step_y;
	double			step_x;
	double			tex_x;
	double			tex_y;
	double			x;
	double			y;
	double			d_x;
	double			d_y;
	double			r_dir;
	double			rad;
	double			len_rey;
}				t_game;

void				print_struct(t_iparc *map);
void				*ft_free(char **arr, int c_2);
void				init_struct_map(t_iparc *map);
void				ft_init_textorsprite(char **tmp_arr,
						int count, t_iparc *map);
void				ft_c(char **tmp_arr, t_iparc *map);
void				ft_f(char **tmp_arr, t_iparc *map);
void				ft_rcf_info(char **tmp_arr, int count, t_iparc *map);
void				ft_check_val1(t_iparc *map);
void				ft_init_vertical2(t_game *game);
void				ft_val1(t_iparc *map);
void				ft_val2(t_iparc *map);
void				ft_arrer(char	*arr_info);
void				map(t_iparc *map, char *line, int fd);
int					check_valid_map_cnt(t_iparc *map, int i, int j);
void				ft_draw_hero_south(t_game *game, double *arr);
void				ft_draw_hero_north(t_game *game, double *arr);
void				ft_draw_hero_west(t_game *game, double *arr);
void				ft_draw_hero_east(t_game *game, double *arr);
void				ft_draw_hero(t_game *game);
void				ft_draw_walls(t_game *game, double len,
						int cnt, double degree);
void				ft_pixel(t_data *data, int x, int y, int c);
int					ft_move_hook(int keycode, t_game *game);
void				draw_test(t_game *game);
void				tester_ray(t_game *game);
int					ft_draw_no(t_game *game, double h, double count, int x);
int					ft_draw_so(t_game *game, double h, double count, int x);
int					ft_draw_we(t_game *game, double h, double count, int x);
int					ft_draw_ea(t_game *game, double h, double count, int x);
void				ft_draw_text(t_game *game, double h, double start, int x);
int					ft_text_col_no(t_game *game, int x, int y);
int					ft_text_col_so(t_game *game, int x, int y);
int					ft_text_col_we(t_game *game, int x, int y);
int					ft_text_col_ea(t_game *game, int x, int y);
int					get_s(t_game *game, int x, int y);
int					ft_check_allval(t_iparc *map, int i, int j);
void				ft_buba_south(t_game *all);
void				ft_er0255(t_iparc *map);
void				ft_r(char **parc_arr, t_iparc *map);
void				ft_buba_west(t_game *game);
int					ft_check_right(int i, int j, t_iparc *map);
int					ft_check_left(int i, int j, t_iparc *map);
int					ft_check_down(int i, int j, t_iparc *map);
int					ft_check_up(int i, int j, t_iparc *map);
int					ft_check_rightcorn1(int i, int j, t_iparc *map);
int					ft_check_rightcorn2(int i, int j, t_iparc *map);
int					ft_check_leftcorn2(int i, int j, t_iparc *map);
int					ft_check_leftcorn1(int i, int j, t_iparc *map);
void				ft_buba_east(t_game *game);
void				ft_buba_north(t_game *game);
int					is_wall(t_game *game, double x, double y);
void				init_rad(t_game *game, int i, int j);
void				ft_start_point(t_game *game);
void				ft_init_textures(t_game *game);
void				ft_check_res_open(int res_open);
void				mlx_clear_put(t_game *game);
void				ft_key53(int keycode, t_game *game);
void				ft_parc(int ac, char **av, t_iparc *map);

void				spt_to_list(t_game *game);
int					find_monster_centre(t_game *game, int cnt, double degree);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(t_game *game, double buf_d_x,
						double buf_d_y, double degree);
int					ft_check(t_list *lst, double x, double y);
int					ft_lstsize(t_list *lst);
void				ft_find_spt(t_game *game, double *arr);
void				ft_lstclear(t_list **lst);
t_list				*ft_sort_list(t_list *head);
int					ft_translate_rgb(int t, int r, int g, int b);
int					get_screen(t_game *game);
void				if_find(t_iparc *map);
void				ft_init_param(t_game *game, int flag,
						double *plr_x, double *plr_y);
void				ft_turn_mat(t_game *game, double plr_x,
						double plr_y, double rad);
void				ft_turn_y(t_game *game, double plr_x,
						double plr_y, double rad);
void				ft_turn_x(t_game *game, double plr_x,
						double plr_y, double rad);
char				**ft_mapre(int r, char **tmp_map, char *str, int count);
void				init_spt(t_game *game);
void				ft_check_zp(char *str);
void				ft_ferror(t_iparc *map);
void				ft_direct(t_iparc *map, int i, int j);
void				ft_init_flags(t_iparc *map);
void				mlx_get_screen_size(int *width, int *height);
char				*ft_strdup(const char *src);
int					ft_atoi(char *str);
int					ft_isdigit(int c);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t len);
int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(char *str1, char *str2);

#endif
