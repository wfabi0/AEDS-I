// Faça um programa que dado um vetor X de 8 elementos:
// a. Crie um vetor Y contendo os elementos de X que estão na faixa entre 10 e 40.
// b. Crie um vetor W contendo os elementos de X que estão nas posições pares.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int x[8], y[8] = { -0, -0, -0, -0, -0, -0, -0, -0 }, w[8] = { -0, -0, -0, -0, -0, -0, -0, -0 };

  cout << "Insira os valores do vetor x: " << endl;

  for(int i = 0; i < 8; i++) {
    cout << "x[" << i << "]: ";
    cin >> x[i];
  }

  for(int i = 0; i < 8; i++) {
    if(x[i] >= 10 && x[i] <= 40) {
        y[i] = x[i];
    }
    if(i % 2 == 0) {
        w[i] = x[i];
    }
  }

  cout << "Vetor Y: " << endl;
  for(int i = 0; i < 8; i++) {
    if(y[i] != -0) {
        cout << "\t\t" << y[i];
    }
  }

  cout << endl << "Vetor W: " << endl;
  for(int i = 0; i < 8; i++) {
    if(w[i] != -0) {
        cout << "\t\t" << w[i];
    }
  }

  cout << endl << endl;
  return 0;
}