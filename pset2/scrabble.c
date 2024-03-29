#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);



    // TODO: Print the winner

    if (score1 == score2)
    {
        printf("Tie!");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }

}

int compute_score(string word)
{
    int sum = 0;

    int n = strlen(word);

    char s[n];

    //Converts to upper case
    for (int i = 0 ; i < n ; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            s[i] = (char)toupper(word[i]);
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            s[i] = (char)word[i];
        }
        else
        {
            s[i] = (char)word[n];
        }
    }


    //Calculates scores
    for (int j = 0 ; j < n ; j++)
    {
        int z = (int)s[j] - 65;

        sum = sum + POINTS[z];
    }

    return sum;
}