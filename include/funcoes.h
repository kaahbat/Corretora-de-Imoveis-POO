//funcoes auxiliares para o programa

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <map>
#include "imovel.h"
#include "apartamento.h"
#include "casa.h"
#include "chacara.h"

using namespace std;

bool stringToBool(const string& str); //converte uma string para bool

void lerApartamento(istringstream& iss, int id, vector<Imovel*>& imoveis); //le um apartamento do arquivo

void lerCasa(istringstream& iss, int id, vector<Imovel*>& imoveis) ; //le uma casa do arquivo

void lerChacara(istringstream& iss, int id, vector<Imovel*>& imoveis);   //le uma chacara do arquivo

void lerImoveis(ifstream& arquivo, vector<Imovel*>& imoveis); //le os imoveis do arquivo e armazena no vetor

void exibirImoveis(const vector<Imovel*>& imoveis); //exibe os imoveis no menu
 
bool possuiImovelDoProprietario(const vector<Imovel*>& imoveis, const string& proprietario) ; //verifica se o proprietario possui imovel

vector<Imovel*> obterImoveisAbaixoDoValor(const vector<Imovel*>& imoveis, float valorLimite); //obtem os imoveis abaixo do valor

vector<Imovel*> obterImoveisComQuartos(const vector<Imovel*>& imoveis, int quartosEspecificado) ; //obtem os imoveis com quartos

bool compararPorValor(const Imovel* a, const Imovel* b) ; //compara os imoveis por valor

vector<Imovel*> obterImoveisPorTipoOrdenadosPorValor(const vector<Imovel*>& imoveis, const string& tipoEspecificado); //obtem os imoveis por tipo ordenados por valor

vector<Imovel*> obterImoveisPorCidadeOrdenadosPorValor(const vector<Imovel*>& imoveis, const string& cidade); //obtem os imoveis por cidade ordenados por valor

bool temProprietario(const Imovel* imovel, const string& proprietario); //verifica se o imovel tem o proprietario
 
void imprimirImoveis(const vector<Imovel*>& imoveis) ; //imprime os imoveis no tela 

map<string, vector<vector<Imovel*>::iterator>> buscarImoveisPorProprietarioEType(vector<Imovel*> &imoveis,const string proprietario); //busca os imoveis por proprietario e tipo

void buscarEExibirImoveisPorProprietario( vector<Imovel*>& imoveis, const string& proprietario); //busca e exibe os imoveis por proprietario 

void exibirOuSalvarImoveis(const vector<Imovel*>& imoveis, const string& tipoSaida, const string& nomeArquivo); //exibe ou salva os imoveis no arquivo de saida 


