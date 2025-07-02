#ifndef TP1_IMOVEL_H
#define TP1_IMOVEL_H

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Imovel { //classe criada para ser a classe base das classes apartamento, chacara e casa
    private: //atributos privados
        int id;
        float valor;
        string proprietario;
        string cidade;
        string bairro;
        string rua;
        int numero;
        int quartos;
        int banheiros;

    public: //metodos publicos
        Imovel(int id, float valor, string proprietario, string cidade, string bairro, string rua, int numero, int quartos, int banheiros);
        virtual ~Imovel() = default; //destrutor virtual
        int getId() const;
        float getValor() const;
        string getProprietario() const;
        string getCidade() const;
        string getBairro() const;
        string getRua() const;
        int getNumero() const;
        int getQuartos() const;
        int getBanheiros() const;
        void setId(int id);
        void setValor(float valor);
        void setProprietario(string proprietario);
        void setCidade(string cidade);
        void setBairro(string bairro);
        void setRua(string rua);
        void setNumero(int numero);
        void setQuartos(int quartos);
        void setBanheiros(int banheiros);
        friend std::ostream& operator<<(std::ostream& os, const Imovel& imovel); //sobrecarga do operador de inserção funçao amiga
        bool pertenceAoProprietario(const std::string& nomeProprietario) const; //verifica se o imovel pertence ao proprietario
        virtual std::string getType() const = 0; //retorna o tipo do imovel virtual
        
};


#endif //TP1_IMOVEL_H
