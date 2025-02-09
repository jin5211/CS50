#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	string name = get_string("Name: ");
	int length = strlen(name);
    printf("Your name\'s length is %i.\n", length);
}
