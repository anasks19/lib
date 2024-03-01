/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:12:34 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/18 13:12:35 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static stack_ptr	push_swap(stack_ptr a, stack_ptr *b, size_t size);
static stack_ptr	sortOf3(stack_ptr a);
static stack_ptr	sort_big_stack(stack_ptr a, stack_ptr *b, size_t size_a);

/**
 * for memory allocation, still have (stack a) + pointer to args (**args)
*/

/**
 * main - Entry point of the program
 * Description: Sorting numbers "arguments" on the stack in ascending order
 * 
 * Return: Always 0 (Success).
*/
int	main(int argc, char *argv[])
{
	stack_ptr	a;
	stack_ptr	b;
	size_t		stack_size;
	char		**args;

	a = NULL;
	b = NULL;
	if (argc <= 1 || NULL == argv[1]) // lack of args, only program name!
		exit(0);
	args = args_checker(argv + 1);
	a = main_stack_build(args);
	free_args(args);
	// After passing all checks, now build the main stack
	stack_size = get_stack_size(a);
	stack_indexing(a, stack_size + 1);
	// now the sort will be done by index, we know which value is 1 (lowest) and which one is stack_size (highest)
	a = push_swap(a, &b, stack_size);
	stack_ptr tmp;
	for (tmp = a; tmp; tmp = tmp->next)
		printf("content: %d\n", tmp->num);
	free_main_stack(a);
	return (0);
}

/**
 * push_swap - sort values in ascending order with a minimum number of
 * actions to execute.
 * @a: pointer to the main stack
 * @b: pointer to the assisting stack
 * @size: size of the main stack
 * Return: void.
*/
static stack_ptr	push_swap(stack_ptr a, stack_ptr *b, size_t size)
{
	if (2 == size && false == is_sorted(a))
		swap(a, "sa");
	else if (3 == size && false == is_sorted(a))
		a = sortOf3(a);
	else if (size > 3 && false == is_sorted(a))
		a = sort_big_stack(a, b, size);
	return (a);
}

/**
 * sorfOf3 - executes an algorithm to sort 3 values on the top of the stack,
 * @a: pointer to the main stack
 * Return: pointer to head (first node on the stack)
*/
static stack_ptr	sortOf3(stack_ptr a)
{
	// IN RESUME, we have 3 scenarios:
		// 1- node 1 => highest index => 'ra', then check if the first 2 nodes are sorted, if not then 'sa'
		// 2- node 2 => highest index => 'rra', then check the same as scenario 1
		// 3- node 3 => highest index (no need to check) =>, then same condition is checked.
	size_t	highest;

	highest = find_hindex(a);
	if (a->index == highest)
		a = rotate(a, "ra");
	else if (a->next->index == highest)
		a = rev_rotate(a, "rra");
	if (false == is_sorted(a))
		swap(a, "sa");
	return (a);
}

static stack_ptr	sort_big_stack(stack_ptr a, stack_ptr *b, size_t size_a)
{
	a = saveOf3(a, b, size_a);
	a = sortOf3(a);
	while ((*b) != NULL)
	{
		// first need to target the position of b element on stack a.
		target_pos(a, b);
		// Once we found the targeted position for each B element on stack a
			// we'll use the target pos of each b element to calculate the cost of a, and the position of each b element to calculate the cost of b
		cost_get(a, b);
		a = lowest_cost_move(a, b);
	}
	if (false == is_sorted(a))
		a = stack_shifting(a);
	return (a);
}