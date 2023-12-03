# push_swap_eiei

The "push_swap" project is another common assignment in the 42 school curriculum. In this project, the goal is to write a program that sorts a stack of integers using a specific set of operations. The two main operations allowed are pushing an element from one stack to another (pa and pb), and rotating the stack either upward or downward (ra, rb, rra, rrb). The challenge is to implement an efficient algorithm to sort the stack using the minimum number of operations.

Here is an explanation of the key aspects of the "push_swap" project:

Stack Operations:
The project involves working with two stacks, usually named stack A and stack B.
The main operations are:
sa: Swap the first two elements at the top of stack A.
sb: Swap the first two elements at the top of stack B.
ss: Perform sa and sb simultaneously.
pa: Push the top element from stack A to stack B.
pb: Push the top element from stack B to stack A.
ra: Rotate the elements of stack A upward (the top element becomes the bottom one).
rb: Rotate the elements of stack B upward.
rr: Perform ra and rb simultaneously.
rra: Rotate the elements of stack A downward (the bottom element becomes the top one).
rrb: Rotate the elements of stack B downward.
rrr: Perform rra and rrb simultaneously.

Sorting Algorithm:
The main challenge is to design an algorithm that efficiently sorts the stack using the provided operations.
Different sorting algorithms can be employed, and the efficiency is often measured by the number of operations required.

Input and Output:
The program usually takes a list of integers as input and outputs a series of operations that, when applied to the initial stack, result in a sorted stack.

Error Handling:
The program should handle errors gracefully, such as invalid inputs or memory allocation failures.

In my "push_swap" project, I opted for a radix sort algorithm due to its simplicity in both debugging and conceptual understanding. For data storage, I chose to utilize single linked lists to efficiently store the input and facilitate the sorting process.
