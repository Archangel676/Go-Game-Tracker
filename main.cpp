#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  char board[9][9]{};
  ifstream file;
  file.open("go.txt");

  for (int i = 0; i < 9; ++i) {   // rows
    for (int j = 0; i < 9; ++i) { // column
      int x;
      cin >> x;
      cout << x;
    }
  }
}
