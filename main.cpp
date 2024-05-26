#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const int MAZE_SIZE = 9;

void readInBoard(char board[MAZE_SIZE][MAZE_SIZE])
{
  ifstream file;
  file.open("go.txt");

  for (int i = 0; i < MAZE_SIZE; ++i) { // rows
    for (int j = 0; j < MAZE_SIZE; ++j) // column
      file >> board[i][j];
  }
}

void printBoard(const char board[MAZE_SIZE][MAZE_SIZE])
{
  for (int i = 0; i < MAZE_SIZE; ++i) {   // rows
    for (int j = 0; j < MAZE_SIZE; ++j) { // column
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void getStartingLocation()
{
  // getting starting location
  int startRow, startCol;
  cout << "Enter row & col numbers (1-9) with space between: ";
  cin >> startRow >> startCol;
  cout << "Start location is: (" << startRow << ", " << startCol << ")";
}

int main()
{
  char board[MAZE_SIZE][MAZE_SIZE]{};

  readInBoard(board);
  printBoard(board);
  getStartingLocation();

  return 0;

  // TO-DO
  // Use recursion for determining the size of the group and number of liberties
  // Read in a row and column from the console indicating a starting location.

  // It should print out:
  //  1) the board, with the squares that are in the group made uppercase
  //  and the liberties for the group marked as *'s;

  // 2) the number of pieces in the group based at the starting location;

  // 3) how many liberties there are.

  // If the row, col the user enters does not have a piece in it (is a - instead
  // of w or b), print an error message.
}
