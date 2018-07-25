#ifndef SOLVE_H
# define SOLVE_H

typedef struct	s_bsq_solution
{
	t_dyn_int	opt;
	t_dyn_int	argopt;
}				t_bsq_solution;

t_bsq_solution	*solve_bsq(t_grid *grid, t_dyn_int *size);

t_dyn_int		get_min(t_grid *grid, t_dyn_int i, t_dyn_int j);
t_bsq_solution	*init_bsq_solution();

#endif
