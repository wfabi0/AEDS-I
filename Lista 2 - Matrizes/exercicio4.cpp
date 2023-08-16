// Faça um programa para preencher duas matrizes A e B de dimensão (3x5) de
// números inteiros. Depois gere uma matriz C, cujo conteúdo é a soma da matriz A com a
// matriz B

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int A[3][5], B[3][5], C[3][5];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
        cout << "Digite o valor da matriz A[" << i << "][" << j << "]: ";
        cin >> A[i][j];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
        cout << "Digite o valor da matriz B[" << i << "][" << j << "]: ";
        cin >> B[i][j];
    }
  }

  cout << endl << endl << "Resultado entre a soma da matriz A com a matriz B" << endl << "Matriz C: " << endl;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
        C[i][j] = A[i][j] + B[i][j];
        cout << C[i][j] << "\t\t";
    }
  }
 
  cout << endl << endl;
  return 0;
}