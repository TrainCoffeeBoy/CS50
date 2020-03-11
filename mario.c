#include <cs50.h>
#include <stdio.h>

void draw(int h); //function to draw blocks

int main(void)
{
    int height = 0;//initialize height

    while (height < 1 || height > 8) //reprompt if user input invalid value
    {
        height = get_int("Height: ");//ask user to input the height
    }

    draw(height);
    return 0;
}

void draw(int h)//function to draw blocks
{
    for (int j = 0; j < h ; j++)
    {
        for (int i = 0; i < h - j - 1 ; i++)
        {
            printf(" ");//draw spaces of left
        }

        for (int i = 0; i < j + 1 ; i++)
        {
            printf("#");//draw # of left
        }

        printf("  ");//draw spaces in the middle

        for (int i = 0; i < j + 1; i++)
        {
            printf("#");//draw # of left
        }

        printf("\n");//new line
    }
}
