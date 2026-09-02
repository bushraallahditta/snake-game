#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int row = 15;
    int col = 40;

    char board[15][40];

    int snakeR[100];
    int snakeC[100];

    int foodR;
    int foodC;

    int snakelength = 2;

    char direction = 'r';
    char input;

    bool gameover = false;
    int score = 0;

    // Snake starting position
    snakeR[0] = 5;
    snakeC[0] = 16;

    snakeR[1] = 5;
    snakeC[1] = 15;

    // Food position
    foodR = rand() % (row - 2) + 1;
    foodC = rand() % (col - 2) + 1;

    bool foodOnSnake = true;

    while (foodOnSnake)
    {
        foodOnSnake = false;

        for (int i = 0; i < snakelength; i++)
        {
            if (foodR == snakeR[i] && foodC == snakeC[i])
            {
                foodOnSnake = true;
            }
        }

        if (foodOnSnake)
        {
            foodR = rand() % (row - 2) + 1;
            foodC = rand() % (col - 2) + 1;
        }
    }
    cout << "--------START GAMNE ---------" << endl;
    cout << "Controls:" << endl;
    cout << "L = Left" << endl;
    cout << "R = Right" << endl;
    cout << "U = Up" << endl;
    cout << "D = Down" << endl;

    cout << endl;
    cout << "Eat the food (!) to grow." << endl;
    cout << "Do not hit the wall or yourself." << endl;

    cout << endl;
    cout << "Press any key to start: ";
    cin >> input;


    while (!gameover)
    {
        // Create board
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 || i == row - 1 ||
                    j == 0 || j == col - 1)
                {
                    board[i][j] = '#';
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }

        // Put snake on board
        for (int i = 0; i < snakelength; i++)
        {
            board[snakeR[i]][snakeC[i]] = '*';
        }

        // Put food on board
        board[foodR][foodC] = '!';

        // Display board
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }

        // Take input
        cout << "Enter direction (L/R/U/D): ";
        cin >> input;

        // Change direction
        if (input == 'u' || input == 'U')
        {
            direction = 'u';
        }
        else if (input == 'd' || input == 'D')
        {
            direction = 'd';
        }
        else if (input == 'l' || input == 'L')
        {
            direction = 'l';
        }
        else if (input == 'r' || input == 'R')
        {
            direction = 'r';
        }
        // old tail position
        int oldTailR = snakeR[snakelength - 1];
        int oldTailC = snakeC[snakelength - 1];

        // Move body
        for (int i = snakelength - 1; i > 0; i--)
        {
            snakeR[i] = snakeR[i - 1];
            snakeC[i] = snakeC[i - 1];
        }

        // Move head
        if (direction == 'r')
        {
            snakeC[0]++;
        }
        else if (direction == 'l')
        {
            snakeC[0]--;
        }
        else if (direction == 'u')
        {
            snakeR[0]--;
        }
        else if (direction == 'd')
        {
            snakeR[0]++;
        }
        // snake eat food 
        if (snakeR[0] == foodR && snakeC[0] == foodC)
        {
            snakelength++;
            score++;
            snakeR[snakelength - 1] = oldTailR;
            snakeC[snakelength - 1] = oldTailC;

            foodR = rand() % (row - 2) + 1;
            foodC = rand() % (col - 2) + 1;
           
        }


        // Wall collision
        if (snakeR[0] == 0 ||
            snakeR[0] == row - 1 ||
            snakeC[0] == 0 ||
            snakeC[0] == col - 1)
        {
            gameover = true;
        }

        // Self collision
        for (int i = 1; i < snakelength; i++)
        {
            if (snakeR[0] == snakeR[i] &&
                snakeC[0] == snakeC[i])
            {
                gameover = true;
            }
        }
    }
    cout << "Score: " << score << endl;
    cout << "\nGAME OVER!" << endl;

    return 0;
}