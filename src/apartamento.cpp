#include "apartamento.h"

//Construtor da classe Apartamento que herda de Imovel
Apartamento::Apartamento(int id, float valor, string proprietario, string cidade, string bairro,
    string rua, int numero, int quartos, int banheiros, int andar, float taxa_condominio, bool elevador, bool sacada)
    : Imovel(id, valor, proprietario, cidade, bairro, rua, numero, quartos, banheiros),
      andar(andar),
      taxa_condominio(taxa_condominio),
      elevador(elevador),
      sacada(sacada) {}


//getters
int Apartamento::getAndar() const {
    return andar;
}
bool Apartamento::temSacada() const {
    return sacada;
}
bool Apartamento::temElevador() const {
    return elevador;
}
float Apartamento::getTaxaCondominio() const {
    return taxa_condominio;
}
//setters
void Apartamento::setAndar(int andar) {
    this->andar = andar;
}
void Apartamento::setTaxaCondominio(float taxa_condominio) {
    this->taxa_condominio = taxa_condominio;
}
void Apartamento::setElevador(bool elevador) {
    this->elevador = elevador;
}
void Apartamento::setSacada(bool sacada) {
    this->sacada = sacada;
}

//Sobrecarga do operador de inserção para impressão dos dados do Apartamento
ostream& operator<<(ostream& os, const Apartamento& apartamento) {
    os << static_cast<const Imovel&>(apartamento)
       << "    Andar: " << apartamento.getAndar() << "\n"
       << "    Taxa de Condominio: " << apartamento.getTaxaCondominio() << "\n"
       << "    Elevador: " << (apartamento.temElevador() ? "Sim" : "Não") << "\n"
       << "------------------------------------\n";
       
    return os;
}

//retorna o tipo do imovel
string Apartamento::getType() const {
    return "Apartamento";
}