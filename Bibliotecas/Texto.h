#ifndef TEXTO_H
#define TEXTO_H

#include <iostream>
#include <string.h>
#include "D:\Semestre [3]\Estruturas de Dados\Bibliotecas\tabela_hash.h"
#include "D:\Semestre [3]\Estruturas de Dados\Bibliotecas\tabela_hash_encadeada.h"

using namespace std;

//CONTADOR DE PALAVRAS=========================================================================================================================================================
int ContarPalavras () {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");
    char frase[100];
    string palavra;
    int numeroPalavras = 0;
    while (fgets(frase, sizeof frase, arquivo) != NULL) {
        for(int i = 0; i < strlen(frase); i++){
            if ((frase[i] != ' ') && (frase[i] != '\n')) {
                if ((frase[i] != '.') && (frase[i] != ',')) {
                    palavra += frase[i];
                }
            } else {
                numeroPalavras++;
                palavra = "";
            }
        }
    }
    fclose(arquivo);
    return numeroPalavras + 1;
}

//INSERIR PALAVRAS NA TABELA ESTATICA=========================================================================================================================================================
template <int TAM>
void InserirTextoEstatico (THash<TAM> &Hash, int &colisoes) {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");
    char frase[100];
    string palavra;
    while (fgets(frase, sizeof frase, arquivo) != NULL) {
        for(int i = 0; i < strlen(frase); i++){
            if ((frase[i] != ' ') and (frase[i] != '\n')) {
                if ((frase[i] != '.') and (frase[i] != ',')) {
                    palavra += frase[i];
                }
            } else {
                InserirHash(Hash, palavra, colisoes);
                palavra = "";
            }
        }
    }
    InserirHash(Hash, palavra, colisoes);
    fclose(arquivo);
}

//INSERIR PALAVRAS NA TABELA ENCADEADA=========================================================================================================================================================
template <int TAM>
void InserirTextoEncadeado (THashE<TAM> &Hash, int &colisoes) {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");
    char frase[100];
    string palavra;
    while (fgets(frase, sizeof frase, arquivo) != NULL) {
        for(int i = 0; i < strlen(frase); i++){
            if ((frase[i] != ' ') and (frase[i] != '\n')) {
                if ((frase[i] != '.') and (frase[i] != ',')) {
                    palavra += frase[i];
                }
            } else {
                InserirHashE(Hash, palavra, colisoes);
                palavra = "";
            }
        }
    }
    InserirHashE(Hash, palavra, colisoes);
    fclose(arquivo);
}

#endif //TEXTO_H