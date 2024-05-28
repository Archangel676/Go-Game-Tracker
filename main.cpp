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

bool isValidPosition(int row, int col)
{
  return row >= 0 && row < MAZE_SIZE && col >= 0 && col < MAZE_SIZE;
}
// char board[MAZE_SIZE][MAZE_SIZE], int row, int col, char )

void getGroup(char board[MAZE_SIZE][MAZE_SIZE], int row, int col,
              char originalPiece, int& groupNumber,
              bool visited[MAZE_SIZE][MAZE_SIZE])
{
  cout << "Start location is: (" << row << ", " << col << ")" << endl;

  // char currentPiece = board[row][col];
  if (!isValidPosition(row, col) || board[row][col] != originalPiece
      || visited[row][col]) {
    cout << "          Empty space - Returning" << endl;
    return;
  }

  visited[row][col] = true;
  board[row][col] = static_cast<char>(toupper(board[row][col]));
  ++groupNumber;

  cout << "          Matches group..." << endl;

  getGroup(board, row - 1, col, originalPiece, groupNumber, visited); // up

  getGroup(board, row + 1, col, originalPiece, groupNumber, visited); // down

  getGroup(board, row, col - 1, originalPiece, groupNumber, visited); // left

  getGroup(board, row, col + 1, originalPiece, groupNumber, visited); // right

  return;
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

  readInBoard(board);
  printBoard(board);
  getStartingLocation(startingLocation);

  int startRow = startingLocation[0];
  int startCol = startingLocation[1];

  if (!isValidPosition(startRow, startCol)
      || board[startRow][startCol] == '-') {
    cout << "Invalid starting location. Please try again." << endl;
    getStartingLocation(startingLocation);
  }

  int groupNumber = 0;
  bool visited[MAZE_SIZE][MAZE_SIZE] = {false};
  getGroup(board, startRow, startCol, board[startRow][startCol], groupNumber,
           visited);
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
