#include "../includes/push_swap.h"

t_stack *new_stack(int32_t value, t_two_stacks **stacks) {
    t_stack *new_stack = (t_stack *)malloc(sizeof(t_stack));
    if (new_stack == NULL) {
        exit(1);
    }

    new_stack->value = value;
    new_stack->index = 0;

    (*stacks)->len_b++;

    return new_stack;
}

t_stack *push(t_stack *stack, int32_t value, t_two_stacks **stacks) {
    if (stack == NULL) {
        return new_stack(value, stacks);
    }

    stack->next = new_stack(value, stacks);

    return stack;
}

t_stack *push_b(t_stack *stack, t_two_stacks **stacks) {
    t_stack *new_stack = new_stack(stack->value, stacks);
    new_stack->next = (*stacks)->b;
    (*stacks)->b = new_stack;

    stack->value = 0;

    return stack;
}

void print_stacks(t_two_stacks *stacks) {
    printf("a: ");
    t_stack *current = (*stacks)->a;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\nb: ");
    current = (*stacks)->b;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void print_instruction(char instruction) {
    printf("%c\n", instruction);
}

void push_swap(t_two_stacks *stacks) {
    int i, j, pivot;
    t_stack *current, *next;

    for (i = 0; i < (*stacks)->len_b / 2; i++) {
        push_a(stacks);
    }

    pivot = (*stacks)->a->value;
    current = (*stacks)->a->next;

    for (i = 0; i < (*stacks)->len_b; i++) {
        if (current->value > pivot) {
            for (j = 0; j < (*stacks)->len_a - 1; j++) {
                rotate_a(stacks);
            }

            push_b(stacks);
        } else {
            current = current->next;
        }
    }

   

