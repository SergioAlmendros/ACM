
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char letras[4] = {'a', 'e', 'r', 's'};

int main() {
  string s(4, ' ');
  sort(letras, letras + 4);
  for (int i = 0; i < 4; ++i)
    s[i] = letras[i];
  cout << s << "\n";
}
