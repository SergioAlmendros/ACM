
#include <iostream>
#include <string>

using namespace std;

string s;
char letras[4] = {'a', 'e', 'r', 's'};

void fuerzabruta(int n) {
  cout << s.substr(0, n) << "\n";
  if (n < 10) {
    for (int i = 0; i < 4; ++i) {
      s[n] = letras[i];
      fuerzabruta(n+1);
    }
  }
}

int main() {
  s = string(10, ' ');
  fuerzabruta(0);
}
