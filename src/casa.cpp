#include "../include/casa.h"

//Construtor da classe Casa que herda de Imovel
Casa::Casa(int id, float valor, string proprietario, string cidade, string bairro, string rua, int numero, int quartos,
    int banheiros, int andares, bool sala_jantar)
    : Imovel(id, valor, proprietario, cidade, bairro, rua, numero, quartos, banheiros),
      andares(andares),
      sala_jantar(sala_jantar){}

//getters
int Casa::getAndares() const
{
    return 0;
}

bool Casa::getSala_jantar() const {
    return sala_jantar;
}
//setters
void Casa::setAndares(int andares) {
    this->andares = andares;
}

void Casa::setSala_jantar(bool sala_jantar) {
    this->sala_jantar = sala_jantar;
}

//Sobrecarga do operador de inserção para impressão dos dados da Casa
ostream& operator<<(ostream& os, const Casa& casa) {
    os << static_cast<const Imovel&>(casa)
       << "    Andares: " << casa.getAndares() << "\n"
       << "    Sala de Jantar: " << (casa.getSala_jantar() ? "Sim" : "Não") << "\n"
       << "------------------------------------\n";
    return os;
}

//retorna o tipo do imovel
string Casa::getType() const {
    return "Casa";
}