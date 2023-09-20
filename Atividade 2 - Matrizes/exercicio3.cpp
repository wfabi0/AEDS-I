// Depois da matriz preenchida, faça a soma dos elementos da diagonal principal e
// depois a soma da diagonal secundária. Depois multiplique a soma da diagonal principal
// pela soma da diagonal secundária

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
        if((i + j) == 8) {
            matriz[i][j] = (i * i) + (j * j) + 2;
        }else if((i + j) > 8) {
            matriz[i][j] = j + 4;
        } else if((i + j) < 8) {
            matriz[i][j] = (3 * i) + j;
        }
    }
  }

  cout << "Matriz: " << endl;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
        cout << matriz[i][j] << "\t\t";
    }
  }

  cout << endl;

  system("pause");
  system("cls");

  int diagonalPrincipal = 0, diagonalSecundaria = 0, diagonalMultiplicacao = 0;
  for(int i = 0; i < 8; i++) {
    diagonalPrincipal += matriz[i][i];
  }
  for(int i = 8; i > 0; i--) {
    diagonalSecundaria += matriz[i][i];
  }
  diagonalMultiplicacao = diagonalPrincipal * diagonalSecundaria;

  cout << "Soma da diagonal principal: " << diagonalPrincipal << endl;
  cout << "Soma da diagonal secundaria: " << diagonalSecundaria << endl;
  cout << "A multiplicação das diagonais é: " << diagonalMultiplicacao << endl;
 
  cout << endl << endl;
  return 0;
}