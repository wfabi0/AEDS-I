#include <iostream>
#include <windows.h>
#include <stack>

using namespace std;

struct Pessoa
{
  string nome;
  int idade;
};

stack<Pessoa> pilha;

void menu();
void listar();
void inserir();
void remover();

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int option;
  do
  {
    system("cls");
    menu();
    cin >> option;

    switch (option)
    {
    case 0:
    {
      cout << "Programa finalizado." << endl;
      break;
    }
    case 1:
    {
      inserir();
      system("pause");
      break;
    }
    case 2:
    {
      remover();
      system("pause");
      break;
    }
    case 3:
    {
      listar();
      system("pause");
      break;
    }
    default:
    {
      cout << "Opção inválida." << endl;
      system("pause");
      break;
    }
    }
  } while (option != 0);

  cout << endl
       << endl;
  return 0;
}

void menu()
{
  cout << "\tMenu\t" << endl;
  cout << "1 - Inserir" << endl;
  cout << "2 - Remover" << endl;
  cout << "3 - Mostrar" << endl;
  cout << "0 - Sair" << endl;
  cout << "Digite uma opção: ";
}

void inserir()
{
  system("cls");
  Pessoa pessoa;
  cout << "Digite o nome: ";
  cin >> pessoa.nome;
  cout << "Digite a idade: ";
  cin >> pessoa.idade;
  pilha.push(pessoa);
  cout << pessoa.nome << " adicionado na pilha." << endl;
}

void remover()
{
  system("cls");
  if (pilha.size() == 0)
  {
    cout << "Sua pilha está vazia." << endl;
  }
  else
  {
    pilha.pop();
    cout << "Primeira pessoa removida da pilha." << endl;
  }
}

void listar()
{
  if (pilha.size() == 0)
  {
    cout << "Sua pilha está vazia." << endl;
  }
  else
  {
    cout << "\tLista da População\t" << endl;
    stack<Pessoa> pilhaAuxiliar = pilha;
    int contador = 1;
    while (!pilhaAuxiliar.empty())
    {
      Pessoa pessoa = pilhaAuxiliar.top();
      cout << contador << "° - " << pessoa.nome << " | " << pessoa.idade << endl;
      pilhaAuxiliar.pop();
      contador++;
    }
  }
}