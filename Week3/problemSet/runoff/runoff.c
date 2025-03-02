#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    int candIdx; // nameと一致する候補者リストのインデックスを代入する変数を定義
    int cnt = 0; // nameが候補者リストの中にあるときにカウントする変数を定義
    // 候補者のインデックスを取得
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candIdx = i;
            cnt++;
            break;
        }
    }

    // 引数の名前が候補者リストになければfalseを返す
    if (cnt == 0)
    {
        return false;
    }

    // 前回のランク付けで入力済みの名前を再び入力していないかチェックする
    for (int j = 0; j < rank; j++)
    {
        if (preferences[voter][j] == candIdx)
        {
            return false;
        }
    }

    // ダメな条件を乗り越えられたら、正常に処理行っていく
    if (rank == 0)
    {
        candidates[candIdx].votes += 1;
    }
    preferences[voter][rank] = candIdx;
    return true;
}

void tabulate(void)
{
    // すべての候補者の票数をリセット
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }

    // 各有権者の有効な票をカウント
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];

            // 候補者がまだ除外されていなければ、その人に票を加算
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;  // その有権者の票をカウントしたので、次の有権者へ
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minVote = voter_count;  // 有権者数が最大票数なので初期値にする

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < minVote)
        {
            minVote = candidates[i].votes;
        }
    }
    return minVote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int cntCand = 0;
    int cntMin = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            cntCand += 1;
            if (candidates[i].votes == min)
            {
                cntMin += 1;
            }
        }
    }
    if (cntCand == cntMin)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
