// Ler um vetor A de 6 elementos inteiros e um valor X também inteiro. Armazenar em um vetor
// M o resultado de cada elemento de A multiplicado pelo valor X. Logo após, imprimir o vetor M.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int a[6], m[6], x;

  cout << "Insira um valor de x: ";
  cin >> x;

  for(int i = 0; i < 6; i++) {
    cout << "Insira o " << i + 1 << "º valor do vetor: ";
    cin >> a[i];
  }

  for(int i = 0; i < 6; i++) {
    m[i] = a[i] * x;
  }

  cout << "Valores multiplicados: " << endl;
  for(int i = 0; i< 6; i++) {
    cout << "\t\t" << m[i];
  }
 
  cout << endl << endl;
  return 0;
}