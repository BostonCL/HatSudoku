# HatSudoku

C program that utalizes the sudoku algorithm on steroids

program will take a grid of n by n and place in each grid a number of dove eggs.

•The eggs will be placed such that each spot on the grid will contain between 1 and n eggs 
inclusive.

•No two spots in the same row or the same column will contain the same number of eggs. In 
other words each row and column will contain each number of dove eggs (between 1 and n) 
exactly once.

Input:

First integeres is single and positive n, it represents the length of the square grid (4<n<=16)
Next line is a list of 3n space separated positive integers between 1 nd n.
In the j-th row each triple of integers, at indices 3i-2, 3i-1, and 3i, for i in the range of 1 to n, 
represent the numbers on i-th hat of the j-th row.

Sample Input:

4

1 2 3 1 3 4 1 3 4 1 3 4

1 2 3 1 2 3 1 2 4 1 2 4

2 3 4 1 2 3 1 2 3 2 3 4

2 3 4 1 3 4 1 3 4 1 2 4

Output:

2 4 3 1

1 3 2 4

4 2 1 3

3 1 4 2
