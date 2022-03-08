#ifndef TABELA_HASH
#define TABELA_HASH

#include <iostream>

using namespace std;

struct TCedula {
    bool  valido;
    string palavra;
    int quantidade;
};

template <int TAM>
struct THash {
    TCedula* tabela[TAM];
};

//INICIALIZAÇÃO DA TABELA=========================================================================================================================================================
template <int TAM>
void InicializaTabela(THash<TAM> &Hash) {
    TCedula* novo = new TCedula;
    novo->palavra = " ";
    novo->valido = true;
    novo->quantidade = 0;
    for(int i = 0; i < TAM; i++) {
        Hash.tabela[i] = novo;
    } 
}

//INICIALIZAÇÃO DA TABELA=========================================================================================================================================================
TCedula* CriarCedula (string palavra) {
    TCedula* novo = new TCedula;
    novo->palavra = palavra;
    novo->valido = false;
    novo->quantidade = 1;

    return novo;
}

//FUNÇÃO HASH=========================================================================================================================================================
template <int TAM>
int FuncaoHash (THash<TAM> &Hash, string chave) {
    int soma = 0;
    for(int i = 0; i < chave.length(); i++) {
        soma = soma + (((unsigned char)chave[i]));
    }
    return soma % TAM;
}

// template <int TAM>
// int FuncaoHash (THash<TAM> &Hash, string chave) {
//     int soma = 0;
//     for(int i = 0; i < chave.length(); i++) {
//         soma = soma + (((unsigned char)chave[i]) * i);
//     }
//     return soma % TAM;
// }

//INSERIR NA TABELA=========================================================================================================================================================
template <int TAM>
void InserirHash (THash<TAM> &Hash, string palavra, int &colisoes) {
    bool inserido = false;
    TCedula* novo = CriarCedula(palavra);
    int chave = FuncaoHash(Hash, novo->palavra);
    while (inserido != true) {
        for (int i = 0; i < TAM; i++) {
            if(Hash.tabela[i]->palavra == palavra) {
                Hash.tabela[i]->quantidade++;
                inserido = true;
            }
        }
        if (inserido != true) {
            if (Hash.tabela[chave]->valido == true) {
                Hash.tabela[chave] = novo;
                inserido = true;
            } else {
                chave++;
                colisoes++;
                if (chave >= TAM) {
                    chave = 0;
                }
                if (chave == chave - 1) {
                    throw "Stack Overflow!";
                }
            }
        }
    }
}

//REMOVER DA TABELA=========================================================================================================================================================
template <int TAM>
string RemoverHash (THash<TAM> &Hash, int chave) {
    if ((chave >= TAM) || (chave < 0)) {
        throw "A chave e' maior ou menor que a tabela!";
    } if(Hash.tabela[chave]->valido == true) {
        throw "Stack Underflow!";
    } else {
        string excluir = Hash.tabela[chave]->palavra;
        if(Hash.tabela[chave]->quantidade > 1) {
            Hash.tabela[chave]->quantidade--;
        } else {
            Hash.tabela[chave]->palavra = " ";
            Hash.tabela[chave]->quantidade = 0;
            Hash.tabela[chave]->valido = true;
        }

        return excluir;
    }
}

//PERTENCE NA TABELA=========================================================================================================================================================
template <int TAM>
bool PertenceHash (THash<TAM> Hash, string palavra) {
    for (int i = 0; i < TAM; i++) {
        if (Hash.tabela[i]->palavra == palavra) {
            return true;
        }
    }
    return false;
}

//BUSCA INDICE NA TABELA=========================================================================================================================================================
template <int TAM>
int BuscarIndiceHash(THash<TAM> Hash, string chave) {
    int indice = FuncaoHash(Hash, chave);
    while (Hash.tabela[indice]->valido != true) {
        if(Hash.tabela[indice]->palavra == chave) {
            return indice;
        } else {
            indice++;
            if (indice >= TAM) {
                indice = 0;
            }
        }
    }
    throw "A palavra nao pertence a tabela!";
}

//BUSCA PALAVRA NA TABELA=========================================================================================================================================================
template <int TAM>
string BuscarDadoHash(THash<TAM> Hash, int chave) {
    while (Hash.tabela[chave]->valido != true) {
        if(Hash.tabela[chave]->valido == false) {
            return Hash.tabela[chave]->palavra;
        } else {
            chave++;
            if (chave >= TAM) {
                chave = 0;
            }
        }
    }
    throw "O indice esta vazio!";
}

//CONTADOR DE ALOCADOS=========================================================================================================================================================
template <int TAM>
void ContarAlocadosTabela(THash<TAM> Hash, int &quantidade) {
    for(int i = 0; i < TAM; i++) {
        if (Hash.tabela[i]->valido == false) {
            quantidade++;
        }
    }
}

//IMPRESSÃO DA TABELA=========================================================================================================================================================
template <int TAM>
void ImprimeTabela(THash<TAM> Hash) {
    cout << "IMPRESSAO DA TABELA" << endl;
    for(int i = 0; i < TAM; i++) {
        cout << "Indice: " << i << endl
             << "Dado: " << Hash.tabela[i]->palavra << endl
             << "Quantidade: " << Hash.tabela[i]->quantidade << endl
             << "Valido: " << Hash.tabela[i]->valido << endl << endl;
    }
}
#endif //TABELA_HASH