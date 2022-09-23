
#include <libft.h>
#include <ft_pivot.h>
#include <ft_doubly_list.h>

void ft_pdata_init(t_d_list_header *header, t_pivot *pivot, int index)
{
	t_d_list *temp;
	int i;

	temp = header->head;
	pivot->data[index].len = pivot->len_arr[index];
	if (!ft_zeromalloc((void **)&pivot->data[index].arr, \
		sizeof(int) * pivot->data[index].len))
		return ;
	i = 0;
	if (index < pivot->len / 3)
	{
		while (i++ < pivot->data[index].len - 1)
			temp = temp->next;
		i = 0;
		while (i < pivot->data[index].len)
		{
			pivot->data[index].arr[i++] = *temp->data;
			temp = temp->prev;
		}
	}
	else
	{
		while (i < pivot->data[index].len)
		{
			pivot->data[index].arr[i++] = *temp->data;
			temp = temp->next;
		}
	}
}

t_pivot *ft_pivot_split(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot)
{
	int			index;

	index = 0;
	while (index < pivot->len)
	{
		if (pivot->arrow[index])
			ft_pivot_up(a,b,pivot->len_arr[index]);
		else
			ft_pivot_down(a,b,pivot->len_arr[index]);
		ft_pdata_init(b, pivot, index);
		index++;
	}
	return (pivot);
}