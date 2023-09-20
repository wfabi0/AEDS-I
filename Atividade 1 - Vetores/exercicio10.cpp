// Fazer um algoritmo que:
// a. Leia 5 valores inteiros e armazene em um vetor A.:
// b. Leia o valor de uma variável inteira X:
// c. Verifique se existe em A algum elemento igual a X. Se existir mostrar qual posição
// este elemento ocupa em A.
// d. Crie um vetor B de 5 posições que vai ser preenchido com os elementos do A divido
// por X, respectivamente.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int a[5], x, b[5];

  for(int i = 0; i < 5; i++) {
    cout << "Insira o valor " << i + 1 << ": ";
    cin >> a[i];
  }

  cout << "Insira o valor de X: ";
  cin >> x;

  for(int i = 0; i < 5; i++) {
    if(a[i] == x) {
      cout << "O valor " << x << " está na posição " << i + 1 << " do vetor A." << endl;
    }
  }

  for(int i = 0; i < 5; i++) {
    b[i] = a[i] / x;
  }

  cout << "Valores na posição B: ";
  for(int i = 0; i < 5; i++) {
    cout << "\t\t" << b[i];
  }
 
  cout << endl << endl;
  return 0;
}