// Faço um programa para preencher a matriz 8x8 onde:
// I*I + J*J + 2, se I + J = 8
// J + 4, se I + J > 8
// 3*I + J, se I + J < 8

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int matriz[8][8];

  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
        if(i + j == 8) {
            matriz[i][j] = i * i + j * j + 2;
        }else if(i + j > 8) {
            matriz[i][j] = j + 4;
        } else if(i + j < 8) {
            matriz[i][j] = 3 * i + j;
        }
    }
  }

  system("pause");
  system("cls");

  cout << "Matriz: " << endl;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
        cout << matriz[i][j] << "\t\t";
    }
  }
 
  cout << endl << endl;
  return 0;
}