// Um professor tem 5 alunos e deseja calcular e imprimir a média da nota da turma e escrever se o
// aluno foi aprovado ou não.

#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int alunos[5], media = 0;

  cout << "Insira a nota dos alunos: " << endl;
  for(int i = 0; i < 5; i++) {
    cin >> alunos[i];
  }

  for(int i = 0; i < 5; i++) {
    media += alunos[i];
  }

  cout << endl << "A media dos alunos e: " << (media / 5) << endl << endl;

  for(int i = 0; i < 5; i++) {
    cout << "Aluno " << (i + 1) << (alunos[i] >= (media / 5) ? " aprovado" : " reprovado") << "." << endl;
  }
 
  cout << endl << endl;
  return 0;
}