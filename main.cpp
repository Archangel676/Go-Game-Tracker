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
    // string rowData;
    // getline(file, rowData);
    // stringstream row(rowData);

    for (int j = 0; j < 9; ++j) { // column
      file >> board[i][j];
      cout << board[i][j] << " ... ";
    }
    cout << "SPACE";
  }
  return 0;
}
