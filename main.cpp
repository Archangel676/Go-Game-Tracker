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

void getGroup(char board[MAZE_SIZE][MAZE_SIZE], int row, int col,
              char originalPiece, int& groupNumber,
              bool visited[MAZE_SIZE][MAZE_SIZE])
{
  // cout << "Start location is: (" << row << ", " << col << ")" << endl;

  // char currentPiece = board[row][col];
  if (!isValidPosition(row, col) || board[row][col] != originalPiece
      || visited[row][col]) {
    // cout << "          Empty space - Returning" << endl;
    return;
  }

  visited[row][col] = true;
  board[row][col] = static_cast<char>(toupper(board[row][col]));
  ++groupNumber;

  // cout << "          Matches group..." << endl;

  getGroup(board, row - 1, col, originalPiece, groupNumber, visited); // up

  getGroup(board, row + 1, col, originalPiece, groupNumber, visited); // down

  getGroup(board, row, col - 1, originalPiece, groupNumber, visited); // left

  getGroup(board, row, col + 1, originalPiece, groupNumber, visited); // right

  return;
}

int getLiberties(char board[MAZE_SIZE][MAZE_SIZE],
                 bool visited[MAZE_SIZE][MAZE_SIZE])
{
  int liberties = 0;

  for (int row = 0; row < MAZE_SIZE; ++row) {
    for (int col = 0; col < MAZE_SIZE; ++col) {
      if (visited[row][col]) {
        if (isValidPosition(row - 1, col) && board[row - 1][col] == '-') {
          board[row - 1][col] = '*';
          ++liberties;
        }
        if (isValidPosition(row + 1, col) && board[row + 1][col] == '-') {
          board[row + 1][col] = '*';
          ++liberties;
        }
        if (isValidPosition(row, col - 1) && board[row][col - 1] == '-') {
          board[row][col - 1] = '*';
          ++liberties;
        }
        if (isValidPosition(row, col + 1) && board[row][col + 1] == '-') {
          board[row][col + 1] = '*';
          ++liberties;
        }
      }
    }
  }
  return liberties;
}

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
    return 0;
  }

  int groupNumber = 0;
  bool visited[MAZE_SIZE][MAZE_SIZE] = {false};
  getGroup(board, startRow, startCol, board[startRow][startCol], groupNumber,
           visited);

  int liberties = getLiberties(board, visited);

  printBoard(board); // see changes
  cout << "The size of the group is: " << groupNumber << endl;
  cout << "The number of liberties is: " << liberties << endl;

  return 0;

  //  and the liberties for the group marked as *'s;

  // 3) how many liberties there are.
}
