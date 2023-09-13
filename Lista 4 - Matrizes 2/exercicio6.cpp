// Escreva um função em C++ para verificar se uma matriz 3x3 forma um quadrado mágico.
// Quadrado Mágico é uma tabela quadrada igual a intersecção de números em que a soma de cada coluna, de
// cada linha e das duas diagonais são iguais.

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

  int sum = 0, diagonalPrimary = 0, diagonalSecundary = 0;
  bool isMagic = true;

  for(int i = 0; i < 3; i++) {
    sum += matrix[0][i];
    diagonalPrimary += matrix[i][i];
    diagonalSecundary += matrix[i][3 - 1 - i];
  }

  for(int i = 0; i < 3; i++) {
    int sumRow = 0, sumColumn = 0;
    for(int j = 0; j < 3; j++) {
      sumRow += matrix[i][j];
      sumColumn += matrix[j][i];
    }
    if(sumRow != sum || sumColumn != sum) {
      isMagic = false;
      break;
    }
  }

  if(diagonalPrimary != sum || diagonalSecundary != sum) {
    isMagic = false;
  }

  cout << endl << (isMagic ? "SIM" : "NAO") << endl;

  return 0;
}