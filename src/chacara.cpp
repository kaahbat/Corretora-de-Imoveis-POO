#include "../include/chacara.h"

//Construtor da classe Chacara que herda de Imovel
Chacara::Chacara(int id, float valor, string proprietario, string cidade, string bairro, string rua, int numero, int quartos, int banheiros,
    bool salaDeFestas, bool salaDeJogos, bool campoDeFutebol, bool churrasqueira, bool piscina)
    : Imovel(id, valor, proprietario, cidade, bairro, rua, numero, quartos, banheiros),
      salaDeFestas(salaDeFestas),
      salaDeJogos(salaDeJogos),
      campoDeFutebol(campoDeFutebol),
      churrasqueira(churrasqueira),
      piscina(piscina) {}

//getters
bool Chacara::getSalaDeFestas() const {
    return salaDeFestas;
}

bool Chacara::getSalaDeJogos() const {
    return salaDeJogos;
}

bool Chacara::getCampoDeFutebol() const {
    return campoDeFutebol;
}

bool Chacara::getChurrasqueira() const {
    return churrasqueira;
}

bool Chacara::getPiscina() const {
    return piscina;
}
//setters
void Chacara::setSalaDeFestas(bool value) {
    salaDeFestas = value;
}

void Chacara::setSalaDeJogos(bool value) {
    salaDeJogos = value;
}

void Chacara::setCampoDeFutebol(bool value) {
    campoDeFutebol = value;
}

void Chacara::setChurrasqueira(bool value) {
    churrasqueira = value;
}

void Chacara::setPiscina(bool value) {
    piscina = value;
}

//Sobrecarga do operador de inserção para impressão dos dados da Chacara 
ostream& operator<<(ostream& os, const Chacara& chacara) {
    os << static_cast<const Imovel&>(chacara) //imprime os dados do imovel
       << "    Sala de Festas: " << (chacara.getSalaDeFestas() ? "Sim" : "Não") << "\n"
       << "    Sala de Jogos: " << (chacara.getSalaDeJogos() ? "Sim" : "Não") << "\n"
       << "    Campo de Futebol: " << (chacara.getCampoDeFutebol() ? "Sim" : "Não") << "\n"
       << "    Churrasqueira: " << (chacara.getChurrasqueira() ? "Sim" : "Não") << "\n"
       << "    Piscina: " << (chacara.getPiscina() ? "Sim" : "Não") << "\n"
       << "------------------------------------\n";
    return os;
}

//Retorna o tipo do imovel
string Chacara::getType() const {
    return "Chacara";
}