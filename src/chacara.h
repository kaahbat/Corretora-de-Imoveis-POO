
#ifndef TP1_CHACARA_H
#define TP1_CHACARA_H

#include "imovel.h"

class Chacara : public Imovel { //Chacara herda de Imovel

private: //atributos privados
    bool salaDeFestas;
    bool salaDeJogos;
    bool campoDeFutebol;
    bool churrasqueira;
    bool piscina;

public: //metodos publicos
    Chacara(int id, float valor, string proprietario, string cidade, string bairro, string rua, int numero, int quartos, int banheiros,
            bool salaDeFestas, bool salaDeJogos, bool campoDeFutebol, bool churrasqueira, bool piscina);
    //getters
    bool getSalaDeFestas() const;
    bool getSalaDeJogos() const; 
    bool getCampoDeFutebol() const;
    bool getChurrasqueira() const; 
    bool getPiscina() const; 

    //setters
    void setSalaDeFestas(bool value);
    void setSalaDeJogos(bool value);
    void setCampoDeFutebol(bool value);
    void setChurrasqueira(bool value); 
    void setPiscina(bool value);
    friend ostream& operator<<(ostream& os, const Chacara& chacara); //sobrecarga do operador de inserção funçao amiga
    string getType() const override; //retorna o tipo do imovel
    
};

#endif //TP1_CHACARA_H
