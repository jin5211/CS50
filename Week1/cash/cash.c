#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters(25C) you should give customer
    int quarters = calculate_quarters(cents);

    // Subtract the value of those quarters from cents
    cents -= quarters * 25;

    // Calculate how many dimes(10C) you should give customer
    int dimes = calculate_dimes(cents);

    // Subtract the value of those dimes from remaining cents
    cents -= dimes * 10;

    // Calculate how many nickels(5C) you should give customer
    int nickels = calculate_nickels(cents);

    // Subtract the value of those nickels from remaining cents
    cents -= nickels * 5;

    // Calculate how many pennies(1C) you should give customer
    int pennies = calculate_pennies(cents);

    // Subtract the value of those pennies from remaining cents
    cents -= pennies * 1;

    if (cents == 0)
    {
        // Sum the number of quarters, dimes, nickels, and pennies used
        int total_coins = quarters + dimes + nickels + pennies;
        // Print that sum
        printf("%i\n", total_coins);
    }
}

// Function to calculate how many quarters(25C) you should give customer
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        cents -= 25;
        quarters++;
    }
    return quarters;
}

// Function to calculate how many dimes(10C) you should give customer
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents -= 10;
        dimes++;
    }
    return dimes;
}

// Function to calculate how many nickels(5C) you should give customer
int calculate_nickels(int cents)
{
    int nickles = 0;
    while (cents >= 5)
    {
        cents -= 5;
        nickles++;
    }
    return nickles;
}

// Function to calculate how many pennies(1C) you should give customer
int calculate_pennies(int cents)
{
    int pennies = cents;
    {
        return pennies;
    }
}