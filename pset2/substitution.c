#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//Prototype
int check_numbers(string argv[]);
int check_reoccurrence(string argv[]);

//Main function
int main(int argc, string argv[])
{

//Key missing or more argument than expected
    if (argc == 1 || argc >= 3)
    {
        printf("Usage: ./substitution key\n");

        return 1;

    }
    int arg_len = strlen(argv[1]);




//Invalid key
    if (argc == 2 && arg_len != 26)
    {

        printf("Key must contain 26 characters.\n");


        return 1;

    }

    int numbers = check_numbers(argv);

    int occrence = check_reoccurrence(argv);


    //key having numbers.
    if (numbers >= 1)
    {
        printf("Key should not contain numbers.\n");


        return 1;
    }

    //key having reapeated alphabets and 1+2+3....+26 = 351
    if (occrence != 351)
    {
        printf("Key should not not contain repeated alphabets\n");


        return 1;
    }



//If all conditions meet
    if (argc == 2 && arg_len == 26)
    {


        string plain_s = get_string("plaintext: ");
        int input_len = strlen(plain_s);


        char big_arg[52];

        for (int i = 0 ; i < 52; i++)
        {
            if (i <= 25)
            {
                big_arg[i] = toupper(argv[1][i]);
            }
            else
            {
                big_arg[i] = tolower(argv[1][i - 26]);
            }
        }

        printf("ciphertext: ");
        for (int k = 0 ; k < input_len ; k++)
        {
            if (plain_s[k] >= 'A' && plain_s[k] <= 'Z')
            {
                printf("%c", big_arg[plain_s[k] - 'A']);
            }
            else if (plain_s[k] >= 'a' && plain_s[k] <= 'z')
            {
                printf("%c", big_arg[plain_s[k] - 'G']);
            }
            else
            {
                printf("%c", plain_s[k]);
            }
        }







        printf("\n");
        return 0;
    }


}



//check for numbers

int check_numbers(string argv[])
{
    int sum = 0;
    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (isdigit(argv[1][i]))
        {
            sum = sum + 1;
        }
    }
    return sum;
}



//Check for reoccurrence
int check_reoccurrence(string argv[])
{
    //
    int sum = 0;

    //upper case key
    char ABC[26];
    char weird_string[26];
    for (int i = 0 ; i < 26 ; i++)
    {
        ABC[i] = toupper(argv[1][i]);
    }

    //because (A/ABC[0] - A + 1) = 1 AND For 'B' it would be '2' and for 'Z' it would be '26'
    for (int j = 0 ; j < 26 ; j++)
    {
        if (ABC[j] >= 'A' && ABC[j] <= 'Z')
        {
            weird_string[j] = ABC[j] - 'A' + 1;
        }


    }

    //1+2+3....+26 = 351
    for (int k = 0 ; k < 26 ; k++)
    {
        sum = sum + weird_string[k];
    }


    return sum;

}


