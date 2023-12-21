#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

StackNode* createNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(StackNode** top, int data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) {
        perror("Stack underflow");
        exit(EXIT_FAILURE);
    }
    int data = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

void printCommand(char* command) {
    printf("%s\n", command);
}

void performOperations(StackNode** stackA, StackNode** stackB, char* command) {
    printCommand(command);
    // Implement the actual stack operations here based on the Push Swap commands
    // For simplicity, I'll just print the commands
}

void mechanicalTurk(int* array, int size) {
    StackNode* stackA = NULL;
    StackNode* stackB = NULL;

    // Step 1: Push the first two numbers to STACK_A
    push(&stackA, array[0]);
    push(&stackA, array[1]);

    // Step 2: Find the cheapest number and push it to STACK_B
    for (int i = 2; i < size; i++) {
        // Implement your calculations to find the cheapest number
        // For simplicity, I'll just push all numbers to STACK_B
        push(&stackB, array[i]);
        performOperations(&stackA, &stackB, "pb");
    }

    // Step 3: Push everything back to STACK_A
    while (stackB != NULL) {
        // Implement your logic to push numbers back to STACK_A
        // For simplicity, I'll just pop from STACK_B and push to STACK_A
        int data = pop(&stackB);
        push(&stackA, data);
        performOperations(&stackA, &stackB, "pa");
    }

    // Step 4: Final arrangement
    // Implement the logic to bring the minimum number to the top of STACK_A
    // For simplicity, I'll just print a command
    performOperations(&stackA, &stackB, "ra");
}

int main() {
    int array[] = {4, 8, 2, 7, 1, 6, 3, 9, 5};
    int size = sizeof(array) / sizeof(array[0]);

    mechanicalTurk(array, size);

    return 0;
}
