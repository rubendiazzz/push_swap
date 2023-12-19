#include "../includes/push_swap.h"

/*
* This file will contain the main parsing code for this project.
* It will parse all the arguments passed in the terminal.
* And it will detect all the movements required: 
* 
* sa (swap a)
* sb (swap b)
* ss (a & b at the same time)
* pa (push a)
* pb (push b)
* ra (rotate a)
* rb(rotate b)
* rr (rotate a and rotate b at the same time)
* rra (reverse rotate a)
* rrb (reverse rotate b)
* rrr (rra & rrb at the same time)
*
*/

int main(int argc, char **argv)
{
  // Reading input from the user.
  char  input[1024];
  int   inputIndex;

  inputIndex = 0;
  while(read(0, &input[inputIndex], 1) > 0)
  {
    if(input[inputIndex] == '\n')
      break ;
    inputIndex++;
  }
  // Initialize empty stacks
  struct stack_a stack_a = {0};
  struct stack_b stack_b = {0};
  // Validate input
  int inputLen = inputIndex;
  while (inputIndex--)
  {
    if (input[inputIndex] < '0' || input[inputIndex] > '9')
    exit(1);
  }
  // Parse numbers
  int numCount = 0;
  int parsedNumbers[1024];
  while (inputIndex >= 0)
  {
    if(input[inputIndex] == ' ')
      parsedNumbers[numCount++] = ft_atoi(&input[inputIndex - numCount + 1]);
      inputIndex--;
  }
  parsedNumbers[numCount] = ft_atoi(&input[0]);
  // Push numbers to stack A
  for (int i = 0; i < numCount; i++)
    push(&stack_a, parsedNumbers[i]);
  // Perform push and swap operations
  while(inputIndex--)
  {
    if (input[inputIndex] == 'a')
      push(&stack_b, pop(&stack_a))
  }
}

