// Dada uma sequência de n números, imprimi-la na ordem inversa à da leitura.

#include <iostream>
#include <windows.h>

#define TAMANHO 5
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int n[TAMANHO];

  cout << "Insira a sequencia de números: " << endl;

  for(int i = 0; i < TAMANHO; i++) {
    cout << "n[" << i << "]: ";
    cin >> n[i];
  }

  cout << "Sequencia invertida: " << endl;
  for(int i = (TAMANHO - 1); i >= 0; i--) {
    cout << "\t\t" << n[i];
  }
 
  cout << endl << endl;
  return 0;
}