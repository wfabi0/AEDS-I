// Escreva um função em C++ que dado um número de 0 a 9 digitado pelo usuário apresente o número em
// formato de “X” s em uma matriz 5x4.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int n;
  cin >> n;

  while(n < 0 || n > 9) {
    cout << "Número inválido. Por favor, insira um número de 0 a 9." << endl << "Numero: ";
    cin >> n;
  }

  char matrix[4][5];
  char x = 'X', space = ' ';

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++) {
        matrix[i][j] = space;
    }
  }

  switch(n) {
    case 0: {
      for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j] = x;
        }
      }
      matrix[1][1] = space;
      matrix[1][2] = space;
      matrix[2][1] = space;
      matrix[2][2] = space;
      matrix[3][1] = space;
      matrix[3][2] = space;
      break;
    }
    case 1: {
      matrix[0][2] = x;
      matrix[1][2] = x;
      matrix[2][2] = x;
      matrix[3][2] = x;
      matrix[4][2] = x;
      break;
    }
    case 2: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][0] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 3: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 4: {
      matrix[0][0] = x;
      matrix[0][3] = x;
      matrix[1][0] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][3] = x;
      break;
    }
    case 5: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][0] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 6: {
      matrix[0][3] = x;
      matrix[0][2] = x;
      matrix[0][1] = x;
      matrix[0][0] = x;
      matrix[1][0] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][0] = x;
      matrix[3][3] = x;
      matrix[4][0] = x;
      matrix[4][1] = x;
      matrix[4][2] = x;
      matrix[4][3] = x;
      break;
    }
    case 7: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][3] = x;
      matrix[2][2] = x;
      matrix[3][1] = x;
      matrix[4][0] = x;
      break;
    }
    case 8: {
      for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j] = x;
        }
      }
      matrix[1][1] = space;
      matrix[1][2] = space;
      matrix[3][1] = space;
      matrix[3][2] = space;
      break;
    }
    case 9: {
      matrix[0][0] = x;
      matrix[0][1] = x;
      matrix[0][2] = x;
      matrix[0][3] = x;
      matrix[1][0] = x;
      matrix[1][3] = x;
      matrix[2][0] = x;
      matrix[2][1] = x;
      matrix[2][2] = x;
      matrix[2][3] = x;
      matrix[3][3] = x;
      matrix[4][3] = x;
      break;
    }
    default: {
      return 0;
      break;
    }
  }

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++) {
        cout << matrix[i][j];
    }
    cout << endl;
  }

  return 0;
}