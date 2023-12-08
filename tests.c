/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:09:00 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/08 17:47:00 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Check why there is no segfault in revers_rotate 
	//when lst contains 2 elements only. 


// int	main(int argc, char *argv[])
// {
// 	t_list	*lst;
// 	int		*args; //FREE YOUR ARGS!!!!

// 	if (argc < 2)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}
// 	args = check_argv(--argc, ++argv);
// 	if (!args)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	lst = create_list(args, argc);
// 	if (!lst)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	return (0);
// }

// void	do_nothing(void *test)
// {
// 	*(int *)test += 0;
// }

// int	main(int argc, char *argv[])
// {
// 	t_list	*lst;
// 	int		*args; //FREE YOUR ARGS!!!!

// 	if (argc < 2)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}
// 	args = check_argv(--argc, ++argv);
// 	if (!args)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	lst = create_list(args, argc);
// 	if (!lst)
// 		return (0);
// 	lst = sort_lst(lst, 0);
// 	ft_lstclear(&lst, do_nothing);
// 	free(args);
// 	return (0);
// }







// Check possible input numbers

// //correct
// 	ft_printf("%d\n", check_arg("1"));
// 	ft_printf("%d\n", check_arg("+1"));
// 	ft_printf("%d\n", check_arg("123"));
// 	ft_printf("%d\n", check_arg("+123"));
// 	ft_printf("%d\n", check_arg("2147483647"));
// 	ft_printf("%d\n", check_arg("+2147483647"));
// 	ft_printf("%d\n", check_arg("0"));
// 	ft_printf("%d\n", check_arg("-0"));
// 	ft_printf("%d\n", check_arg("+0"));
// 	ft_printf("%d\n", check_arg("-1"));
// 	ft_printf("%d\n", check_arg("-123"));
// 	ft_printf("%d\n", check_arg("-2147483647"));
// 	ft_printf("%d\n", check_arg("-2147483648"));
// 	ft_printf("\n");
// 	ft_printf("%d\n", check_arg("00001"));
// 	ft_printf("%d\n", check_arg("+00001"));
// 	ft_printf("%d\n", check_arg("0000123"));
// 	ft_printf("%d\n", check_arg("+0000123"));
// 	ft_printf("%d\n", check_arg("00002147483647"));
// 	ft_printf("%d\n", check_arg("+00002147483647"));
// 	ft_printf("%d\n", check_arg("000000"));
// 	ft_printf("%d\n", check_arg("-00000"));
// 	ft_printf("%d\n", check_arg("+00000"));
// 	ft_printf("%d\n", check_arg("-00001"));
// 	ft_printf("%d\n", check_arg("-0000123"));
// 	ft_printf("%d\n", check_arg("-00002147483647"));
// 	ft_printf("%d\n", check_arg("-000002147483648"));
// 	ft_printf("\n");
// 	//incorrect
// 	ft_printf("%d\n", check_arg("2147483648"));
// 	ft_printf("%d\n", check_arg("+2147483648"));
// 	ft_printf("%d\n", check_arg("-2147483649"));
// 	ft_printf("%d\n", check_arg("--1"));
// 	ft_printf("%d\n", check_arg("++1"));
// 	ft_printf("%d\n", check_arg("--123"));
// 	ft_printf("%d\n", check_arg("++123"));
// 	ft_printf("%d\n", check_arg("--2147483647"));
// 	ft_printf("%d\n", check_arg("++2147483647"));
// 	ft_printf("%d\n", check_arg("--0"));
// 	ft_printf("%d\n", check_arg("++0"));
// 	ft_printf("%d\n", check_arg("--2147483648"));
// 	ft_printf("\n");
// 	ft_printf("%d\n", check_arg("asdf"));
// 	ft_printf("%d\n", check_arg("123a"));
// 	ft_printf("%d\n", check_arg("+asdf"));
// 	ft_printf("%d\n", check_arg("-34253434523452345"));
// 	ft_printf("%d\n", check_arg("34523465475674562345"));
// 	ft_printf("%d\n", check_arg("a2314"));
// 	ft_printf("%d\n", check_arg("+"));
// 	ft_printf("%d\n", check_arg("-"));
// 	ft_printf("%d\n", check_arg(""));
// 	ft_printf("\n");
// 	return (0);


// ##########################################################################################
// ##########################################################################################
// ##########################################################################################
// ##########################################################################################
// ##########################################################################################
// ##########################################################################################


