#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9
//9 is a constant
//each candidate have name and vote so, total = 18

// Candidates have name and vote count
typedef struct
{
    string name; //in simple way, int x = 1;
    int votes; //int y = 3;
}
candidate; //candidate = a structure called candidate

// Array of candidates
candidate candidates[MAX]; //in this line, candidate is a structure above
//cnadidates is a new global variable named for Max definition.
//each element in it has two variables.

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name); //I see two functions, vote and print winner
void print_winner(void);// bool decides which vote is for which candidate
//void returns no value

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //compare each candidate's names
    //if nobody get voted, vote is 0;
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
           candidates[i].votes++;
           return candidates[i].votes++;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //if candidate votes are equal, print tie
    //also print their names! new lines
    int maximum_vote = 0;
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes >= maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == maximum_vote)
        {
            printf("%s\n",candidates[i].name);
        }
    }
    return;
}
