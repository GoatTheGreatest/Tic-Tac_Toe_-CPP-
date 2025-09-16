//* Code by Abdul Raheem (GoatTheGreatest)

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void plMove(char *spaces);
void cpuMove(char *spaces);
bool winner(char *spaces);
bool checkTie(char *spaces);
int main()
{
    bool playerTurn = true;
    bool gameOn = true;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    while (gameOn)
    {
        drawBoard(spaces);
        plMove(spaces);
        if (winner(spaces))
        {
            gameOn = false;
            break;
        }
        else if (checkTie(spaces))
        {
            gameOn = false;
            break;
        }

        drawBoard(spaces);
        cpuMove(spaces);
        if (winner(spaces))
        {
            gameOn = false;
            break;
        }
        else if (checkTie(spaces))
        {
            gameOn = false;
            break;
        }
    }
    cout << "Thanks for playing bro :) \n";
    return 0;
}

void drawBoard(char *spaces)
{
    cout << "\n     |     |     \n";
    cout << "  " << spaces[0] << "  |" << "  " << spaces[1] << "  |  " << spaces[2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << spaces[3] << "  |" << "  " << spaces[4] << "  |  " << spaces[5] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << spaces[6] << "  |" << "  " << spaces[7] << "  |  " << spaces[8] << endl;
    cout << "     |     |     \n";
}

void plMove(char *spaces)
{
    int i;
    cout << "Enter location to play your move (1-9): " << endl;
    cin >> i;
    if (spaces[i - 1] == ' ')
    {
        spaces[i - 1] = 'X';
    }
    else
    {
        cout << "That place is taken. Play some other move!!!\n";
        plMove(spaces);
    }
}

void cpuMove(char *spaces)
{
    srand(time(0));
    int i = rand() % 9;
    if (spaces[i] == ' ')
    {
        spaces[i] = 'O';
    }
}

bool winner(char *spaces)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        (spaces[0] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        (spaces[3] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        (spaces[6] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[0] == spaces[6])
    {
        (spaces[0] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[1] == spaces[7])
    {
        (spaces[1] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[2] == spaces[8])
    {
        (spaces[2] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[0] == spaces[8])
    {
        (spaces[0] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[2] == spaces[6])
    {
        (spaces[2] == 'X') ? cout << "YOU WIN!!!\n" : cout << "YOU LOSE!!!\n";
    }
    else
    {
        return false;
    }
    return true;
}

bool checkTie(char *spaces)
{

    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}