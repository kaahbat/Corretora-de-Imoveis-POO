#ifndef TP1_CASA_H
#define TP1_CASA_H
#include "imovel.h"

class Casa : public Imovel { //Casa herda de Imovel

private: //atributos privados
    int andares;
    bool sala_jantar;
public: //metodos publicos
    Casa(int id, float valor, string proprietario, string cidade, string bairro, string rua, int numero, int quartos, int banheiros,
    int andares, bool sala_jantar);
    int getAndares() const;
    bool getSala_jantar() const;
    void setAndares(int andares);
    void setSala_jantar(bool sala_jantar);
    friend ostream& operator<<(ostream& os, const Casa& casa); //sobrecarga do operador de inserção funçao amiga
    string getType() const override; //retorna o tipo do imovel
};



#endif //TP1_CASA_H
