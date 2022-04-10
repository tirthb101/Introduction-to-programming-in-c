#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes
int count_letter(string str);
int count_words(string str);
int count_sentences(string str);



int main(void)
{
    //Get input
    string s = get_string("Text: ");


    //Count
    int letters = count_letter(s);

    int words = count_words(s);

    int sentences = count_sentences(s);

    //Math
    double L = 100 * ((double)letters / (double)words);

    double S = 100 * ((double)sentences / (double)words);

    //Coleman-Liau index Equation
    double index = 0.0588 * L - 0.296 * S - 15.8;

    int rounded_index = round(index);




    //Print grade
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rounded_index);
    }




}



//Count total letters of the text
int count_letter(string str)
{
    int sum = 0;

    for (int i = 0 ; str[i] != 0; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            sum = sum + 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            sum = sum + 1;
        }

    }

    return sum;
}


//count number of words
int count_words(string str)
{
    int total = 0;

    for (int i = 0 ; str[i] != 0; i++)
    {
        if (str[i] == 32)
        {
            total = total + 1;
        }
    }

    return total + 1;
}



//Count sentences
int count_sentences(string str)
{
    int summ = 0;

    for (int i = 0 ; str[i] != 0; i++)
    {
        if (str[i] == 46)
        {
            summ = summ + 1;
        }
        else if (str[i] == 33)
        {
            summ = summ + 1;
        }
        else if (str[i] == 63)
        {
            summ = summ + 1;
        }


    }

    return summ;
}