#include <iostream>
using namespace std;

int main()
{
    char board[3][3] =
        {
            {'#', '#', '#'},
            {'#', '#', '#'},
            {'#', '#', '#'}};

    char player = 'X', winner = '#';

    for (int moves = 0; moves < 9; moves++)
    {
        // print board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << board[i][j] << ' ';
            cout << endl;
        }

        int row, column;
        cout << "Enter a row (1-3): ";
        cin >> row;
        cout << "Enter a column (1-3): ";
        cin >> column;

        if (board[row - 1][column - 1] == '#')
            board[row - 1][column - 1] = player;
        else
        {
            cout << "Invalid move\n";
            continue;
        }

        bool gameEnded = false;

        // Column check
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            {
                gameEnded = true;
                winner = player;
                break;
            }
        }
        if (gameEnded)
            break;

        // Row check (FIXED)
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                gameEnded = true;
                winner = player;
                break;
            }
        }
        if (gameEnded)
            break;

        // Diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            winner = player;
            break;
        }

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            winner = player;
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    // Print result
    if (winner == 'X')
        cout << "Player X has won!\n";
    else if (winner == 'O')
        cout << "Player O has won!\n";
    else
        cout << "It's a tie!\n";

    return 0;
}
