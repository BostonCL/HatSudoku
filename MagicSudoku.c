#include <stdio.h>

#define TRUE (1==1)
#define FALSE (1==0)


#define SUB_SIZE 3
#define EMPTY 0
#define SIZE 16
int n;
//global input variable
int board[SIZE][SIZE][3];
//input array. maximum 16 by 16 and groups of 3
int outgrid[SIZE][SIZE];
//output array. maximum input is 16 by 16

void readBoard();
void printBoard();
int isValid();
int backTrack(int, int);

int main()
{

  scanf("%d", &n);
  //User input for length of square grid

    readBoard();

    if (backTrack(0, 0))
    {
        printBoard();
    }
    else
    {
        printf("No Solution found.\n");
    }

    return 0;
}

int isValid()
{
    int row, col, subRow, subCol, value, r, c;

    // Check each row
    //changed to new size
    for (row = 0; row < n; row++)
    {
        // Set that no value exists
        //Changed to new size
        int contains[n];
        for (value = 0; value < n; value++)
        {
            contains[value] = FALSE;
        }

        // Loop through the row
        //changed to new size n
        for (col = 0; col < n; col++)
        {
            // Check if a value is present
            //changed to output array
            if (outgrid[row][col] != EMPTY)
            {
                // Check if the value is already in the row
                //changed to output array
                if (contains[outgrid[row][col] - 1])
                {
                    return FALSE;
                }

                // Set the value is in the row
                contains[outgrid[row][col] - 1] = TRUE;
            }
        }
    }

    // Check each column
    //changed to new size n
    for (col = 0; col < n; col++)
    {
        // Set that no value exists
        int contains[SIZE];
        for (value = 0; value < n; value++)
        {
            contains[value] = FALSE;
        }

        // Loop through the column
        //changed to new size n
        for (row = 0; row < n; row++)
        {
            // Check if a value is present
            if (outgrid[row][col] != EMPTY)
            {
                // Check if the value is already in the row
                //Changed to the output array
                if (contains[outgrid[row][col] - 1])
                {
                    return FALSE;
                }

                // Set the value is in the row
                //Changed the array to the output array
                contains[outgrid[row][col] - 1] = TRUE;
            }
        }
    }
    //We do not need to check nonets because that was for Sudoku
    //Sudoku was broken into 9 square sections called nonets.
    /*// Check each nonet
    for (subRow = 0; subRow < SIZE; subRow += SUB_SIZE)
    {
        for (subCol = 0; subCol < SIZE; subCol += SUB_SIZE)
        {
            // Set that no value exists
            int contains[SIZE];
            for (value = 0; value < SIZE; value++)
            {
                contains[value] = FALSE;
            }

            // In the nonet loop through all values
            for (row = 0; row < SUB_SIZE; row++)
            {
                for (col = 0; col < SUB_SIZE; col++)
                {

                    r = row + subRow;
                    c = col + subCol;
                    if (board[r][c] != EMPTY)
                    {
                        // Check if the value is already in the row
                        if (contains[outgrid[r][c] - 1])
                        {
                            return FALSE;
                        }

                        // Set the value is in the row
                        contains[outgrid[r][c] - 1] = TRUE;
                    }
                }
            }
        }
    }*/

    // No invalid row, column, or nonet was found
    return TRUE;
}

int backTrack(int r, int c)
{
    // THIS IS BACKTRACKING : Check validity
    if (!isValid())
    {
        return FALSE;
    }

    // Check if col index (c) is off the board
    if (c == n)
    //changed to new size
    {
        return backTrack(r + 1, 0);
    }

    // Check if row index (r) is off the board
    if (r == n)
    //changed to new size
    {
        return TRUE;
    }

    // Check if forced
    if (outgrid[r][c] != 0)
    {
        return backTrack(r, c + 1);
    }

    // Try all possible decisions
    int attempt;
    for (attempt = 0; attempt <= 2; attempt++)
        //changed to new size
    {
        outgrid[r][c] = board[r][c][attempt];
        // we want the outgrid to equal the ingrid as a check.
        if (backTrack(r, c + 1))
            return TRUE;

        // Undo the choice
        outgrid[r][c] = EMPTY;
    }

    // No solution found
    return FALSE;
}

void printBoard()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", outgrid[i][j]);
        printf("\n");
    }
}

void readBoard()
{
  //Triple for loop to assign values in 3d array
  //Idea from your white board in office hours
  int i, j, k;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      for (k = 0; k < 3; k++)
      {
        scanf("%d", &board[i][j][k]);
        //input array
      }
    }
  }
}
