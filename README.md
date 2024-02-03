# push_swap

42 push_swap sorting algorithm project to sort big stacks of data

## Description

The goal of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you'll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

## Instructions

The project is written in C language, following the 42 school norm: [Norm](

The project is compiled via Makefile, using command `make` or `make bonus` to compile with bonus visualization.

The program takes a list of integers as arguments, and prints out the list of instructions to sort the stack.

## Usage

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Visualizer

The visualizer is written in Python3, using the Pygame library.

To run the visualizer, use the following command:

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG | python3 visualizer.py
```

## Example

![Example](

## Algorithm

The algorithm used is a combination of different sorting algorithms, depending on the size of the stack.

For stacks of 3 or less, the algorithm uses a simple sorting algorithm, which is the following:

```
if (a > b && b > c)
	sa
	rra
else if (a > b && a > c)
	ra
	if (a > b)
		sa
else if (a < b && a < c)
	rra
	if (a > b)
		sa
else if (a < b && b > c)
	sa
```

For stacks of 4 or 5, the algorithm uses a sorting algorithm, which is the following:

```
while (stack_a is not sorted)
	if (stack_a[0] > stack_a[1])
		sa
	if (stack_a[0] > stack_a[2])
		ra
	if (stack_a[0] < stack_a[1])
		rra
```

For stacks of 6 or more, the algorithm uses a sorting algorithm, which is the following:

```
while (stack_a is not sorted)
	if (stack_a[0] > stack_a[1])
		sa
	if (stack_a[0] > stack_a[2])
		ra
	if (stack_a[0] < stack_a[1])
		rra
	if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2])
		pb
```

For stacks of 100 or more, the algorithm uses a sorting algorithm, which is the following:

```
while (stack_a is not sorted)
	if (stack_a[0] > stack_a[1])
		sa
	if (stack_a[0] > stack_a[2])
		ra
	if (stack_a[0] < stack_a[1])
		rra
	if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2])
		pb
```

For stacks of 500 or more, the algorithm uses a sorting algorithm, which is the following:

```
while (stack_a is not sorted)
	if (stack_a[0] > stack_a[1])
		sa
	if (stack_a[0] > stack_a[2])
		ra
	if (stack_a[0] < stack_a[1])
		rra
	if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2])
		pb
```

## Bonus

The bonus part of the project is a visualizer, which shows the stacks and the instructions being executed in real time.

## Tester

The tester is written in Python3, and tests the program with random numbers, and checks if the program sorts the stack correctly.

To run the tester, use the following command:

```
python3 tester.py
```
