#ifndef TABELA_HASH_ENCADEADA
#define TABELA_HASH_ENCADEADA

#include <iostream>

using namespace std;

struct TCedulaE {
    string palavra;
    int quantidade;
    TCedulaE* proximo;
};

template <int TAM>
struct THashE {
    TCedulaE* tabela[TAM];
};

//INICIALIZAÇÃO DA TABELA=========================================================================================================================================================
template <int TAM>
void InicializaTabelaE(THashE<TAM> &Hash) {
    for(int i = 0; i < TAM; i++) {
        Hash.tabela[i] = NULL;
    } 
}

//INICIALIZAÇÃO DA TABELA=========================================================================================================================================================
TCedulaE* CriarCedulaE (string palavra) {
    TCedulaE* novo = new TCedulaE;
    novo->palavra = palavra;
    novo->quantidade = 1;
    novo->proximo = NULL;

    return novo;
}

//FUNÇÃO HASH=========================================================================================================================================================
template <int TAM> // COLOCAR TODAS AS FUNÇÕES TESTADAS
int FuncaoHashE (THashE<TAM> &Hash, string chave) {
    int soma = 0;
    for(int i = 0; i < chave.length(); i++) {
        soma = soma + (((unsigned char)chave[i]));
    }
    return soma % TAM;
}

// template <int TAM> // COLOCAR TODAS AS FUNÇÕES TESTADAS
// int FuncaoHashE (THashE<TAM> &Hash, string chave) {
//     int soma = 0;
//     for(int i = 0; i < chave.length(); i++) {
//         soma = soma + (((unsigned char)chave[i]) * i);
//     }
//     return soma % TAM;
// }

//INSERIR NA TABELA=========================================================================================================================================================
template <int TAM>
void InserirHashE (THashE<TAM> &Hash, string palavra, int &colisoes) {
    bool inserido = false;
    TCedulaE* novo = CriarCedulaE(palavra);
    int chave = FuncaoHashE(Hash, novo->palavra);
    while (inserido != true) {
        if (Hash.tabela[chave] == NULL) {
            Hash.tabela[chave] = novo;
            inserido = true;
        } else {
            for (TCedulaE* nav = Hash.tabela[chave]; nav != NULL; nav = nav->proximo) {
                if (nav->palavra == novo->palavra) {
                    nav->quantidade++;
                    inserido = true;
                }
            }
            if (inserido != true) {
                TCedulaE* nav = Hash.tabela[chave];
                TCedulaE* navAnt = Hash.tabela[chave];
                while (nav != NULL) {
                    navAnt = nav;
                    nav = nav->proximo;
                    colisoes++;
                }
                if (nav == NULL) {
                    nav = novo;
                    navAnt->proximo = nav;
                    inserido = true;
                }
            }
        }
    }
}

//REMOVER DA TABELA=========================================================================================================================================================
template <int TAM>
TCedulaE* RemoverHashE (THashE<TAM> &Hash, string chave) {
    int i = FuncaoHashE(Hash, chave);
    bool posicao = false;
    if ((i >= TAM) || (i < 0)) {
        throw "A chave e' maior ou menor que a tabela!";
    } if (Hash.tabela[i] == NULL) {
        throw "Stack Underflow!";
    } if (PertenceHashE(Hash, chave) == false) {
        throw "Palavra nao pertence a lista!";
    } else {
        TCedulaE* excluir = Hash.tabela[i];
        if (excluir->palavra == chave) {
            if (excluir->quantidade > 1) {
                excluir->quantidade--;
            } else {
                Hash.tabela[i] = excluir->proximo;
            }
        } else {
            TCedulaE* navAnt;
            while (posicao != true) {
                if (excluir->palavra == chave) {
                    posicao = true;
                } else {
                    navAnt = excluir;
                    excluir = excluir->proximo;
                }
            }
            if (excluir->quantidade > 1) {
                excluir->quantidade--;
            } else {
                navAnt->proximo = excluir->proximo;
                excluir->proximo = NULL;
            }
        }
        return excluir;
    }
}

//PERTENCE A TABALA=========================================================================================================================================================
template <int TAM>
bool PertenceHashE (THashE<TAM> Hash, string palavra) {
    for (int i = 0; i < TAM; i++) {
        if (Hash.tabela[i] != NULL) {
            for (TCedulaE* nav = Hash.tabela[i]; nav != NULL; nav = nav->proximo) {
                if (nav->palavra == palavra) {
                    return true;
                }
            }
        }
    }
    return false;
}

//BUSCA INDICE NA TABELA=========================================================================================================================================================
template <int TAM>
int BuscarIndiceHashE(THashE<TAM> Hash, string chave) {
    int i = FuncaoHashE(Hash, chave);
    return i;
}

//BUSCA PALAVRA NA TABELA=========================================================================================================================================================
template <int TAM>
TCedulaE* BuscarDadoHashE(THashE<TAM> Hash, int chave) {
    return Hash.tabela[chave];
}
//CONTADOR DE ALOCADOS=========================================================================================================================================================
template <int TAM>
void ContarAlocadosTabelaE (THashE<TAM> Hash, int &quantidade) {
    for (int i = 0; i < TAM; i++) {
        if (Hash.tabela[i] != NULL) {
            for (TCedulaE* nav = Hash.tabela[i]; nav != NULL; nav = nav->proximo) {
                quantidade++;
            }
        }
    }
}

//IMPRIMIR TABELA=========================================================================================================================================================
template <int TAM>
void ImprimirTabelaE (THashE<TAM> Hash) {
    cout << "IMPRESSAO DA TABELA ENCADEADA" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "-------Indice: " << i << "-------" << endl;
        if (Hash.tabela[i] != NULL) {
            for (TCedulaE* nav = Hash.tabela[i]; nav != NULL; nav = nav->proximo) {
                cout << "Dado: " << nav->palavra << endl
                     << "Quantidade: " << nav->quantidade << endl
                     << "Endereco: " << nav << endl
                     << "Proximo: " << nav->proximo << endl << endl;
            }
        } else {
            cout << "Vazia" << endl << endl;
        }
    }
}

#endif //TABELA_HASH_ENCADEADA