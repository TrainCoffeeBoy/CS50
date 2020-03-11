#include <cs50.h>
#include <stdio.h>
#include <math.h>

void check(long num);

int main(void)
{
    long num = 0;
    //use while loop to check the num is num or not
    num = get_long("Number: ");

    //check sum and print the result
    check(num);

    return 0;
}

void check(long num)
{
    //count the digits of num
    long num_devided = num;
    int digits = 0;
    while (num_devided != 0)
    {
        num_devided /= 10;
        digits++; 
    }
    //printf("debug digits: %d\n",digits);

    //store the digits into array
    int array[digits];
    long temp = num;
    for (int i = digits - 1 ; i >= 0; i--)
    {
        array[i] = temp / pow(10, i);
        //printf("array[%d]: %d\n", i, array[i]);
        temp %= (long)pow(10, i);
        //printf("temp: %ld\n", temp);
    }

    //multiply second to last digit and sum them up
    int sum1 = 0;
    for (int i = 1; i < digits; i = i + 2)
    {
        if (array[i] * 2 >= 10)
        {
            sum1 = sum1 + 1 + (array[i] * 2) % 10;//for digit over 10
        }
        else
        {
            sum1 = sum1 + array[i] * 2;
        }   
    }
    //printf("%d\n",sum1);

    //add sum1 to sum of digits which weren't multiplied by 2
    int sum2 = 0;
    for (int i = 0; i < digits; i = i + 2)
    {
        sum2 = sum2 + array[i];
    }
    sum2 = sum1 + sum2;
    //printf("%d,%d\n", sum1, sum2);

    //check the last digit is 0 or not
    //count the digits of sum2
    int temp1 = sum2;
    int dig = 0;
    while (temp1 != 0)
    {
        temp1 /= 10;
        dig++; 
    }
    //find the last digit
    int arr[dig];
    temp1 = sum2;
    for (int i = dig - 1 ; i >= 0; i--)
    {
        arr[i] = temp1 / pow(10, i);
        //printf("array[%d]: %d\n", i, array[i]);
        temp1 %= (int)pow(10, i);
        //printf("temp: %ld\n", temp);
    }
    
    //print the result
    int last_digit = arr[0];
    int first_digit = array[digits - 1];
    int second_digit = array[digits - 2];
    
    if (last_digit == 0)
    {
        //Amex
        if (digits == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
        {
            printf("AMEX\n");
        }
        //Master card
        else if
        (digits == 16 && first_digit == 5 && 
            (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4
             || second_digit == 5))
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if ((digits == 13 || digits == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
