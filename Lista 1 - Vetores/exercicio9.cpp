// Deseja-se publicar o número de acertos de cada aluno em uma prova em forma de testes. A
// prova consta de 3 questões, cada uma com cinco alternativas identificadas por A, B, C, D, E. Para
// isso são dados:
// a. o cartão gabarito;
// b. o número de alunos da turma:
// C. o cartão de respostas para cada aluno, contendo o seu número e suas respostas.

#include <iostream>
#include <windows.h>

#define QUESTOES 3
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  char gabarito[QUESTOES];
  int alunos;

  cout << "Insira o gabarito da prova:" << endl;
  for(int i = 0; i < QUESTOES; i++) {
    cout << "Questão " << i + 1 << ": ";
    cin >> gabarito[i];
  }

  cout << "Insira o número de alunos: ";
  cin >> alunos;

  char respostas[alunos][QUESTOES]; 
  int acertos[alunos];

  for(int i = 0; i < alunos; i++) {
    cout << "Insira as respostas do aluno " << i + 1 << ":" << endl;
    for(int j = 0; j < QUESTOES; j++) {
      cout << "Questão " << j + 1 << ": ";
      cin >> respostas[i][j];
    }
  }

  for(int i = 0; i < alunos; i++) {
    acertos[i] = 0;
    for(int j = 0; j < QUESTOES; j++) {
      if(respostas[i][j] == gabarito[j]) {
        acertos[i]++;
      }
    }
  }

  for(int i = 0; i < alunos; i++) {
    cout << "O aluno " << i + 1 << " acertou " << acertos[i] << " questões." << endl;
  }
 
  cout << endl << endl;
  return 0;
}