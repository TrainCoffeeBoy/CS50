#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)//check the number of arguments
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");//open file with read mode

    if (f == NULL)
    {
        printf("File cannot be opend.\n");
        return 1;
    }

    FILE *img;// file pointer for jpg
    size_t size;// variable for fread to check the end of file
    int i = 0;
    unsigned char buffer[512];
    char filename[8];

    while (1)
    {
        size = fread(buffer, 512, 1, f);//read 512btye of file

        if (size < 1)//if the end of the file
        {
            fclose(img);
            break;
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0)//check the first four byte to find jpeg headder
        {
            if (i == 0)//for first jpg
            {
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "a");
                fwrite(buffer, 512, 1, img);
                i++;
            }
            else//for jpg from 2nd to 50th
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "a");
                fwrite(buffer, 512, 1, img);
                i++;
            }
        }
        else
        {
            if (i > 0)//write buffer to jpg file before finding next jpg headder
            {
                fwrite(buffer, 512, 1, img);
            }
            else
            {
                //nothing to do
            }
        }

    }
    return 0;

}
