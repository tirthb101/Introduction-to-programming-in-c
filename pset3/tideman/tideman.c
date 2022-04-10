#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];


// Counts
int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int a, int b, int variable1, int variable2, int variable3);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int k = 0; k < candidate_count ; k++)
    {
        if (strcmp(candidates[k], name) == 0)
        {
            ranks[rank] = k;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int k = 0; k < candidate_count - 1;  k++)
    {
        for (int l = k + 1; l < candidate_count ; l++)
        {
            if (k != l)
            {
                preferences[ranks[k]][ranks[l]] = preferences[ranks[k]][ranks[l]] + 1;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        for (int l = 0; l < candidate_count; l++)
        {
            if (preferences[k][l] == preferences[l][k])
            {
                ;
            }
            else if (preferences[k][l] > preferences[l][k])
            {
                pairs[pair_count].winner = k;
                pairs[pair_count].loser = l;
                pair_count++;
            }

        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int l = 0;
    int runs = pair_count * pair_count;
    while (l < runs)
    {
        for (int q = 0; q < pair_count; q += 1)
        {
            if (preferences[pairs[q].winner][pairs[q].loser] < preferences[pairs[q + 1].winner][pairs[q + 1].loser])
            {
                int temp1 = pairs[q].winner;
                int temp2 = pairs[q + 1].winner;

                int temp3 = pairs[q].loser;
                int temp4 = pairs[q + 1].loser;

                pairs[q].winner = temp2;
                pairs[q + 1].winner = temp1;

                pairs[q].loser = temp4;
                pairs[q + 1].loser = temp3;
            }
        }
        l++;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int k = 0 ; k < pair_count; k++)
    {
        // Add first edge
        if (k == 0)
        {
            locked[pairs[k].winner][pairs[k].loser] = true;
        }

        // If first edge already added
        else
        {
            //Variables to be used to detect cycles
            int variable1 = pairs[k].winner;
            int variable2 = pairs[k].loser;
            int variable3 = 0;

            // Temporarly add a edge
            locked[pairs[k].winner][pairs[k].loser] = true;

            // Check if adding a edge created a cycle or not
            bool cycle = creates_cycle(pairs[k].winner, pairs[k].loser, variable1, variable2, variable3);

            // If adding a node created a cycle revert changes otherwise keep the changes
            if (cycle == true)
            {
                locked[pairs[k].winner][pairs[k].loser] = false;
            }
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    bool arrow_pointing_towards[candidate_count];
    bool arrow_pointing_from[candidate_count];


    // Initialize bool array to false
    for (int k = 0; k < candidate_count; k++)
    {
        arrow_pointing_from[k] = false;
        arrow_pointing_towards[k] = false;
    }

    // Variable to keep count of number of sources
    int first = 0;


    // Fill data into bool arrays
    for (int k = 0; k < candidate_count; k++)
    {
        for (int l = 0; l < candidate_count ; l++)
        {
            if (locked[k][l] == true)
            {
                arrow_pointing_from[k] = true;
                arrow_pointing_towards[l] = true;
            }

        }

    }

    // Calculate number of sources
    for (int k = 0; k < candidate_count; k++)
    {
        if (arrow_pointing_from[k] == true && arrow_pointing_towards[k] == false)
        {
            first++;
        }
    }

    // If sources are greates than one
    if (first >= 1)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (arrow_pointing_from[k] == true && arrow_pointing_towards[k] == false)
            {
                printf("%s\n", candidates[k]);
            }
        }

    }

    // If source is one
    else if (first == 0)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (arrow_pointing_from[k] == false && arrow_pointing_towards[k] == false)
            {
                printf("%s\n", candidates[k]);
            }
        }

    }
}


//Check if it will create a cycle or not
bool creates_cycle(int a, int b, int variable1, int variable2, int variable3)
{
    //Check if using recursion we have completed a cicle on loop
    if (variable3 != 0 && variable1 == a && variable2 == b)
    {
        return true;
    }

    //Use recursion
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[b][i] == true)
        {
            variable3++;
            bool random = creates_cycle(b, i, variable1, variable2, variable3);

            if (random == true)
            {
                return true;
            }
        }
    }
    return false;
}