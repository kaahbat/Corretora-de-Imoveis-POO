#include <iostream>
#include <fstream>
#include <vector>
#include "../include/imovel.h"
#include "../include/menu.h"
#include "../include/funcoes.h"

int main() {
    ifstream arquivo("database_imoveis.txt"); //abre o arquivo
    vector<Imovel*> imoveis; //vetor de imoveis

    if (!arquivo.is_open()) { //verifica se o arquivo foi aberto
        cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    lerImoveis(arquivo, imoveis); //le os imoveis do arquivo e armazena no vetor

    Menu menu(imoveis); //cria um objeto menu
    menu.exibirMenu(); //exibe o menu

    for (auto imovel : imoveis) { //deleta os imoveis do vetor
        delete imovel;
    }

    return 0;
}
