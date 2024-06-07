#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int i = 0;
  while (i < 50)
  {
    printf("%i回目の'Hello World!'\n", i+1);
    i++;
  }
}

// int main(void)
// {
//   int i = 50;
//   while (i > 0)
//   {
//     printf("%i回目の'Hello World!'\n", i);
//     i--;
//   }
// }