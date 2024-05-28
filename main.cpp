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

void getGroup(char board[MAZE_SIZE][MAZE_SIZE],
              int startingLocation[COORDINATES], int groupNumber)
{
  int startRow = startingLocation[0];
  int startCol = startingLocation[1];
  cout << "Start location is: (" << startRow << ", " << startCol << ")" << endl;

  if (startCol < 0 || startRow < 0 || startCol >= MAZE_SIZE
      || startRow >= MAZE_SIZE) {
    cout << "          Out of bounds - Returning" << endl;
    return;
  }

  char currentPiece = board[startRow][startCol];
  if (currentPiece == '-') {
    cout << "          Empty space - Returning" << endl;
    return;
  }

  else if (currentPiece != board[startRow][startCol]) {
    cout << "          Wrong group - Returning" << endl;
    return;
  }

  else {
    cout << "          Matches group..." << endl;
    char uppercasePiece = static_cast<char>(toupper(currentPiece));
    board[startRow][startCol] = uppercasePiece;
    ++groupNumber;

    startingLocation[1] = startCol - 1;
    getGroup(board, startingLocation, groupNumber); // left

    startingLocation[0] = startRow + 1;
    getGroup(board, startingLocation, groupNumber); // down

    startingLocation[1] = startCol + 1;
    getGroup(board, startingLocation, groupNumber); // right

    return;
    startingLocation[0] = startRow - 1;
    getGroup(board, startingLocation, groupNumber); // up

    return;
  }
}

// add a visited function???
// Check discord

// - is 45
// B is 66
// W is 87
// b is 98
// w is 119

int main()
{
  char board[MAZE_SIZE][MAZE_SIZE]{};
  int startingLocation[COORDINATES] = {0, 0};
  int groupNumber = 0;

  readInBoard(board);
  printBoard(board);
  getStartingLocation(startingLocation);
  if (board[startingLocation[0]][startingLocation[1]] == '-') {
    cout << "Invalid starting location. Please try again." << endl;
    getStartingLocation(startingLocation);
  }

  getGroup(board, startingLocation, groupNumber);
  cout << "The size of our group is: " << groupNumber << endl;
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
