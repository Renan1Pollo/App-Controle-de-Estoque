#include <iostream>
#include <locale.h>
#include <cstring>
#define t 20

using namespace std;


struct Tipo
{
    int idTipo;
    string descricao;
};
struct Produtos
{
    int idProduto;
    string descricao;
    int codTipo;
    int codFornecedor;
    int qtdEstoque;
    int estoqueMin;
    int estoqueMax;
    float valorUnit;
};
struct Estado
{
    int idEstado;
    string nome;
};
struct Fornecedor
{
    int idFornecedor;
    string nome;
    string endereco;
    string telefone;
    int codUf;
    string cnpj;
};

void cadastrarTipo(Tipo *tipo, int &contador);
void cadastrarProduto(Produtos *produto, int &contador);
void cadastrarEstado(Estado *estado, int &contador);
void cadastrarFornecedor(Fornecedor *fornecedor, int &contador);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    Estado estado[t];
    Tipo tipo[t];
    Produtos produto[t];
    Fornecedor fornecedor[t];

    int contEstado = 0;
    int contTipo = 0;
    int contProduto = 0;
    int contFornecedor = 0;

    while (opcao != 7)
    {
        system("cls");
        cout << "\t\tSistema de controle de estoque\n\n";
        cout << "1 - Cadastros" << endl;
        cout << "2 - Inclusao" << endl;
        cout << "3 - Venda" << endl;
        cout << "4 - Mostrar" << endl;
        cout << "7 - Sair" << endl;
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");
            int opcao1;
            while (opcao1 != 5)
            {
                system("cls");
                cout << "\t\tCadastros\n\n";
                cout << "1 - Produto" << endl;
                cout << "2 - Fornecedor" << endl;
                cout << "3 - Tipo" << endl;
                cout << "4 - Estado" << endl;
                cout << "5 - Voltar";

                cout << "\n\nEscolha uma opcao: ";
                cin >> opcao1;

                switch (opcao1)
                {
                case 1:
                    system("cls");
                    cadastrarProduto(produto, contProduto);
                    opcao1 = 0;
                    break;

                case 2:
                    system("cls");
                    cadastrarFornecedor(fornecedor, contFornecedor);
                    opcao1 = 0;
                    break;

                case 3:
                    system("cls");
                    cadastrarTipo(tipo, contTipo);
                    opcao1 = 0;
                    break;

                case 4:
                    system("cls");
                    cadastrarEstado(estado, contEstado);
                    opcao1 = 0;
                    break;

                case 5:
                    system("cls");
                    cout << "Voltando...\n\n\n";
                    break;

                default:
                    system("cls");
                    cout << "Opcao invalida! Informe um valor entre 1 e 5.\n\n\n";
                    system("pause");
                    opcao1 = 0;
                    break;
                }
            }
            opcao1 = 0;
            break;

        case 2:
            system("cls");

            int opcao2;
            while (opcao2 != 3)
            {
                system("cls");
                cout << "\t\tInserir novos Cadastros\n\n";
                cout << "1 - Fornecedor" << endl;
                cout << "2 - Produto" << endl;
                cout << "3 - Voltar";

                cout << "\n\nEscolha uma opcao: ";
                cin >> opcao2;

                switch (opcao2)
                {
                case 1:
                    system("cls");
                    opcao2 = 0;
                    break;

                case 2:
                    system("cls");

                    break;

                case 3:
                    system("cls");
                    cout << "Voltando...\n\n\n";
                    break;

                default:
                    system("cls");
                    cout << "Opcao invalida!\n\n\n";
                    system("pause");
                    opcao2 = 0;
                    break;
                }
            }
            opcao2 = 0;
            break;

        case 3:
            system("cls");

            break;

        case 4:
            system("cls");
            system("pause");
            opcao = 0;
            break;

        case 7:
            system("cls");
            cout << "Saindo...\n\n\n";
            break;

        default:
            system("cls");
            cout << "Opcao invalida! Informe um valor entre 1 e 7.\n\n\n";
            system("pause");
            opcao = 0;
            break;
        }
    }
}

void cadastrarTipo(struct Tipo tipos[], int &contador)
{
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++)
    {
        cout << "\t\tCadastro tipo\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n\n";

        cout << "ID: ";
        cin >> tipos[i].idTipo;
        if (tipos[i].idTipo != -1)
        {
            cout << "Descricao: ";
            cin >> tipos[i].descricao;
            system("cls");
        }
        else
        {
            saida = -1;
        }
    }
    contador = i - 1;
    system("cls");
}
void cadastrarProduto(struct Produtos produtos[], int &contador)
{
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++)
    {
        cout << "\t\tCadastro produto\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n\n";

        cout << " ID: ";
        cin >> produtos[i].idProduto;
        if (produtos[i].idProduto != -1)
        {
            cout << " Descricao: ";
            cin >> produtos[i].descricao;
            cout << " Tipo: ";
            cin >> produtos[i].codTipo;
            cout << " Codigo do fornecedor: ";
            cin >> produtos[i].codFornecedor;
            cout << " Quantidade em estoque: ";
            cin >> produtos[i].qtdEstoque;
            cout << " Estoque minimo: ";
            cin >> produtos[i].estoqueMin;
            cout << " Estoque maximo: ";
            cin >> produtos[i].estoqueMax;
            cout << " Valor unitario: ";
            cin >> produtos[i].valorUnit;
            system("cls");
        }
        else
        {
            saida = -1;
        }
    }
    contador = i - 1;
    system("cls");
}
void cadastrarEstado(struct Estado estados[], int &contador)
{
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++)
    {
        cout << "\t\tCadastro estado\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n";

        cout << "\n ID: ";
        cin >> estados[i].idEstado;
        if (estados[i].idEstado != -1)
        {
            cout << " Nome do estado: ";
            cin >> estados[i].nome;
            system("cls");
        }
        else
        {
            saida = -1;
        }
    }
    contador = i - 1;
}
void cadastrarFornecedor(struct Fornecedor fornecedor[], int &contador)
{
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++)
    {
        cout << "\t\tCadastro fornecedor\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n";

        cout << " ID: ";
        cin >> fornecedor[i].idFornecedor;
        if (fornecedor[i].idFornecedor != -1)
        {
            cout << " Nome do fornecedor: ";
            cin >> fornecedor[i].nome;
            cout << " Endereco: ";
            cin >> fornecedor[i].endereco;
            cout << " Telefone: ";
            cin >> fornecedor[i].telefone;
            cout << " Codigo do estado: ";
            cin >> fornecedor[i].codUf;
            cout << " Cnpj: ";
            cin >> fornecedor[i].cnpj;

            system("cls");
        }
        else
        {
            saida = -1;
        }
    }
    contador = i - 1;
    system("cls");
}
