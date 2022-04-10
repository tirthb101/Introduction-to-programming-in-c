#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//Defines uint8_t as BYTE which is convenient to use
typedef uint8_t BYTE;


//Main function
int main(int argc, char *argv[])
{
    //Check command line argument for inproper useage
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //Open forensic image
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("could not open %s\n", argv[1]);
        return 1;
    }
    //Makes a temporary pointer
    FILE *fileo = fopen("delete.jpg", "w");

    //Counter for files
    int i = 0;

    //Buffer
    BYTE buffer[512];

    //Stores filename that changes with number of jpg files genrated
    char *filename = malloc(sizeof(BYTE) * 8);

    //Main function
    while (fread(&buffer, 1, 512, input))
    {
        //JPEG files have some comman data in their headers which can be useful to identiy deleted files
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //When its first jpg file that is being recoverd
            if (i == 0)
            {
                sprintf(filename, "%03i.jpg", i);
                fileo = fopen(filename, "w");
                fwrite(&buffer, 1, 512, fileo);
                i++;
            }
            //if it isn't
            else
            {

                sprintf(filename, "%03i.jpg", i);
                fileo = fopen(filename, "w");
                fwrite(&buffer, 1, 512, fileo);
                i++;
            }

        }
        else
        {
            //Just copies data
            fwrite(&buffer, 1, 512, fileo);
        }
    }


    //Garbage collaction
    free(filename);
    remove("delete.jpg");
    fclose(input);
    fclose(fileo);

}