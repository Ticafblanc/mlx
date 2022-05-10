#ifndef SO_LONG_H
# define SO_LONG_H

# define TILES 50
# define PATH_W "./Assets/wall.xpm"
# define PATH_E "./Assets/empty.xpm"
# define PATH_EX "./Assets/exit.xpm"
# define PATH_PD "./Assets/player_down.xpm"
# define PATH_PT "./Assets/player_top.xpm"
# define PATH_PR "./Assets/player_right.xpm"
# define PATH_PL "./Assets/player_left.xpm"
# define PATH_I "./Assets/item.xpm"
# define PATH_V "./Assets/venom.xpm"
# define TOP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define RESET 0x72

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <libft.h>

# define BUFFER_SIZE 1

typedef struct s_position
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_map_check
{
	int	player;
	int	exit;
	int	collect;
}				t_map_check;

typedef struct s_map
{
	t_pos		player;
	t_pos		player_bup;
	int			valid;
	int			end_col;
	int			colum;
	int			line;
	t_map_check	check;
	int			item_bup;
	char		**map;
	char		**backup_map;
}				t_map;

typedef struct s_data
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	int		bpp;
	int		line_size;
	int		endian;
}				t_data;

typedef struct s_side
{
	t_data	down;
	t_data	top;
	t_data	left;
	t_data	right;
}				t_side;

typedef struct s_img
{
	t_data	wall;
	t_data	emp;
	t_data	exit;
	t_side	player;
	t_data	item;
	t_data	enemy;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		end_game;
	int		steps;
	int		init_game;
	double	reset;
	int		side;
}				t_mlx;

//utils
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

//map
char	**read_map(char *path, t_map *o_map);
void	verify(int valid, t_map *map);
int		check_wall(char c);
int		check_c(char c, t_map *map, int col, int line);
int		valid_cpe(t_map *map);
int		check(char c, t_map *map, int col, int line);
int		valid_map(int argc, char *map_file);
void	free_map(char **map_str, t_map *map);
int		check_extension(char *str, char *extension);
int		backup_map(t_map *map, char **map_str);
int		recovery(t_map *map);

//print map
t_img	init_image(void *mlx);
void	print_map(t_game *game);
void	*backup(t_map *map, char **map_str);

//init sprites
void	init_wall(t_img *img, void *mlx);
void	init_exit(t_img *img, void *mlx);
void	init_item(t_img *img, void *mlx);
void	init_player(t_img *img, void *mlx);
void	init_enemy(t_img *img, void *mlx);

//erros
int		errors(char *message);
void	*null_erro(char *message);
void	warning(char *message);

//game
int		init_game(t_game *game, int argc, char **argv);
int		action(int key, t_game *game);
int		update(t_game *game);
int		close_win(t_game *game);
void	check_side(t_game *game, int key);
void	move_player(t_game *game, int line, int col, int key);
int		verify_move(t_game *game, int line, int col, int key);
void	reset(t_game *game);
void	kill_player(t_game *game);

#endif