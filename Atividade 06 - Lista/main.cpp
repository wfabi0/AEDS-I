#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

const int MAX_LIVROS = 100;

struct Livro
{
    int codigo;
    string nome;
    string editora;
    int ano;
};

struct ListaDeLivros
{
    int quantidade = 0;
    Livro livros[MAX_LIVROS];
};

ListaDeLivros lista;

void inserirInicio(Livro li);
void inserirFim(Livro li);
void inserirEmUmaPosicao(Livro li, int posicao);

void trocarPosicao();
void editarPosicao();

void importarLista();
void exportarLista();

void removerInicio();
void removerFim();
void removerDeUmaPosicao(int posicao);

Livro leDoTeclado();

int menu();

void mostrarLista();

int main()
{

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao, posicao;
    Livro livro;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            livro = leDoTeclado();
            inserirInicio(livro);
            break;
        case 2:
            livro = leDoTeclado();
            cout << "Em qual posicao? ";
            cin >> posicao;
            inserirEmUmaPosicao(livro, posicao);
            break;
        case 3:
            livro = leDoTeclado();
            inserirFim(livro);
            break;
        case 4:
            trocarPosicao();
            break;
        case 5:
            editarPosicao();
            break;
        case 6:
            removerInicio();
            break;
        case 7:
            importarLista();
            break;
        case 8:
            exportarLista();
            break;
        case 9:
            cout << "Em qual posicao? ";
            cin >> posicao;
            removerDeUmaPosicao(posicao);
            break;
        case 10:
            removerFim();
            break;
        case 11:
            mostrarLista();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (opcao != 0);
}

void inserirInicio(Livro li)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        for (int i = lista.quantidade; i > 0; i--)
        {
            lista.livros[i] = lista.livros[i - 1];
        }
        lista.livros[0] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}
void inserirFim(Livro li)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        lista.livros[lista.quantidade] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}
void inserirEmUmaPosicao(Livro li, int posicao)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        for (int i = lista.quantidade; i > posicao; i--)
        {
            lista.livros[i] = lista.livros[i - 1];
        }
        lista.livros[posicao] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}

void removerInicio()
{
    if (lista.quantidade > 0)
    {
        cout << "Removendo ";
        cout << lista.livros[0].codigo << ' ';
        cout << lista.livros[0].nome << endl;
        for (int i = 0; i < lista.quantidade; i++)
        {
            lista.livros[i] = lista.livros[i + 1];
        }
        lista.quantidade = lista.quantidade - 1;
    }
}
void removerFim()
{
    if (lista.quantidade > 0)
    {
        cout << "Removendo ";
        cout << lista.livros[lista.quantidade - 1].codigo << ' ';
        cout << lista.livros[lista.quantidade - 1].nome << endl;
        lista.quantidade = lista.quantidade - 1;
    }
}
void removerDeUmaPosicao(int posicao)
{
    if (lista.quantidade > 0 && posicao < lista.quantidade)
    {
        cout << "Removendo ";
        cout << lista.livros[posicao].codigo << ' ';
        cout << lista.livros[posicao].nome << endl;
        for (int i = posicao; i < lista.quantidade; i++)
        {
            lista.livros[i] = lista.livros[i + 1];
        }
        lista.quantidade = lista.quantidade - 1;
    }
}

void mostrarLista()
{
    cout << endl;
    cout << "++++++ CONTEÚDO DA LISTA ++++++ " << endl;
    for (int i = 0; i < lista.quantidade; i++)
    {
        cout << lista.livros[i].codigo << " | ";
        cout << lista.livros[i].nome << " | ";
        cout << lista.livros[i].editora << " | ";
        cout << lista.livros[i].ano << endl;
    }
    cout << endl;
}

void trocarPosicao()
{
    if (lista.quantidade >= 1)
    {
        int pos1, pos2;
        cout << "Qual deseja selecionar? (Posição 1) ";
        cin >> pos1;
        cout << "Qual posição deseja trocar? (Posição 2) ";
        cin >> pos2;

        if (pos1 > lista.quantidade || pos2 > lista.quantidade)
        {
            cout << "Posição inválida.";
            return;
        }

        if (pos1 == pos2)
        {
            cout << "Você não pode trocar pela mesma posição.";
            return;
        }

        Livro aux = lista.livros[pos1];
        lista.livros[pos1] = lista.livros[pos2];
        lista.livros[pos2] = aux;
        cout << "Posição trocada.";
    }
}

void editarPosicao()
{
    if (lista.quantidade > 0)
    {
        int pos;
        cout << "Qual posição deseja editar? ";
        cin >> pos;

        if (pos > lista.quantidade)
        {
            cout << "Posição inválida.";
            return;
        }

        Livro livro = leDoTeclado();
        lista.livros[pos] = livro;
        cout << "Posição editada.";
    }
}

void importarLista()
{
    ifstream arquivo("lista.txt", std::ios::in);
    if (arquivo.is_open())
    {
        ListaDeLivros lista2;
        lista = lista2;
        while (!arquivo.eof())
        {
            Livro livro;
            arquivo >> livro.codigo >> livro.nome >> livro.editora >> livro.ano;
            inserirFim(livro);
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo.";
    }
}

void exportarLista()
{
    ofstream arquivo("lista.txt");
    if (arquivo.is_open())
    {
        for (int i = 0; i < lista.quantidade; i++)
        {
            arquivo << lista.livros[i].codigo << " ";
            arquivo << lista.livros[i].nome << " ";
            arquivo << lista.livros[i].editora << " ";
            arquivo << lista.livros[i].ano << endl;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo.";
    }
}

Livro leDoTeclado()
{
    Livro livro;
    cout << "Código: ";
    cin >> livro.codigo;
    cout << "Nome: ";
    cin >> livro.nome;
    cout << "Editora: ";
    cin >> livro.editora;
    cout << "Ano: ";
    cin >> livro.ano;
    return livro;
}

int menu()
{
    int opcao;
    cout << "+++++ OPERAÇÕES +++++ " << endl;
    cout << "1 - Inserir no início." << endl;
    cout << "2 - Inserir em uma posição." << endl;
    cout << "3 - Inserir no final." << endl;
    cout << "4 - Alterar posições." << endl;
    cout << "5 - Editar posição." << endl;
    cout << "6 - Remover no início." << endl;
    cout << "7 - Importar lista." << endl;
    cout << "8 - Exportar lista." << endl;
    cout << "9 - Remover em uma posição." << endl;
    cout << "10 - Remover no final." << endl;
    cout << "11 - Mostrar lista." << endl;
    cout << "0 - Sair." << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}