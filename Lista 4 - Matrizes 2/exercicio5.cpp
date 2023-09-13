// Escreva um função em C++ para ler os elementos de uma matriz 3x3 e imprimir a soma de cada diagonal
// da matriz.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int matrix[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cin >> matrix[i][j];
    }
  }

  int diagonalPrimary = 0, diagonalSecundary = 0;
  for(int i = 0; i < 3; i++) {
    diagonalPrimary += matrix[i][i];
    diagonalSecundary += matrix[i][3 - 1 - i];
  }

  cout << endl << "Diagonal principal: " << diagonalPrimary << endl;
  cout << "Diagonal secundaria: " << diagonalSecundary << endl;

  return 0;
}