// Fazer um algoritmo que leia 5 valores inteiros e armazena no vetor Ae 5 valores inteiros e
// armazena no vetor B. Depois gere e exiba unm vetor C de 10 elementos, cujos elementos sejam a
// intercalação dos elementos de A e B.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int a[5], b[5], c[10];

  for(int i = 0; i < 5; i++) {
    cout << "Insira o valor " << i + 1 << " de A: ";
    cin >> a[i];
  }

  for(int i = 0; i < 5; i++) {
    cout << "Insira o valor " << i + 1 << " de B: ";
    cin >> b[i];
  }

  int i = 0, j = 0, k = 0;
  while (i < 5 && j < 5) {
    c[k++] = a[i++];
    c[k++] = b[j++];
  }

  while (i < 5) {
    c[k++] = a[i++];
  }

  while (j < 5) {
    c[k++] = b[j++];
  }

  cout << "Vetores intercalado: " << endl;
  for(int i = 0; i < 10; i++) {
    cout << "\t\t" << c[i];
  }
 
  cout << endl << endl;
  return 0;
}