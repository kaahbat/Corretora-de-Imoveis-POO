#include "../include/imovel.h"

//Construtor da classe Imovel
Imovel::Imovel(int id, float valor, string proprietario, string cidade, string bairro, string rua, int numero, int quartos, int banheiros) 
{
    this->id = id;
    this->valor = valor;
    this->proprietario = proprietario;
    this->cidade = cidade;
    this->bairro = bairro;
    this->rua = rua;
    this->numero = numero;
    this->quartos = quartos;
    this->banheiros = banheiros;
}

//getters
int Imovel::getId() const
{
    return id;
}

float Imovel::getValor() const
{
    return valor;
}

string Imovel::getProprietario() const
{
    return proprietario;
}

string Imovel::getCidade() const
{
    return cidade;
}

string Imovel::getBairro() const
{
    return bairro;
}

string Imovel::getRua() const
{
    return rua;
}

int Imovel::getNumero() const
{
    return numero;
}

int Imovel::getQuartos() const
{
    return quartos;
}

int Imovel::getBanheiros() const
{
    return banheiros;
}

//setters
void Imovel::setId(int id)
{
    this->id = id;
}

void Imovel::setValor(float valor)
{
    this->valor = valor;
}

void Imovel::setProprietario(string proprietario)
{
    this->proprietario = proprietario;
}

void Imovel::setCidade(string cidade)
{
    this->cidade = cidade;
}

void Imovel::setBairro(string bairro)
{
    this->bairro = bairro;  
}

void Imovel::setRua(string rua)
{
    this->rua = rua;
}

void Imovel::setNumero(int numero)
{
    this->numero = numero;
}

void Imovel::setQuartos(int quartos)
{
    this->quartos = quartos;
}

void Imovel::setBanheiros(int banheiros)
{
    this->banheiros = banheiros;
}


//sobrecarga do operador << para imprimir um imovel
ostream& operator<<(ostream& os, const Imovel& imovel) { 
    os <<"------------------------------------\n"
       << "Proprietario: " << imovel.getProprietario() << "\n"
       << "    Preco: R$ " << fixed << setprecision(2) << imovel.getValor() << "\n"
       << "    Numero de Quartos: " << imovel.getQuartos() << "\n"
       << "    Rua: " << imovel.getRua() << "\n"
       << "    Bairro: " << imovel.getBairro() << "\n"
       << "    Cidade: " << imovel.getCidade() << "\n";
    return os;
}

//verifica se o imovel pertence ao proprietario
bool Imovel::pertenceAoProprietario(const string& nomeProprietario) const { 
    return proprietario == nomeProprietario;
}

