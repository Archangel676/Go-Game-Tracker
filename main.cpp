#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  char board[9][9]{};
  ifstream file;
  file.open("go.txt");

  for (int i = 0; i < 9; ++i) { // rows
    string row;
    getline(file, row);

    for (int j = 0; i < 9; ++j) { // column
      row >> board[i][j];
      cout << board[i][j] << " ... ";
    }
    cout << "SPACE";
  }
  return 0;
}
