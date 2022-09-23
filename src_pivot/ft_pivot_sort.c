
#include <libft.h>
#include <ft_pivot.h>
#include <ft_doubly_list.h>
#include <ft_stack.h>


int ft_min_hold(t_pdata *hold[3])
{
	int min;

	min = -1;
	if (hold[0]->len != hold[0]->index)
 	{
		min = 0;
		if (hold[1]->len != hold[1]->index && 
			hold[0]->arr[hold[0]->index] > hold[1]->arr[hold[1]->index])
		{
			min = 1;
			if (hold[2]->len != hold[2]->index && 
				hold[1]->arr[hold[1]->index] > hold[2]->arr[hold[2]->index])
				min = 2;
		}
		else if (hold[2]->len != hold[2]->index && 
			hold[0]->arr[hold[0]->index] > hold[2]->arr[hold[2]->index])
			min = 2;
	}
	else if (hold[1]->len != hold[1]->index)
	{
		min = 1;
		if (hold[2]->len != hold[2]->index && \
			hold[1]->arr[hold[1]->index] > hold[2]->arr[hold[2]->index])
			min = 2;
	}
	else if (hold[2]->len != hold[2]->index)
		min = 2;
	return (min);
}

int ft_max_hold(t_pdata *hold[3])
{
	int max;

	max = -1;
	if (hold[0]->len != hold[0]->index)
 	{
		max = 0;
		if (hold[1]->len != hold[1]->index && \
			hold[0]->arr[hold[0]->index] < hold[1]->arr[hold[1]->index])
		{
			max = 1;
			if (hold[2]->len != hold[2]->index && 
				hold[1]->arr[hold[1]->index] < hold[2]->arr[hold[2]->index])
				max = 2;
		}
		else if (hold[2]->len != hold[2]->index && \
			hold[0]->arr[hold[0]->index] < hold[2]->arr[hold[2]->index])
			max = 2;
	}
	else if (hold[1]->len != hold[1]->index)
	{
		max = 1;
		if (hold[2]->len != hold[2]->index && \
			hold[1]->arr[hold[1]->index] < hold[2]->arr[hold[2]->index])
			max = 2;
	}
	else if (hold[2]->len != hold[2]->index)
		max = 2;
	return (max);
}


t_pdata	*ft_find_pdata(t_pivot *pivot, int num)
{
	int i;
	
	i = 0;
	while (i < pivot->len)
	{
		if (pivot->data[i].arr[0] == num)
			return (&pivot->data[i]);
		i++;
	}
	return (NULL);
}


void ft_pdata_arr_up(t_d_list_header *header, int len, t_pdata *data)
{
	t_d_list	*temp;
	int			i;
	temp = header->head;
	free(data->arr);
	if (!ft_zeromalloc((void **)&data->arr, sizeof(int) * len))
		return ;
	i = 0;
	while (i++ < len - 1)
		temp = temp->next;
	i = 0;
	while (i < len)
	{
		data->arr[i++] = *temp->data;
		temp = temp->prev;
	}
	data->len = len;
	data->index = 0;
}

void ft_pdata_arr_down(t_d_list_header *header, int len, t_pdata *data)
{
	t_d_list	*temp;
	int			i;

	temp = header->head;
	free(data->arr);
	if (!ft_zeromalloc((void **)&data->arr, sizeof(int) * len))
		return ;
	i = 0;
	while (i < len)
	{
		data->arr[i++] = *temp->data;
		temp = temp->next;
	}
	data->len = len;
	data->index = 0;
}

void ft_set_split_a(t_d_list_header *a, t_d_list_header *b, int len)
{
	while (len--)
		ft_pb(a,b);
}

void ft_pivot_split_a(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot)
{
	int i;
	int minmax;
	t_pdata *hold[3];

	i = 0;
	while (i++ < pivot->len / 3)
		ft_set_split_a(a, b, pivot->data[pivot->len - i].len);
	hold[0] = ft_find_pdata(pivot, *a->head->data);
	hold[1] = ft_find_pdata(pivot, *a->tail->data);
	hold[2] = ft_find_pdata(pivot, *b->tail->data);
	i = 0;
	while (i < pivot->len / 3)
	{
		if (!pivot->arrow[i])
			minmax = ft_min_hold(hold);
		else
			minmax = ft_max_hold(hold);
		if (minmax == -1)
		{
			if (i < pivot->len / 3 / 3)
				ft_pdata_arr_up(b, hold[0]->len + hold[1]->len + hold[2]->len, &pivot->data[i]);
			else
				ft_pdata_arr_down(b, hold[0]->len + hold[1]->len + hold[2]->len, &pivot->data[i]);
			i++;
			if (i >= pivot->len / 3)
				break;
			hold[0] = ft_find_pdata(pivot, *a->head->data);
			hold[1] = ft_find_pdata(pivot, *a->tail->data);
			hold[2] = ft_find_pdata(pivot, *b->tail->data);
		}
		else if (minmax == 0)
		{
			ft_pb(a,b);
			hold[0]->index++;
		}
		else if (minmax == 1)
		{
			ft_rra(a);
			ft_pb(a,b);
			hold[1]->index++;
		}
		else if (minmax == 2)
		{
			ft_rrb(b);
			hold[2]->index++;
		}
	}
	pivot->len = pivot->len / 3;
}

void ft_set_split_b(t_d_list_header *a, t_d_list_header *b, int len)
{
	while (len--)
		ft_pa(a,b);
}
void ft_pivot_split_b(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot)
{
	int i;
	int minmax;
	t_pdata *hold[3];

	i = 0;
	while (i++ < pivot->len / 3)
		ft_set_split_b(a, b, pivot->data[pivot->len - i].len);
	hold[0] = ft_find_pdata(pivot, *b->head->data);
	hold[1] = ft_find_pdata(pivot, *b->tail->data);
	hold[2] = ft_find_pdata(pivot, *a->tail->data);
	i = 0;
	while (i < pivot->len / 3)
	{
		if (!pivot->arrow[i])
			minmax = ft_min_hold(hold);
		else
			minmax = ft_max_hold(hold);
		if (minmax == -1)
		{
			if (i < pivot->len / 3 / 3)
				ft_pdata_arr_up(a, hold[0]->len + hold[1]->len + hold[2]->len, &pivot->data[i]);
			else
				ft_pdata_arr_down(a, hold[0]->len + hold[1]->len + hold[2]->len, &pivot->data[i]);
			i++;
			if (i >= pivot->len / 3)
				break;
			hold[0] = ft_find_pdata(pivot, *b->head->data);
			hold[1] = ft_find_pdata(pivot, *b->tail->data);
			hold[2] = ft_find_pdata(pivot, *a->tail->data);
		}
		else if (minmax == 0)
		{
			ft_pa(a,b);
			hold[0]->index++;
		}
		else if (minmax == 1)
		{
			ft_rrb(b);
			ft_pa(a,b);
			hold[1]->index++;
		}
		else if (minmax == 2)
		{
			ft_rra(a);
			hold[2]->index++;
		}
	}
	pivot->len = pivot->len / 3;
}

t_d_list *ft_pivot_sort(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot)
{
	pivot = ft_pivot_split(a, b, pivot);
	while (pivot->deep)
	{
		if (a->head)
			ft_pivot_split_a(a, b, pivot);
		else if(b->head)
			ft_pivot_split_b(a, b, pivot);
		pivot->deep--;
	}
	return (a->head);
}