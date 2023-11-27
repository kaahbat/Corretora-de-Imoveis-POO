#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "imovel.h"



class Apartamento : public Imovel { //Apartamento herda de Imovel
private: //atributos privados
    int andar;
    float taxa_condominio;
    bool elevador;
    bool sacada;

public:  //metodos publicos
    Apartamento(int id, float valor, string proprietario, string cidade, string bairro,
                string rua, int numero, int quartos, int banheiros, int andar, float taxa_condominio,
                bool elevador, bool sacada);

    int getAndar() const; 
    void setAndar(int andar);

    float getTaxaCondominio() const;
    void setTaxaCondominio(float taxa_condominio);

    bool temElevador() const;
    void setElevador(bool elevador);

    bool temSacada() const;
    void setSacada(bool sacada);
    friend ostream& operator<<(ostream& os, const Apartamento& apartamento); //sobrecarga do operador de inserção funçao amiga
    string getType() const override; //retorna o tipo do imovel 
};
#endif //APARTAMENTO_H
