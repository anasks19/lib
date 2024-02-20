/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:12:47 by achahid-          #+#    #+#             */
/*   Updated: 2024/02/18 13:12:49 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // for debugging
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int	num; // Current number on stack

	struct s_stack_node	*next;
} t_stack_node;

typedef t_stack_node *stack_ptr;

/* arguments checker */
char	**args_checker(char **ptr_args);

# endif /* PUSH_SWAP_H */
