#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct Pessoa
{
  string nome;
  int idade;
};

vector<Pessoa> populacao;

void menu();
void inserir();
void remover();
void listar();

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
  cout << "2 - Listar" << endl;
  cout << "0 - Sair" << endl;
  cout << "Digite uma opção: ";
}

void inserir()
{
  system("cls");
  Pessoa pessoa;
  cout << "Insira o primeiro nome: ";
  cin >> pessoa.nome;
  cout << "Insira a idade: ";
  cin >> pessoa.idade;

  populacao.push_back(pessoa);
  cout << pessoa.nome << " adicionado(a) na população." << endl;
}

void remover()
{
  system("cls");
  if (populacao.size() == 0)
  {
    cout << "Sua população está vazia." << endl;
  }
  else
  {
    populacao.pop_back();
    cout << "Última pessoa removida." << endl;
  }
}

void listar()
{
  system("cls");
  if (populacao.size() == 0)
  {
    cout << "Sua população está vazia." << endl;
  }
  else
  {
    cout << "\tLista da População\t" << endl;
    for (int i = 0; i < populacao.size(); i++)
    {
      cout << i + 1 << "° - " << populacao[i].nome << " | " << populacao[i].idade << endl;
    }
    cout << endl;
  }
}