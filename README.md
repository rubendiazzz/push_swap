# Push Swap

This is a project for the 42Cursus curriculum. The goal of this project is to sort a stack of integers using a limited set of operations.

## Algorithm Used

In this project, I have implemented the Mechanical Turk algorithm, as described in the following article: [Push Swap: Mechanical Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

## Getting Started

To get started with this project, follow the steps below:

1. Clone the repository: `git clone https://github.com/your-username/push_swap.git`
2. Compile the program: `make`
3. Run the program: `./push_swap <list of integers>`

## Usage

The program takes a list of integers as input and outputs a series of operations to sort the stack. The available operations are:

- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: swap the first two elements of both stacks
- `pa`: push the first element of stack B to stack A
- `pb`: push the first element of stack A to stack B
- `ra`: rotate stack A (move the first element to the end)
- `rb`: rotate stack B (move the first element to the end)
- `rr`: rotate both stacks
- `rra`: reverse rotate stack A (move the last element to the beginning)
- `rrb`: reverse rotate stack B (move the last element to the beginning)
- `rrr`: reverse rotate both stacks