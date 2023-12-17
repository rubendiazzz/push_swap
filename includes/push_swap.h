#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LTL_CASE 3
#define FIVE_CASE 5
#define I_32_MIN -2147483648
#define I_32_MAX 2147483647

typedef struct s_stack {
    struct s_stack *next;
    int32_t value;
    int32_t index;
} t_stack;

typedef struct s_two_stacks {
    t_stack *a, *b;
    int32_t min, max;
    int32_t len_b;
} t_two_stacks;

t_stack *new_stack(int32_t value, t_two_stacks **stacks);
t_stack *push(t_stack *stack, int32_t value, t_two_stacks **stacks);
t_stack *push_b(t_stack *stack, t_two_stacks **stacks);

void print_stacks(t_two_stacks *stacks);
void print_instruction(char instruction);

void push_swap(t_two_stacks *stacks);

#endif

