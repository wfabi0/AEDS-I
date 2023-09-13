// Escreva um função em C++ para ler os elementos de uma matriz 3x3 e imprimir a soma de cada coluna
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

  for(int j = 0; j < 3; j++) {
    int coluna = 0;
    for(int i = 0; i < 3; i++) {
        coluna += matrix[i][j];
    }
    cout << "Coluna " << j << ": " << coluna << endl;
  }

  return 0;
}