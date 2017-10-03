#include <cstdio>
#include <vector>

using namespace std;

inline int legal(int current_move, int total_stones)
{
    return (current_move <= total_stones);
}

int get_winner(int no_of_stones, vector <int> &moves)
{
    vector <int> winner(no_of_stones + 1, 0);

    winner[0] = 1;

    for(int stones = 1; stones <= no_of_stones; stones++)
    {
        winner[stones] = 2;

        for(int j = 0; j < moves.size(); j++)
        {
            if(legal(moves[j], stones) && winner[stones - moves[j]] == 2)
            {
                winner[stones] = 1;
                break;
            }
        }
    }

    return winner[no_of_stones];
}

int main()
{
    int no_of_stones, no_of_moves;
    scanf("%d %d", &no_of_stones, &no_of_moves);

    vector <int> moves(no_of_moves);
    for(int i = 0; i < no_of_moves; i++)
        scanf("%d", &moves[i]);

    int winner = get_winner(no_of_stones, moves);
    printf("%d\n", winner);

    return 0;
}
