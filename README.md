# push_swap

./push_swap "1 3 2 0" | ./checker "1 3 2 0"

cc main.c -I include -I modules/Libft/include -I modules/ft_printf/include -L modules/Libft -lft -L modules/ft_printf -lftprintf src/**.c src_doubly_list/**.c src_push_swap/**.c src_quick_sort/**.c src_pivot/**.c src_stack/**.c -g