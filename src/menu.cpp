#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <memory>
#include <iomanip>
#include "../include/menu.h"
#include "../include/funcoes.h"

Menu::Menu(vector<Imovel*>& imoveis) : allImoveis(imoveis) {} //construtor

//exibe o menu
void Menu::exibirMenu() {  
    int opcao;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Exibir imóveis\n";
        cout << "2. Verificar propriedade do proprietário\n";
        cout << "3. Obter imóveis abaixo do valor\n";
        cout << "4. Obter imóveis com quartos\n";
        cout << "5. Obter imóveis por tipo ordenados por valor\n";
        cout << "6. Obter imóveis por cidade ordenados por valor\n";
        cout << "7. Buscar e exibir imóveis por proprietário\n";
        cout << "8. Exibir ou salvar imóveis\n";
        cout << "9. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                menuExibirImoveis();
                break;
            case 2:
                menuVerificarPropriedadeDoProprietario();
                break;
            case 3:
                menuObterImoveisAbaixoDoValor();
                break;
            case 4:
                menuObterImoveisComQuartos();
                break;
            case 5:
                menuObterImoveisPorTipoOrdenadosPorValor();
                break;
            case 6:
                menuObterImoveisPorCidadeOrdenadosPorValor();
                break;
            case 7:
                menuBuscarEExibirImoveisPorProprietario();
                break;
            case 8:
                menuExibirOuSalvarImoveis();
                break;
            case 9:
                cout << "Saindo do programa...\n";
                break;
            default:
                cerr << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 9);
}

//exibir imoveis cadastrados
void Menu::menuExibirImoveis() { 
    cout << "Imóveis cadastrados:\n";
    imprimirImoveis(allImoveis); //imprime os imoveis cadastrados através da funcao imprimirImoveis
}

//verificar se o proprietario possui imovel
void Menu::menuVerificarPropriedadeDoProprietario() { 
    string proprietario;
    cout << "Digite o nome do proprietário: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora o limite de caracteres
    getline(cin, proprietario);
    if (possuiImovelDoProprietario(allImoveis, proprietario)) {     //if pra saber se proprietario possuir imovel
        cout << "\nO proprietário " << proprietario << " possui imóvel.\n";
    } else {
        cout << "\nO proprietário " << proprietario << " não possui imóvel.\n";
    }

}

//obter imoveis abaixo do valor digitado
void Menu::menuObterImoveisAbaixoDoValor() { 
    float valorLimite;
    cout << "Digite o valor limite: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> valorLimite;
    vector<Imovel*> imoveisAbaixoDoLimite = obterImoveisAbaixoDoValor(allImoveis, valorLimite);  //vetor de imoveis abaixo do valor recebido da funcao obterImoveisAbaixoDoValor

    //Exibindo os imóveis abaixo do valor no main
    cout << "\nImóveis abaixo do valor de " << valorLimite << ":\n";
    imprimirImoveis(imoveisAbaixoDoLimite); //imprime os imoveis abaixo do valor através da funcao imprimirImoveis
}

//obter imoveis com quartos
void Menu::menuObterImoveisComQuartos() { 
    int quartosEspecificado;
    cout << "Digite o número de quartos: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> quartosEspecificado;
    vector<Imovel*> imoveisComQuartos = obterImoveisComQuartos(allImoveis, quartosEspecificado);

    //Exibindo os imóveis com quartos igual ou acima do especificado no main
    cout << "\nImóveis com " << quartosEspecificado << " quartos ou mais:\n";
    imprimirImoveis(imoveisComQuartos);
}

//obter imoveis por tipo ordenados por valor
void Menu::menuObterImoveisPorTipoOrdenadosPorValor() { 
    string tipoEspecificado;
    cout << "Digite o tipo de imóvel: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> tipoEspecificado;
    if (!tipoEspecificado.empty()) {
        
        tipoEspecificado[0] = toupper(tipoEspecificado[0]);//Torne a primeira letra maiúscula
    }
    vector<Imovel*> imoveisDoTipo = obterImoveisPorTipoOrdenadosPorValor(allImoveis, tipoEspecificado); //vetor de imoveis do tipo recebido da funcao obterImoveisPorTipoOrdenadosPorValor

    
    cout << "\nImóveis do tipo " << tipoEspecificado << " ordenados por valor:\n";
    imprimirImoveis(imoveisDoTipo); //imprime os imoveis do tipo através da funcao imprimirImoveis

}

//obter imoveis por cidade ordenados por valor
void Menu::menuObterImoveisPorCidadeOrdenadosPorValor() {   
   string cidadeEspecificada;
    cout << "Digite o nome da cidade: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> cidadeEspecificada;

    vector<Imovel*> imoveisNaCidade = obterImoveisPorCidadeOrdenadosPorValor(allImoveis, cidadeEspecificada); //vetor de imoveis na cidade recebido da funcao obterImoveisPorCidadeOrdenadosPorValor

    //Exibindo os imóveis na cidade, ordenados por valor, no main
    cout << "\nImóveis em " << cidadeEspecificada << " ordenados por valor:\n";
    imprimirImoveis(imoveisNaCidade); //imprime os imoveis na cidade através da funcao imprimirImoveis
}

//buscar e exibir imoveis por proprietario separados por tipo
void Menu::menuBuscarEExibirImoveisPorProprietario() {
    string proprietarioEspecificado;
    cout << "Digite o nome completo do proprietário: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, proprietarioEspecificado);
    buscarEExibirImoveisPorProprietario(allImoveis, proprietarioEspecificado); //funcao buscarEExibirImoveisPorProprietario
}

//exibir ou salvar imoveis
void Menu::menuExibirOuSalvarImoveis() {
    string opcao;
    cout << "Deseja exibir os imóveis na tela ou salvar em um arquivo? (exibir/salvar): ";
    cin >> opcao;
    if (opcao == "exibir") {
         exibirOuSalvarImoveis(allImoveis, "terminal", ""); //funcao exibirOuSalvarImoveis passando a opçao terminal para imprimir na tela
    } else if (opcao == "salvar") {
        string nomeArquivo = "saida.txt";
        exibirOuSalvarImoveis(allImoveis, "arquivo", nomeArquivo); //funcao exibirOuSalvarImoveis passando a opçao arquivo para salvar em um arquivo
    } else {
        cerr << "Opção inválida.\n";
    }
}