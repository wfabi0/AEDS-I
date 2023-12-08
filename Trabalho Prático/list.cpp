#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

struct Pessoa
{
  string nome;
  int idade;
};

list<Pessoa> populacao;

void menu();
void listar();
void limpar();
void inserirInicio();
void removerInicio();
void inserirPosicao();
void removerPosicao();
void inserirFinal();
void removerFinal();

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
      inserirInicio();
      system("pause");
      break;
    }
    case 2:
    {
      inserirPosicao();
      system("pause");
      break;
    }
    case 3:
    {
      inserirFinal();
      system("pause");
      break;
    }
    case 4:
    {
      listar();
      system("pause");
      break;
    }
    case 5:
    {
      removerInicio();
      system("pause");
      break;
    }
    case 6:
    {
      removerPosicao();
      system("pause");
      break;
    }
    case 7:
    {
      removerFinal();
      system("pause");
      break;
    }
    case 8:
    {
      limpar();
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
  cout << "1 - Inserir inicio" << endl;
  cout << "2 - Inserir posição" << endl;
  cout << "3 - Inserir final" << endl;
  cout << "4 - Mostrar" << endl;
  cout << "5 - Remover inicio" << endl;
  cout << "6 - Remover posição" << endl;
  cout << "7 - Remover final" << endl;
  cout << "8 - Limpar" << endl;
  cout << "0 - Sair" << endl;
  cout << "Digite uma opção: ";
}

void inserirInicio()
{
  system("cls");
  Pessoa pessoa;
  cout << "Digite o nome: ";
  cin >> pessoa.nome;
  cout << "Digite a idade: ";
  cin >> pessoa.idade;

  populacao.push_front(pessoa);
  cout << pessoa.nome << " adicionado(a) no início da população." << endl;
}

void removerInicio()
{
  system("cls");
  if (populacao.size() == 0)
  {
    cout << "Sua população está vazia." << endl;
  }
  else
  {
    populacao.pop_front();
    cout << "Primeira pessoa removida." << endl;
  }
}

void inserirPosicao()
{
  system("cls");
  Pessoa pessoa;
  cout << "Digite o nome: ";
  cin >> pessoa.nome;
  cout << "Digite a idade: ";
  cin >> pessoa.idade;

  int posicao;
  cout << "Digite o índice: ";
  cin >> posicao;

  list<Pessoa>::iterator init = populacao.begin();
  advance(init, posicao);
  populacao.insert(init, pessoa);
  cout << pessoa.nome << " adicionado(a) na " << posicao << "° posição da população." << endl;
}

void removerPosicao()
{
  system("cls");
  if (populacao.size() == 0)
  {
    cout << "Sua população está vazia." << endl;
  }
  else
  {
    int posicao;
    cout << "Digite o índice: ";
    cin >> posicao;

    list<Pessoa>::iterator init = populacao.begin();
    advance(init, posicao);
    populacao.erase(init);
    cout << "Pessoa na " << posicao << "° posição removida." << endl;
  }
}

void inserirFinal()
{
  system("cls");
  Pessoa pessoa;
  cout << "Digite o nome: ";
  cin >> pessoa.nome;
  cout << "Digite a idade: ";
  cin >> pessoa.idade;

  populacao.push_back(pessoa);
  cout << pessoa.nome << " adicionado(a) no final na população." << endl;
}

void removerFinal()
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

void limpar()
{
  system("cls");
  populacao.clear();
  cout << "População reiniciada." << endl;
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
    list<Pessoa>::iterator it;
    int contador = 1;
    for (it = populacao.begin(); it != populacao.end(); ++it)
    {
      cout << contador << "° - " << it->nome << " | " << it->idade << endl;
      contador++;
    }
    cout << endl;
  }
}