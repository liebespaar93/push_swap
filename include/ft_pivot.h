
#ifndef FT_PIVOT_H
# define FT_PIVOT_H

# include <ft_doubly_list.h>


typedef struct s_pivot_data
{
	int	*arr;
	int index;
	int len;
}	t_pdata;

typedef struct s_pivot
{
	int	index;
	int *arrow;
	int *len_arr;
	t_pdata *data;
	int len;
	int deep;
}	t_pivot;

t_pivot *ft_pivot_init(t_d_list *memory);
t_pivot *ft_pivot_split(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot);

int	ft_pivot_up(t_d_list_header *a, t_d_list_header *b, int len);
int	ft_pivot_down(t_d_list_header *a, t_d_list_header *b, int len);

t_d_list	*ft_sort_two(t_d_list_header *a, int *result);
t_d_list	*ft_sort_three(t_d_list_header *a, int *result);
t_d_list	*ft_sort_five(t_d_list_header *a, t_d_list_header *b, int *result);
t_d_list *ft_pivot_sort(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot);

void	 ft_pdata_init(t_d_list_header *header, t_pivot *pivot, int index);
#endif