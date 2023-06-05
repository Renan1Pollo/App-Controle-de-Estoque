#include <iostream>
#include <clocale>
#include <cstring>
#define t 20

using namespace std;

struct Tipo {
    int idTipo;
    string descricao;
};
struct Produtos {
    int idProduto;
    string descricao;
    int codTipo;
    int codFornecedor;
    int qtdEstoque;
    int estoqueMin;
    int estoqueMax;
    float valorUnit;
};
struct Estado {
    int idEstado;
    string nome;
};
struct Fornecedor {
    int idFornecedor;
    string nome;
    string endereco;
    string telefone;
    int codUf;
    string cnpj;
};

void cadastrarTipo(Tipo *tipo, int &contador);
void cadastrarProduto(Produtos *produtos, int &contador, Tipo *tipo, int contTipo ,Fornecedor *fornecedor, int contFornecedor);
void cadastrarFornecedor(Fornecedor *fornecedor, int &contador, Estado *estado, int contEstado);
void cadastrarEstado(Estado *estado, int &contador);
void cadastrarNovoProduto(Produtos *produtos, Produtos *produtosA, int &contador, int contadorA, Tipo *tipos, int contTipo, Fornecedor *fornecedores, int contFornecedor );

void incluirFornecedor(Fornecedor *fornecedorN, Fornecedor *fornecedorA, int &contador, Estado *estado, int contEstado);
void incluirProdutos(Produtos *produtosA, Produtos *produtosB, int &contador, Fornecedor *fornecedor, int contFornecedor, Tipo *tipo, int contTipo);
void adicionarVenda(Produtos *produtos, Fornecedor *fornecedores, Tipo *tipos, int contProdutos, int contFornecedores, int contTipos);

bool buscarTipo(int codTipo, Tipo *tipo, int contTipo);
bool buscarEstado(int codEstado, Estado *estado, int contEstado);
bool buscarFornecedor(int codFornecedor, Fornecedor *fornecedor, int contFornecedor);
bool buscarProduto(int codProduto, Produtos *produto, int contProduto);
int buscarProduto2(int codProduto, Produtos produto[], int contProduto);

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao = 0;

    Estado estado[t];
    Tipo tipo[t];
    Produtos produto[t];
    Produtos produtoN[t];
    Fornecedor fornecedor[t];
    Fornecedor fornecedorN[t];

    int contEstado = 0;
    int contTipo = 0;
    int contProduto = 0;

    int contFornecedor = 0;

    while (opcao != 7) {
        system("cls");
        cout << "\t\tSistema de controle de estoque\n\n";
        cout << " 1 - Cadastros" << endl;
        cout << " 2 - Inclusao" << endl;
        cout << " 3 - Venda" << endl;
        cout << " 4 - Mostrar" << endl;
        cout << " 7 - Sair" << endl;
        cout << "\n Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            system("cls");
            int opcao1;
            while (opcao1 != 5) {
                system("cls");
                cout << "\t\t Cadastros\n\n";
                cout << " 1 - Produto" << endl;
                cout << " 2 - Fornecedor" << endl;
                cout << " 3 - Tipo" << endl;
                cout << " 4 - Estado" << endl;
                cout << " 5 - Voltar";

                cout << "\n\n Escolha uma opcao: ";
                cin >> opcao1;

                switch (opcao1) {
                case 1:
                    system("cls");
                    cadastrarProduto(produto, contProduto, tipo, contTipo, fornecedor, contFornecedor);
                    opcao1 = 0;
                    break;

                case 2:
                    system("cls");
                    cadastrarFornecedor(fornecedor, contFornecedor, estado, contEstado);
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
                    cout << " Opcao invalida! Informe um valor entre 1 e 5.\n\n\n";
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
            while (opcao2 != 3) {
                system("cls");
                cout << "\t\t Inserir novos Cadastros\n\n";
                cout << " 1 - Fornecedor" << endl;
                cout << " 2 - Produto" << endl;
                cout << " 3 - Voltar";

                cout << "\n\n Escolha uma opcao: ";
                cin >> opcao2;

                switch (opcao2) {
                case 1:
                    system("cls");
                    incluirFornecedor(fornecedorN, fornecedor, contFornecedor, estado, contEstado);
                    opcao2 = 0;
                    break;
                case 2:
                    system("cls");
                    incluirProdutos(produto, produtoN, contProduto, fornecedor, contFornecedor, tipo, contTipo);
                    break;
                case 3:
                    system("cls");
                    cout << "Voltando...\n\n\n";
                    break;
                default:
                    system("cls");
                    cout << " Opcao invalida!\n\n\n";
                    system("pause");
                    opcao2 = 0;
                    break;
                }
            }
            opcao2 = 0;
            break;

        case 3:
            system("cls");
            adicionarVenda(produto, fornecedor, tipo, contProduto, contFornecedor, contTipo);
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
            cout << " Opcao invalida! Informe um valor entre 1 e 7.\n\n\n";
            system("pause");
            opcao = 0;
            break;
        }
    }
}

void cadastrarTipo(Tipo tipos[], int &contador) {
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++) {
        cout << "\t\tCadastro tipo\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n\n";

        cout << "ID: ";
        cin >> tipos[i].idTipo;
        if (tipos[i].idTipo > 0) {
            cout << "Descricao: ";
            cin >> tipos[i].descricao;
            system("cls");
        } else {
            saida = -1;
        }
    }
    contador = i - 1;
    system("cls");
}
void cadastrarProduto(Produtos produtos[], int &contador, Tipo tipos[], int contTipo ,Fornecedor fornecedor[], int contFornecedor) {
    int saida = 0;
    int i;

    for (i = 0; i < t && saida != -1; i++) {
        cout << "\t\tCadastro produto\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n\n";

        cout << " ID: ";
        cin >> produtos[i].idProduto;
        if (produtos[i].idProduto > 0) {
            cout << " Descricao: ";
            cin >> produtos[i].descricao;

            for(int j = 0; j < contTipo; j++){
			    cout<<"\n\t ===== Listagem de Tipos =====" << endl;
			    cout<<" Codigo: "<<tipos[j].idTipo << endl;
			    cout<<" Descricao: "<<tipos[j].descricao;
		    }
            cout << "\n\n Tipo: ";
            cin >> produtos[i].codTipo;
            bool resultadoTipo = buscarTipo(produtos[i].codTipo, tipos, contTipo);
            while (!resultadoTipo) {
               cout << "\n\t ===== Codigo do Tipo invalido =====" << endl;
               cout << " Tipo: ";
               cin >> produtos[i].codTipo;
               resultadoTipo = buscarTipo(produtos[i].codTipo, tipos, contTipo);
            }

            for(int j = 0; j < contFornecedor; j++){
			    cout<<"\n\t ===== Listagem de Fornecedores =====" << endl;
			    cout<<" Codigo: " << fornecedor[j].idFornecedor << endl;
			    cout<<" Nome: " << fornecedor[j].nome;
		    }
            cout << "\n\n Codigo do fornecedor: ";
            cin >> produtos[i].codFornecedor;
            bool resultado = buscarFornecedor(produtos[i].codFornecedor, fornecedor, contFornecedor);
            while (!resultado) {
               cout << "\n\t ===== Codigo do Fornecedor invalido =====" << endl;
               cout << " Codigo do Fornecedor: ";
               cin >> produtos[i].codFornecedor;
               resultado = buscarFornecedor(produtos[i].codFornecedor, fornecedor, contFornecedor);
            }

            cout << " Quantidade em estoque: ";
            cin >> produtos[i].qtdEstoque;
            cout << " Estoque minimo: ";
            cin >> produtos[i].estoqueMin;
            cout << " Estoque maximo: ";
            cin >> produtos[i].estoqueMax;
            cout << " Valor unitario: ";
            cin >> produtos[i].valorUnit;
            system("cls");
        } else {
            saida = -1;
        }
    }
    contador = i - 1;
    system("cls");
}
void cadastrarEstado(Estado estados[], int &contador) {
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++) {
        cout << "\t\tCadastro estado\n\n";
        cout << "\t Se desejar sair digite o ID como -1\n";

        cout << "\n ID: ";
        cin >> estados[i].idEstado;
        if (estados[i].idEstado > 0) {
            cout << " Nome do estado: ";
            cin >> estados[i].nome;
            system("cls");
        } else {
            saida = -1;
        }
    }
    contador = i - 1;
}
void cadastrarFornecedor(Fornecedor fornecedor[], int &contador, Estado estado[], int contEstado) {
    int saida = 0;
    int i;
    for (i = 0; i < t && saida != -1; i++) {
        cout << "\t\tCadastro fornecedor\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n";

        cout << " ID: ";
        cin >> fornecedor[i].idFornecedor;
        if (fornecedor[i].idFornecedor > 0) {
            cout << " Nome do fornecedor: ";
            cin >> fornecedor[i].nome;
            cout << " Endereco: ";
            cin >> fornecedor[i].endereco;
            cout << " Telefone: ";
            cin >> fornecedor[i].telefone;
            cout << " Codigo do estado: ";
            cin >> fornecedor[i].codUf;

            bool resultado = buscarEstado(fornecedor[i].codUf, estado, contEstado);
            while (!resultado) {
               cout << "\n\t ===== Codigo do Estado invalido =====" << endl;
               cout << " Codigo do estado: ";
               cin >> fornecedor[i].codUf;
               resultado = buscarEstado(fornecedor[i].codUf, estado, contEstado);
            }
            cout << " Cnpj: ";
            cin >> fornecedor[i].cnpj;

            system("cls");
        } else {
            saida = -1;
        }
    }
    contador = i - 1;
    system("cls");
}
void cadastrarNovoProduto(Produtos produtosT[], Produtos produtosA[], int &contadorT, int contadorA  ,Tipo tipos[], int contTipo, Fornecedor fornecedores[], int contFornecedor ) {
    int saida = 0;
    int i;

    for (i = 0; i < t && saida != -1; i++) {
        cout << "\t\tCadastro produto\n\n";
        cout << "\tSe desejar sair digite o ID como -1\n\n";

        cout << " ID: ";
        cin >> produtosT[i].idProduto;
        if (produtosT[i].idProduto > 0) {
            bool resultadoProduto = buscarProduto(produtosT[i].idProduto, produtosA, contadorA);
            while (!resultadoProduto) {
                cout << "\n\t ===== Codigo ja cadastrado! =====" << endl;
                cout << " ID: ";
                cin >> produtosT[i].idProduto;
                resultadoProduto = buscarProduto(produtosT[i].idProduto, produtosA, contadorA);
            }

            cout << " Descricao: ";
            cin >> produtosT[i].descricao;

            for(int j = 0; j < contTipo; j++) {
			    cout<<"\n\t ===== Listagem de Tipos =====" << endl;
			    cout<<" Codigo: "<< tipos[j].idTipo << endl;
			    cout<<" Descricao: "<< tipos[j].descricao;
		    }
            cout << "\n\n Tipo: ";
            cin >> produtosT[i].codTipo;
            bool resultadoTipo = buscarTipo(produtosT[i].codTipo, tipos, contTipo);
            while (!resultadoTipo) {
               cout << "\n\t ===== Codigo do Tipo invalido =====" << endl;
               cout << " Tipo: ";
               cin >> produtosT[i].codTipo;
               resultadoTipo = buscarTipo(produtosT[i].codTipo, tipos, contTipo);
            }

            for(int j = 0; j < contFornecedor; j++){ 
			    cout<<"\n\t ===== Listagem de Fornecedores =====" << endl;
			    cout<<" Codigo: " << fornecedores[j].idFornecedor << endl;
			    cout<<" Nome: " << fornecedores[j].nome;
		    }
            cout << "\n\n Codigo do fornecedor: ";
            cin >> produtosT[i].codFornecedor;
            bool resultado = buscarFornecedor(produtosT[i].codFornecedor, fornecedores, contFornecedor);
            while (!resultado) {
               cout << "\n\t ===== Codigo do Fornecedor invalido =====" << endl;
               cout << " Codigo do Fornecedor: ";
               cin >> produtosT[i].codFornecedor;
               resultado = buscarFornecedor(produtosT[i].codFornecedor, fornecedores, contFornecedor);
            }

            cout << " Quantidade em estoque: ";
            cin >> produtosT[i].qtdEstoque;
            cout << " Estoque minimo: ";
            cin >> produtosT[i].estoqueMin;
            cout << " Estoque maximo: ";
            cin >> produtosT[i].estoqueMax;
            cout << " Valor unitario: ";
            cin >> produtosT[i].valorUnit;
            system("cls");
        } else {
            saida = -1;
        }
    }
    contadorT = i - 1;
    system("cls");
}

void incluirFornecedor(Fornecedor fornecedorN[], Fornecedor fornecedorA[], int &contador, Estado estado[], int contEstado) {
    Fornecedor fornecedorT[t];
    int contFornecedorT = 0;
    cadastrarFornecedor(fornecedorT, contFornecedorT, estado, contEstado);

    int i = 0, j = 0, z = 0;
	for(;i < contador && j < contFornecedorT; z++) {
		if (fornecedorA[i].idFornecedor < fornecedorT[j].idFornecedor) {
			fornecedorN[z] = fornecedorA[i];
			i++;
		} else {
			fornecedorN[z] = fornecedorT[j];
			j++;
		}
	}

	for(; i < contador; i++) {
		fornecedorN[z] = fornecedorA[i];
		z++;
	}

	for(; j < contFornecedorT; j++) {
		fornecedorN[z] = fornecedorT[j];
		z++;
	}

    int x = 0;
    for (; x < z; x++) {
        fornecedorA[x] = fornecedorN[x];
    }
    contador = x;
    cout << "\t\t===== Fornecedores Inseridos com Sucesso =====" << endl;
    system("PAUSE");
}
void incluirProdutos(Produtos produtoA[], Produtos produtoN[], int &contador, Fornecedor fornecedor[], int contFornecedor, Tipo tipo[], int contTipo) {
    Produtos produtoT[t];
    int contProdutoT = 0;
    cadastrarNovoProduto(produtoT, produtoA, contProdutoT, contador ,tipo, contTipo, fornecedor, contFornecedor);

    int i = 0, j = 0, z = 0;
	for(;i < contador && j < contProdutoT; z++) {
		if (produtoA[i].idProduto < produtoT[j].idProduto) {
			produtoN[z] = produtoA[i];
			i++;
		} else {
			produtoN[z] = produtoT[j];
			j++;
		}
	}

	for(; i < contador; i++) {
		produtoN[z] = produtoA[i];
		z++;
	}

	for(; j < contProdutoT; j++) {
		produtoN[z] = produtoT[j];
		z++;
	}

    int x = 0;
    for (; x < z; x++) {
        produtoA[x] = produtoN[x];
    }
    contador = x;
    cout << "\t ===== Produtos Inseridos com Sucesso =====" << endl;
    system("PAUSE");
}

bool buscarEstado(int codEstado, Estado estado[], int contEstado) {
    int inicio = 0;
    int final = contEstado;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codEstado != estado[meio].idEstado; meio = (inicio + final) / 2){
        if (codEstado > estado[meio].idEstado)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codEstado == estado[meio].idEstado) {
        cout << "\n ===== Estado Encontrado =====" << endl;
        cout << " Codigo do Estado: " << estado[meio].idEstado << endl;
        cout << " Nome do Estado: " << estado[meio].nome << endl << endl;
        return true;
    } else {
        return false;
    }
}
bool buscarFornecedor(int codFornecedor, Fornecedor fornecedor[], int contFornecedor) {
    int inicio = 0;
    int final = contFornecedor;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codFornecedor != fornecedor[meio].idFornecedor; meio = (inicio + final) / 2){
        if (codFornecedor > fornecedor[meio].idFornecedor)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codFornecedor == fornecedor[meio].idFornecedor) {
        cout << "\n ===== Fornecedor Encontrado =====" << endl;
        cout << " Codigo do Fornecedor: " << fornecedor[meio].idFornecedor << endl;
        cout << " Nome do Fornecedor: " << fornecedor[meio].nome << endl << endl;
        return true;
    } else {
        return false;
    }
}
bool buscarTipo(int codTipo, Tipo tipo[], int contTipo) {
    int inicio = 0;
    int final = contTipo;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codTipo != tipo[meio].idTipo; meio = (inicio + final) / 2){
        if (codTipo > tipo[meio].idTipo)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codTipo == tipo[meio].idTipo) {
        cout << "\n ===== Tipo Encontrado =====" << endl;
        cout << " Codigo do Tipo " << tipo[meio].idTipo << endl;
        cout << " Descricao do Tipo: " << tipo[meio].descricao << endl;
        return true;
    } else {
        return false;
    }
     
}
bool buscarProduto(int codProduto, Produtos produto[], int contProduto) {
    int inicio = 0;
    int final = contProduto;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codProduto != produto[meio].idProduto; meio = (inicio + final) / 2){
        if (codProduto > produto[meio].idProduto)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codProduto == produto[meio].idProduto) {
        return false;
    } else {
        return true;
    }
}

int buscarProduto2(int codProduto, Produtos produto[], int contProduto) {
    int inicio = 0;
    int final = contProduto;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codProduto != produto[meio].idProduto; meio = (inicio + final) / 2){
        if (codProduto > produto[meio].idProduto)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codProduto == produto[meio].idProduto) {
        return meio;
    } else {
        return -1;
    }
}
int buscarTipo2(int codTipo, Tipo tipo[], int contTipo) {
    int inicio = 0;
    int final = contTipo;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codTipo != tipo[meio].idTipo; meio = (inicio + final) / 2){
        if (codTipo > tipo[meio].idTipo)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codTipo == tipo[meio].idTipo) {
        return meio;
    } else {
        return -1;
    }
     
}
int buscarFornecedor2(int codFornecedor, Fornecedor fornecedor[], int contFornecedor) {
    int inicio = 0;
    int final = contFornecedor;
    int meio = (inicio + final)/2;

    for (; final >= inicio && codFornecedor != fornecedor[meio].idFornecedor; meio = (inicio + final) / 2){
        if (codFornecedor > fornecedor[meio].idFornecedor)
            inicio = meio + 1;
        else
            final = meio - 1;
    }

    if (codFornecedor == fornecedor[meio].idFornecedor) {
        return meio;
    } else {
        return -1;
    }
}

void adicionarVenda(Produtos produtos[], Fornecedor fornecedores[], Tipo tipos[], int contProdutos, int contFornecedores, int contTipos) {
	int codProduto = 0;
	cout << "\t\tADICIONAR VENDA\n\n";
	cout << " Informe o Codigo do produto a ser vendido: ";
	cin >> codProduto;
	
	int indice = buscarProduto(codProduto, produtos, contProdutos);
	if (produtos[indice].idProduto > 0) {
        cout << "\n\t\t ===== Detalhes do Produto =====\n\n";
        cout << " Codigo do produto: " << produtos[indice].idProduto << endl;
        cout << " Descricao do produto: " << produtos[indice].descricao << endl;
        cout << " Quantidade em Estoque: " << produtos[indice].qtdEstoque << endl;
        cout << " Valor unitario: " << produtos[indice].valorUnit << endl;

        int aux = buscarTipo2(produtos[indice].codTipo, tipos, contTipos);
        cout << " Tipo: " << tipos[aux].descricao << endl;

        aux = buscarFornecedor2(produtos[indice].codFornecedor, fornecedores, contFornecedores);
        cout << " Fornecedor: " << fornecedores[aux].nome << endl;
        cout << "\t\t ===============================\n\n";

        cout << " Digite a Quantidade a ser Vendida deste Produto: ";
        cin >> aux;
        while(aux > produtos[indice].qtdEstoque) {
		    cout << "\n\t ===== Quantidade em estoque insuficiente! =====" << endl;
		    cout << " Limite: " << produtos[indice].qtdEstoque << endl;
		    cout << " Digite a Quantidade a ser Vendida deste Produto: ";
		    cin >> aux;
	    }
        char op;
        cout <<  " Total do Pedido: R$ " << aux * produtos[indice].valorUnit << endl;
	    cout << " Deseja Confirmar a Compra(S/N): ";
	    cin >> toupper(op);
        if (op = 'S') {
            system("cls");
            cout << "\t\t===== Produto Vendido ===== ";
            cout << "\n Venda Confirmada!";
		    produtos[indice].qtdEstoque -= aux;
            system("pause");
        } else {
            system("cls");
            cout << "\n Venda nao Confirmada!";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\t\t===== Codigo do produto invalido! ===== ";
        cout << "\n Venda Cancelada";
        system("pause");
    }

}