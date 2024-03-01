/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:47:36 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/25 10:47:38 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(stack_ptr a, char *str);
stack_ptr	rotate(stack_ptr stack, char *str);
stack_ptr	rev_rotate(stack_ptr stack, char *str);
stack_ptr	push(stack_ptr a, stack_ptr *b, char *str);

/**
 * swap - executes a swap between the 2 values on the top of the stack
 * @a: pointer to the stack
 * @str: pointer to the operation to execute
 * Return: void.
 * 
*/
void	swap(stack_ptr a, char *str)
{
	int	tmp;

	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
	tmp = a->index;
	a->index = a->next->index;
	a->next->index = tmp;
	if (str != NULL)
		ft_putendl_fd(str, 1);
}

/**
 * ra - swipe up stack's order,
 * e.g: the first node becomes the last one, the second one
 * becomes the first one and the third one becomes the second one
 * (2, 4, 6) => (4, 6, 2)
 * @a: pointer to the main stack
 * Return: pointer to the main stack with the new order.
*/
stack_ptr	rotate(stack_ptr stack, char *str)
{
	stack_ptr   last_node;
	stack_ptr   tmp;

	if (get_stack_size(stack) < 2)
		return (stack);
	// make the last node points to the first node
	last_node = find_last_node(stack);
	last_node->next = stack;
	// stack pointer should point to the second node
	tmp = stack;
	stack = stack->next;
	// update the node.next to NULL (last node on the stack)
	tmp->next = NULL;
	if (str != NULL)
		ft_putendl_fd(str, 1);
	return (stack);
}

/**
 * rra - swipe down stack's order,
 * e.g: (2, 4, 6) => (6, 2, 4)
 * @a: pointer to the main stack
 * Return: pointer to the main stack with the new order.
*/
stack_ptr	rev_rotate(stack_ptr stack, char *str)
{
	stack_ptr	tmp;
	stack_ptr	last;
	stack_ptr	before_last;

	if (get_stack_size(stack) < 2)
		return (stack);
	// find the before last node
	before_last = find_blast_node(stack);
	// make a temporary pointer to the first node
	tmp = stack;
	// make the last node points to the first node
	last = find_last_node(stack);
	last->next = tmp;
	// make the last node points to NULL
	before_last->next = NULL;
	// make the stack pointer points to the node that becomes the first
	stack = last;
	if (str)
		ft_putendl_fd(str, 1);
	return (stack);
}

stack_ptr	push(stack_ptr a, stack_ptr *b, char *str)
{
	stack_ptr	tmp;

	if (0 == ft_strncmp(str, "pb", ft_strlen(str)))
	{
		tmp = a->next;
		a->next = (*b);
		(*b) = a;
		a = tmp;
	}
	else if (0 == ft_strncmp(str, "pa", ft_strlen(str)))
	{
		tmp = (*b)->next;
		(*b)->next = a;
		a = (*b);
		(*b) = tmp;
	}
	if (str)
		ft_putendl_fd(str, 1);
	return (a);
}
