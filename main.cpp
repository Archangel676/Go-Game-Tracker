#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  char board[9][9]{};
  ifstream file;
  file.open("go.txt");

  for (int i = 0; i < 9; ++i) {   // rows
    for (int j = 0; i < 9; ++j) { // column
      file >> board[i][j];
      cout << board[i][j] << " ... ";
    }
    cout << "SPACE";
  }
  return 0;
}
