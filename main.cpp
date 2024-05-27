#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

const int MAZE_SIZE = 9;
const int COORDINATES = 2;

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
  cout << endl;
  for (int i = 0; i < MAZE_SIZE; ++i) {   // rows
    for (int j = 0; j < MAZE_SIZE; ++j) { // column
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void getStartingLocation(int startingLocation[COORDINATES])
{
  int startRow, startCol;
  cout << "Enter row & column numbers (0-8) with a space in between: ";
  cin >> startRow >> startCol;
  startingLocation[0] = startRow;
  startingLocation[1] = startCol;
}

int getGroup(char board[MAZE_SIZE][MAZE_SIZE],
             int startingLocation[COORDINATES])
{
  int startRow = startingLocation[0];
  int startCol = startingLocation[1];
  cout << "Start location is: (" << startRow << ", " << startCol << ")" << endl;

  int groupNumber = 0;

  if (startCol < 0 || startRow < 0 || startCol >= MAZE_SIZE
      || startRow >= MAZE_SIZE)
    return groupNumber;

  char currentPiece = board[startRow][startCol];
  if (currentPiece == '-')
    return groupNumber;
  else if (currentPiece != board[startRow][startCol])
    return groupNumber;
  else {
    char uppercasePiece = static_cast<char>(toupper(currentPiece));
    board[startRow][startCol] = uppercasePiece;
    return ++groupNumber;
  }
}

int main()
{
  char board[MAZE_SIZE][MAZE_SIZE]{};
  int startingLocation[COORDINATES] = {0, 0};

  readInBoard(board);
  printBoard(board);
  getStartingLocation(startingLocation);
  int groupSize = getGroup(board, startingLocation);
  printBoard(board); // see changes

  return 0;

  // TO-DO
  // Use recursion for determining the size of the group and number of liberties

  // It should print out:
  //  1) the board, with the squares that are in the group made uppercase
  //  and the liberties for the group marked as *'s;

  // 2) the number of pieces in the group based at the starting location;

  // 3) how many liberties there are.

  // If the row, col the user enters does not have a piece in it (is a - instead
  // of w or b), print an error message.
}
