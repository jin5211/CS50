#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for the pyramid's height
    int height;
    do
    {
      height = get_int("Height: ");
    }
    while (height < 1);

    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
      // Print row of bricks
      // Print spaces
      for (int j = 0; j < height - i - 1; j++)
      {
        printf(" ");
      }
      // Print bricks
      for(int k = 0; k < i + 1; k++)
      {
        printf("#");
      }
      printf("\n");
    }
}

// space, brick
// height = 7(i=0,1,2,3,4,5,6)
// 6 spaces, 1 brick(i=0, j=height-i-1=6 , k=i+1=0+1=1 )
// 5 spaces, 2 bricks(i=1, j=height-i-1=5, k=i+1=1+1=2 )
// 4 spaces, 3 bricks(i=2, j=height-i-1=4, k=i+1=2+1=3 )
// 3 spaces, 4 bricks(i=3, j=height-i-1=3, k=i+1=3+1=4 )
// 2 spaces, 5 bricks(i=4, j=height-i-1=2, k=i+1=4+1=5 )
// 1 space, 6 bricks (i=5, j=height-i-1=1, k=i+1=5+1=6 )
// 0 spaces, 7 bricks(i=6, j=height-i-1=0, k=i+1=6+1=7 )

// int i = 0; i < height; i++
// int j = 0; j < height - i - 1; j++
// int k = 0; k < i + 1; k++