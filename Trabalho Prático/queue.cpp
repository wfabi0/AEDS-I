#include <iostream>
#include <windows.h>
#include <queue>

using namespace std;

struct Pessoa
{
    string nome;
    int idade;
};

queue<Pessoa> fila;

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
    fila.push(pessoa);
    cout << pessoa.nome << " adicionado na fila." << endl;
}

void remover()
{
    system("cls");
    if (fila.size() == 0)
    {
        cout << "Sua fila está vazia." << endl;
    }
    else
    {
        fila.pop();
        cout << "Primeira pessoa removida da fila." << endl;
    }
}

void listar()
{
    if (fila.size() == 0)
    {
        cout << "Sua fila está vazia." << endl;
    }
    else
    {
        cout << "\tLista da População\t" << endl;
        queue<Pessoa> filaAuxiliar = fila;
        int contador = 1;
        while (!filaAuxiliar.empty())
        {
            Pessoa pessoa = filaAuxiliar.front();
            cout << contador << "° - " << pessoa.nome << " | " << pessoa.idade << endl;
            filaAuxiliar.pop();
            contador++;
        }
    }
}