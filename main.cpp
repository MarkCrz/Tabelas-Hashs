#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "D:\Semestre [3]\Estruturas de Dados\Bibliotecas\tabela_hash.h"
#include "D:\Semestre [3]\Estruturas de Dados\Bibliotecas\tabela_hash_encadeada.h"
#include "Bibliotecas/Texto.h"

using namespace std;

int main () {
    THash<204> HashEstatica;
    THashE<204> HashEncadeada;
    int colisoesEstatica = 0;
    int colisoesEncadeada = 0;
    int quantidadeEstatica = 0;
    int quantidadeEncadeada = 0;

    try {
        InicializaTabelaE(HashEncadeada);
        InicializaTabela(HashEstatica);
        InserirTextoEstatico(HashEstatica, colisoesEstatica);
        InserirTextoEncadeado(HashEncadeada, colisoesEncadeada);
        ImprimeTabela(HashEstatica);
        ImprimirTabelaE(HashEncadeada);
        ContarAlocadosTabela(HashEstatica, quantidadeEstatica);
        ContarAlocadosTabelaE(HashEncadeada, quantidadeEncadeada);

        cout << endl << "Colisoes Estatica: " << colisoesEstatica << endl;
        cout << "Quantidade de ocupacao: " << quantidadeEstatica << endl;
        cout << "Percentual de ocupacao estatica: " << double (((quantidadeEstatica * 100) / 204)) << "%" << endl;
        cout << endl << "Colisoes Encadeada: " << colisoesEncadeada << endl;
        cout << "Quantidade de ocupacao: " << quantidadeEncadeada << endl;
        cout << "Percentual de ocupacao estatica: " << double (((quantidadeEncadeada * 100) / 204)) << "%" << endl;
        cout << "Numero de palavras: " << ContarPalavras() << endl;
        

    } catch(const char *erro) {
        cout << "DEU ERRO: " << erro << endl;
    }
    

    return 0;
}