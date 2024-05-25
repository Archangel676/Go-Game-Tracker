#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  char board[9][9]{};
  ifstream file;
  file.open("go.txt");

  // filling to board
  for (int i = 0; i < 9; ++i) {   // rows
    for (int j = 0; j < 9; ++j) { // column
      file >> board[i][j];
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  // getting starting location
  int startLocationX, startLocationY;
  cin >> startLocationX >> startLocationY;
  cout << "Start location is: (" << startLocationX << ", " << startLocationY
       << ")";

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
