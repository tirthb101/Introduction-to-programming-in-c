#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Go to pixels one by one from left to right / left to middle and switch to next row by nester for loop
    //Calculate avrage color and assign same value to all rgb elemetns of pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Calculate avrage of all red, green and blue
            int z = round(image[i][j].rgbtBlue / 3.0 + image[i][j].rgbtRed / 3.0 + image[i][j].rgbtGreen / 3.0);

            //Asign avrage of red, green and blue to pixel's elements
            image[i][j].rgbtBlue = z;
            image[i][j].rgbtRed = z;
            image[i][j].rgbtGreen = z;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Go to pixels one by one from left to right / left to middle and switch to next row by nester for loop
    //swap first pixel with last and second with second to last and so on
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= (width / 2) - 1; j++)
        {
            //Temp variables
            int temp1 = image[i][j].rgbtBlue;
            int temp2 = image[i][j].rgbtRed;
            int temp3 = image[i][j].rgbtGreen;

            //Swap
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;

            image[i][width - 1 - j].rgbtBlue = temp1;
            image[i][width - 1 - j].rgbtRed = temp2;
            image[i][width - 1 - j].rgbtGreen = temp3;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Temp variable
    RGBTRIPLE imagetemp[height][width];

    //Add data to temporary variable
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagetemp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            imagetemp[i][j].rgbtRed = image[i][j].rgbtRed;
            imagetemp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }


    //Calculate
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //Multiple if and else if functions to do calculation in diffrent ways depending on location of pixel
            //i will add a shorter way to blur image in few days
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtBlue = round((imagetemp[i + 1][j].rgbtBlue + imagetemp[i + 1][j + 1].rgbtBlue + imagetemp[i][j + 1].rgbtBlue +
                                              imagetemp[i][j].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((imagetemp[i + 1][j].rgbtRed + imagetemp[i + 1][j + 1].rgbtRed + imagetemp[i][j + 1].rgbtRed +
                                             imagetemp[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((imagetemp[i + 1][j].rgbtGreen + imagetemp[i + 1][j + 1].rgbtGreen + imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i][j].rgbtGreen) / 4.0);

            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((imagetemp[i][j - 1].rgbtBlue + imagetemp[i + 1][j - 1].rgbtBlue + imagetemp[i + 1][j].rgbtBlue  +
                                              imagetemp[i][j].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((imagetemp[i][j - 1].rgbtRed + imagetemp[i + 1][j - 1].rgbtRed + imagetemp[i + 1][j].rgbtRed +
                                             imagetemp[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j - 1].rgbtGreen + imagetemp[i + 1][j - 1].rgbtGreen + imagetemp[i + 1][j].rgbtGreen +
                                               imagetemp[i][j].rgbtGreen) / 4.0);

            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtBlue = round((imagetemp[i - 1][j].rgbtBlue + imagetemp[i - 1][j + 1].rgbtBlue + imagetemp[i][j + 1].rgbtBlue +
                                              imagetemp[i][j].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((imagetemp[i - 1][j].rgbtRed + imagetemp[i - 1][j + 1].rgbtRed + imagetemp[i][j + 1].rgbtRed +
                                             imagetemp[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((imagetemp[i - 1][j].rgbtGreen + imagetemp[i - 1][j + 1].rgbtGreen + imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i][j].rgbtGreen) / 4.0);

            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((imagetemp[i][j - 1].rgbtBlue + imagetemp[i - 1][j - 1].rgbtBlue + imagetemp[i - 1][j].rgbtBlue +
                                              imagetemp[i][j].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((imagetemp[i][j - 1].rgbtRed + imagetemp[i - 1][j - 1].rgbtRed + imagetemp[i - 1][j].rgbtRed +
                                             imagetemp[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j - 1].rgbtGreen + imagetemp[i - 1][j - 1].rgbtGreen + imagetemp[i - 1][j].rgbtGreen +
                                               imagetemp[i][j].rgbtGreen) / 4.0);
            }
            else if (i == 0)
            {
                image[i][j].rgbtBlue = round((imagetemp[i][j].rgbtBlue + imagetemp[i][j - 1].rgbtBlue + imagetemp[i][j + 1].rgbtBlue + imagetemp[i +
                                              1][j].rgbtBlue + imagetemp[i + 1][j - 1].rgbtBlue + imagetemp[i + 1][j + 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed = round((imagetemp[i][j].rgbtRed +  imagetemp[i][j - 1].rgbtRed + imagetemp[i][j + 1].rgbtRed + imagetemp[i +
                                             1][j].rgbtRed + imagetemp[i + 1][j - 1].rgbtRed + imagetemp[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j].rgbtGreen + imagetemp[i][j - 1].rgbtGreen + imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i + 1][j].rgbtGreen +
                                               imagetemp[i + 1][j - 1].rgbtGreen + imagetemp[i + 1][j + 1].rgbtGreen) / 6.0);

            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((imagetemp[i][j].rgbtBlue + imagetemp[i][j - 1].rgbtBlue + imagetemp[i][j + 1].rgbtBlue + imagetemp[i -
                                              1][j].rgbtBlue + imagetemp[i - 1][j - 1].rgbtBlue + imagetemp[i - 1][j + 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed =  round((imagetemp[i][j].rgbtRed +  imagetemp[i][j - 1].rgbtRed + imagetemp[i][j + 1].rgbtRed + imagetemp[i -
                                              1][j].rgbtRed + imagetemp[i - 1][j - 1].rgbtRed + imagetemp[i - 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j].rgbtGreen + imagetemp[i][j - 1].rgbtGreen + imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i - 1][j].rgbtGreen +
                                               imagetemp[i - 1][j - 1].rgbtGreen + imagetemp[i - 1][j + 1].rgbtGreen) / 6.0);
            }
            else if (j == 0)
            {
                image[i][j].rgbtBlue =  round((imagetemp[i][j].rgbtBlue + imagetemp[i - 1][j].rgbtBlue + imagetemp[i + 1][j].rgbtBlue +
                                               imagetemp[i][j + 1].rgbtBlue +
                                               imagetemp[i - 1][j + 1].rgbtBlue + imagetemp[i + 1][j + 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed =  round((imagetemp[i][j].rgbtRed +  imagetemp[i - 1][j].rgbtRed + imagetemp[i + 1][j].rgbtRed +
                                              imagetemp[i][j + 1].rgbtRed +
                                              imagetemp[i - 1][j + 1].rgbtRed + imagetemp[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j].rgbtGreen + imagetemp[i - 1][j].rgbtGreen + imagetemp[i + 1][j].rgbtGreen +
                                               imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i - 1][j + 1].rgbtGreen + imagetemp[i + 1][j + 1].rgbtGreen) / 6.0);
            }
            else if (j == width - 1)
            {
                image[i][j].rgbtBlue =  round((imagetemp[i][j].rgbtBlue + imagetemp[i - 1][j].rgbtBlue + imagetemp[i + 1][j].rgbtBlue +
                                               imagetemp[i][j - 1].rgbtBlue +
                                               imagetemp[i + 1][j - 1].rgbtBlue + imagetemp[i - 1][j - 1].rgbtBlue)  / 6.0);
                image[i][j].rgbtRed =  round((imagetemp[i][j].rgbtRed +  imagetemp[i - 1][j].rgbtRed + imagetemp[i + 1][j].rgbtRed +
                                              imagetemp[i][j - 1].rgbtRed +
                                              imagetemp[i + 1][j - 1].rgbtRed + imagetemp[i - 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j].rgbtGreen + imagetemp[i - 1][j].rgbtGreen + imagetemp[i + 1][j].rgbtGreen +
                                               imagetemp[i][j - 1].rgbtGreen +
                                               imagetemp[i + 1][j - 1].rgbtGreen + imagetemp[i - 1][j - 1].rgbtGreen) / 6.0);
            }
            else if (i == height - 1)
            {
                image[i][j].rgbtBlue = round((imagetemp[i][j].rgbtBlue + imagetemp[i][j - 1].rgbtBlue + imagetemp[i][j + 1].rgbtBlue +
                                              imagetemp[i - 1][j].rgbtBlue +
                                              imagetemp[i - 1][j - 1].rgbtBlue + imagetemp[i - 1][j + 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed = round((imagetemp[i][j].rgbtRed +  imagetemp[i][j - 1].rgbtRed + imagetemp[i][j + 1].rgbtRed +
                                             imagetemp[i - 1][j].rgbtRed +
                                             imagetemp[i - 1][j - 1].rgbtRed + imagetemp[i - 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((imagetemp[i][j].rgbtGreen + imagetemp[i][j - 1].rgbtGreen + imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i - 1][j].rgbtGreen +
                                               imagetemp[i - 1][j - 1].rgbtGreen + imagetemp[i - 1][j + 1].rgbtGreen) / 6.0);

            }
            else
            {
                image[i][j].rgbtBlue = round((imagetemp[i + 1][j].rgbtBlue + imagetemp[i + 1][j + 1].rgbtBlue + imagetemp[i][j + 1].rgbtBlue +
                                              imagetemp[i][j - 1].rgbtBlue + imagetemp[i - 1][j].rgbtBlue + imagetemp[i + 1][j - 1].rgbtBlue +
                                              imagetemp[i - 1][j - 1].rgbtBlue + imagetemp[i][j].rgbtBlue + imagetemp[i - 1][j + 1].rgbtBlue) / 9.0);
                image[i][j].rgbtRed = round((imagetemp[i + 1][j].rgbtRed + imagetemp[i + 1][j + 1].rgbtRed + imagetemp[i][j + 1].rgbtRed +
                                             imagetemp[i][j - 1].rgbtRed + imagetemp[i - 1][j].rgbtRed + imagetemp[i + 1][j - 1].rgbtRed +
                                             imagetemp[i - 1][j - 1].rgbtRed + imagetemp[i][j].rgbtRed + imagetemp[i - 1][j + 1].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = round((imagetemp[i + 1][j].rgbtGreen + imagetemp[i + 1][j + 1].rgbtGreen + imagetemp[i][j + 1].rgbtGreen +
                                               imagetemp[i][j - 1].rgbtGreen + imagetemp[i - 1][j].rgbtGreen + imagetemp[i + 1][j - 1].rgbtGreen +
                                               imagetemp[i - 1][j - 1].rgbtGreen + imagetemp[i][j].rgbtGreen + imagetemp[i - 1][j + 1].rgbtGreen) / 9.0);
            }

        }
    }




    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Size of new 2D temporary array
    int new_row = height + 2;
    int new_coll = width + 2;

    //Temp 2D array of data type RGBTRIPLE with 1 more row and 1 more collam on each side
    RGBTRIPLE imagetemp[new_row][new_coll];

    //Genrate a temporary image with all pixels black
    for (int i = 0; i < new_row; i++)
    {
        for (int j = 0; j < new_coll; j++)
        {
            imagetemp[i][j].rgbtBlue = 00;
            imagetemp[i][j].rgbtRed = 00;
            imagetemp[i][j].rgbtGreen = 00;
        }
    }

    //Add data from image to temporary image in such a way that their is a black border around the image which is around one pixel
    for (int i = 1; i < new_row - 1; i++)
    {
        for (int j = 1; j < new_coll - 1 ; j++)
        {
            imagetemp[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
            imagetemp[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
            imagetemp[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
        }
    }

    //Calculate
    for (int i = 1; i < new_row - 1; i++)
    {
        for (int j = 1; j < new_coll - 1; j++)
        {
            //Calculate x kernal for sobar oprator (x kernal is for horizontal detection)
            float gx_b = (1) * imagetemp[i + 1][j + 1].rgbtBlue + (2) * imagetemp[i][j + 1].rgbtBlue + (-2) * imagetemp[i][j - 1].rgbtBlue +
                         (-1) * imagetemp[i + 1][j - 1].rgbtBlue + (-1) * imagetemp[i - 1][j - 1].rgbtBlue + (1) * imagetemp[i - 1][j + 1].rgbtBlue;
            float gx_r = (1) * imagetemp[i + 1][j + 1].rgbtRed + (2) * imagetemp[i][j + 1].rgbtRed + (-2) * imagetemp[i][j - 1].rgbtRed +
                         (-1) * imagetemp[i + 1][j - 1].rgbtRed + (-1) * imagetemp[i - 1][j - 1].rgbtRed + (1) * imagetemp[i - 1][j + 1].rgbtRed;
            float gx_g = (1) * imagetemp[i + 1][j + 1].rgbtGreen + (2) * imagetemp[i][j + 1].rgbtGreen + (-2) * imagetemp[i][j - 1].rgbtGreen +
                         (-1) * imagetemp[i + 1][j - 1].rgbtGreen + (-1) * imagetemp[i - 1][j - 1].rgbtGreen + (1) * imagetemp[i - 1][j + 1].rgbtGreen;

            //Calculate y kernal for sobar oprator (x kernal is for vertical detection)
            float gy_b = (2) * imagetemp[i + 1][j].rgbtBlue + (1) * imagetemp[i + 1][j + 1].rgbtBlue + (-2) * imagetemp[i - 1][j].rgbtBlue +
                         (1) * imagetemp[i + 1][j - 1].rgbtBlue + (-1) * imagetemp[i - 1][j - 1].rgbtBlue + (-1) * imagetemp[i - 1][j + 1].rgbtBlue;
            float gy_r = (2) * imagetemp[i + 1][j].rgbtRed + (1) * imagetemp[i + 1][j + 1].rgbtRed + (-2) * imagetemp[i - 1][j].rgbtRed +
                         (1) * imagetemp[i + 1][j - 1].rgbtRed + (-1) * imagetemp[i - 1][j - 1].rgbtRed + (-1) * imagetemp[i - 1][j + 1].rgbtRed;
            float gy_g = (2) * imagetemp[i + 1][j].rgbtGreen + (1) * imagetemp[i + 1][j + 1].rgbtGreen + (-2) * imagetemp[i - 1][j].rgbtGreen +
                         (1) * imagetemp[i + 1][j - 1].rgbtGreen + (-1) * imagetemp[i - 1][j - 1].rgbtGreen + (-1) * imagetemp[i - 1][j + 1].rgbtGreen;


            //Combine both x and y kernals by combining squares and than taking sqare root for each channal
            int g_b = round(sqrt((gx_b * gx_b) + (gy_b * gy_b)));
            int g_r = round(sqrt((gx_r * gx_r) + (gy_r * gy_r)));
            int g_g = round(sqrt((gx_g * gx_g) + (gy_g * gy_g)));


            //truncate value to 255 if it is momre than 255
            if (g_b >= 255)
            {
                g_b = 255;
            }
            if (g_r >= 255)
            {
                g_r = 255;
            }
            if (g_g >= 255)
            {
                g_g = 255;
            }

            //Add new edited pixels to the image
            image[i - 1][j - 1].rgbtBlue = g_b;
            image[i - 1][j - 1].rgbtRed =  g_r;
            image[i - 1][j - 1].rgbtGreen = g_g;
        }
    }



    return;
}
