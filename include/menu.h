#ifndef MENU_H
#define MENU_H

#include <vector>
#include "imovel.h"
#include "apartamento.h"
#include "casa.h"
#include "chacara.h"

class Menu { //classe menu

private: //funcoes privados

    vector<Imovel*>& allImoveis;
    void menuExibirImoveis();
    void menuVerificarPropriedadeDoProprietario();
    void menuObterImoveisAbaixoDoValor();
    void menuObterImoveisComQuartos();
    void menuObterImoveisPorTipoOrdenadosPorValor();
    void menuObterImoveisPorCidadeOrdenadosPorValor();
    void menuBuscarEExibirImoveisPorProprietario();
    void menuExibirOuSalvarImoveis();

public: //funcoes publicos

    Menu(vector<Imovel*>& imoveis); //construtor da classe
    void exibirMenu(); //exibe o menu principal do programa 


};

#endif // MENU_H
