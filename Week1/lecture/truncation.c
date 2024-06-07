#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Get numbers from user
  float x = get_float("x: ");
  float y = get_float("y: ");

  // Divide x by y
  float z =  x / y;
  printf("%f\n", z);
}