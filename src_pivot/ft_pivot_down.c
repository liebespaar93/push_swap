#include <ft_doubly_list.h>
#include <ft_quick_sort.h>
#include <libft.h>
#include <ft_stack.h>

void	ft_pivot_down_1(t_d_list_header *a, t_d_list_header *b)
{
	ft_pb(a, b);
}

void	ft_pivot_down_2(t_d_list_header *a, t_d_list_header *b)
{
	if (*a->head->data > *a->head->next->data)
		ft_sa(a);
	ft_pb(a, b);
	ft_pb(a,b);
}

void	ft_pivot_down_3(t_d_list_header *a, t_d_list_header *b)
{
	ft_pb(a, b);
	if (*a->head->data > *a->head->next->data)
		ft_sa(a);
	ft_pb(a,b);
	if (*b->head->data < *b->head->next->data)
		ft_sb(b);
	ft_pb(a,b);
	if (*b->head->data < *b->head->next->data)
		ft_sb(b);
}

int	ft_pivot_down(t_d_list_header *a, t_d_list_header *b, int len)
{
	if (len <= 1)
	{
		ft_pivot_down_1(a,b);
	}
	else if (len == 2)
	{
		ft_pivot_down_2(a,b);
	}
	else if (len == 3)
	{
		ft_pivot_down_3(a,b);
	}
	else
		return (0);
	return (1);
}
