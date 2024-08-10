#include <iostream>
#include <vector>

using namespace std;


void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool placeMark(vector<vector<char>>& board, int row, int col, char mark);
bool checkWin(const vector<vector<char>>& board, char mark);
bool checkDraw(const vector<vector<char>>& board);
void playGame();

int main() 
{
    char playAgain;
    
    do 
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing!" << endl;
    return 0;
}

void initializeBoard(vector<vector<char>>& board) 
{
    board = vector<vector<char>>(3, vector<char>(3, ' '));
}

void displayBoard(const vector<vector<char>>& board) 
{
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

bool placeMark(vector<vector<char>>& board, int row, int col, char mark)
 {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
     {
        return false;
    }
    board[row][col] = mark;
    return true;
}

bool checkWin(const vector<vector<char>>& board, char mark) 
{
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) 
            {
            return true;
        }
    }
    
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) 
        {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) 
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void playGame() 
{
    vector<vector<char>> board;
    initializeBoard(board);
    
    char currentPlayer = 'X';
    bool gameWon = false;
    
    while (true) {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        if (!placeMark(board, row - 1, col - 1, currentPlayer)) 
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        
        if (checkWin(board, currentPlayer)) 
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
            break;
        }
        
        if (checkDraw(board)) 
        {
            displayBoard(board);
            cout << "The game is a draw!" << endl;
            break;
        }
        
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}