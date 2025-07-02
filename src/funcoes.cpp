#include "../include/funcoes.h"



//Função para converter uma string para bool 
bool stringToBool(const string& str) { 
    if (str == "1") {
        return true;
    } else if (str == "0") {
        return false;
    } else {
        cerr << "Erro ao converter string para bool: " << str << "\n";
        return false;
    }
}

//Função para ler um apartamento do arquivo e armazenar no vetor de imóveis 
void lerApartamento(istringstream& iss, int id, vector<Imovel*>& imoveis) { 
    float valor;
    string proprietario, cidade, bairro, rua;
    int numero, quartos, banheiros, andar;
    float taxa_condominio;
    bool elevador, sacada;
    string valor_str, numero_str, quartos_str, banheiros_str, andar_str, taxa_condominio_str, elevador_str, sacada_str; //Variáveis auxiliares para ler os dados do arquivo de entrada 
    //Lendo os dados do apartamento
    getline(iss, valor_str, ';');
    valor = stof(valor_str);

    getline(iss, proprietario, ';');
    getline(iss, rua, ';');
    getline(iss, bairro, ';');
    getline(iss, cidade, ';');

    getline(iss, numero_str, ';');
    numero = stoi(numero_str);

    getline(iss, quartos_str, ';');
    quartos = stoi(quartos_str);

    getline(iss, banheiros_str, ';');
    banheiros = stoi(banheiros_str);

    getline(iss, andar_str, ';');
    andar = stoi(andar_str);

    getline(iss, taxa_condominio_str, ';');
    taxa_condominio = stof(taxa_condominio_str);

    getline(iss, elevador_str, ';');
    elevador = stringToBool(elevador_str);

    getline(iss, sacada_str, ';');
    sacada = stringToBool(sacada_str);

    Apartamento *novoApartamento = new Apartamento(id, valor, proprietario, cidade, bairro, rua, numero, quartos, banheiros, andar, taxa_condominio, elevador, sacada); //Criando um novo apartamento 
    imoveis.push_back(novoApartamento); //Adicionando o apartamento no vetor de imóveis
}

//Função para ler uma casa do arquivo e armazenar no vetor de imóveis
void lerCasa(istringstream& iss, int id, vector<Imovel*>& imoveis) {
    float valor;
    string proprietario, cidade, bairro, rua;
    int numero, quartos, banheiros, andares;
    bool sala_jantar;
    string valor_str, numero_str, quartos_str, banheiros_str, andares_str, sala_jantar_str; //Variáveis auxiliares para ler os dados do arquivo de entrada

    getline(iss, valor_str, ';');
    valor = stof(valor_str);

    getline(iss, proprietario, ';');
    getline(iss, rua, ';');
    getline(iss, bairro, ';');
    getline(iss, cidade, ';');

    getline(iss, numero_str, ';');
    numero = stoi(numero_str);

    getline(iss, quartos_str, ';');
    quartos = stoi(quartos_str);

    getline(iss, banheiros_str, ';');
    banheiros = stoi(banheiros_str);

    getline(iss, andares_str, ';');
    andares = stoi(andares_str);

    getline(iss, sala_jantar_str, ';');
    sala_jantar = stringToBool(sala_jantar_str);

    Casa *novaCasa = new Casa(id, valor, proprietario, cidade, bairro, rua, numero, quartos, banheiros, andares, sala_jantar);  //Criando uma nova casa
    imoveis.push_back(novaCasa); //Adicionando a casa no vetor de imóveis
}

//Função para ler uma chacara do arquivo e armazenar no vetor de imóveis
void lerChacara(istringstream& iss, int id, vector<Imovel*>& imoveis) {
    float valor;
    string proprietario, cidade, bairro, rua;
    int numero, quartos, banheiros;
    bool salao_festas, salao_jogos, campo_futebol, churrasqueira, piscina;
    string valor_str, numero_str, quartos_str, banheiros_str, salao_festas_str, salao_jogos_str, campo_futebol_str, churrasqueira_str, piscina_str; //Variáveis auxiliares para ler os dados do arquivo de entrada
    
    getline(iss, valor_str, ';');
    valor = stof(valor_str);

    getline(iss, proprietario, ';');
    getline(iss, rua, ';');
    getline(iss, bairro, ';');
    getline(iss, cidade, ';');

    getline(iss, numero_str, ';');
    numero = stoi(numero_str);
    getline(iss, quartos_str, ';');
    quartos = stoi(quartos_str);
    getline(iss, banheiros_str, ';');
    banheiros = stoi(banheiros_str);
    getline(iss, salao_festas_str, ';');
    salao_festas = stringToBool(salao_festas_str);
    getline(iss, salao_jogos_str, ';');
    salao_jogos = stringToBool(salao_jogos_str);
    getline(iss, campo_futebol_str, ';');
    campo_futebol = stringToBool(campo_futebol_str);
    getline(iss, churrasqueira_str, ';');
    churrasqueira = stringToBool(churrasqueira_str);
    getline(iss, piscina_str, ';');
    piscina = stringToBool(piscina_str); 
    Chacara *novaChacara = new Chacara(id, valor, proprietario, cidade, bairro, rua, numero, quartos, banheiros, salao_festas, salao_jogos, campo_futebol, churrasqueira, piscina); //Criando uma nova chacara
    imoveis.push_back(novaChacara); //Adicionando a chacara no vetor de imóveis
}

//Função para ler os imóveis do arquivo e armazenar no vetor de imóveis
void lerImoveis(ifstream& arquivo, vector<Imovel*>& imoveis) {
    int id = 1; //Inicializando o ID
    string linha;
    while (getline(arquivo, linha)) { //Lê uma linha do arquivo de entrada 
        istringstream iss(linha); //Cria um stream para ler a linha
        string tipo; 
        getline(iss, tipo, ';'); //Lê o tipo de imóvel
        if (tipo == "apartamento") { //Verifica se o imóvel é um apartamento
            lerApartamento(iss, id, imoveis);
        } else if (tipo == "casa") { //Verifica se o imóvel é uma casa
            lerCasa(iss, id, imoveis);
        } else if (tipo == "chacara") { //Verifica se o imóvel é uma chacara
            lerChacara(iss, id, imoveis); 
        } else {
            cerr << "Tipo de imóvel desconhecido: " << tipo << "\n";
            continue;
        }
        ++id; //Incrementar o ID
    }
}

//Função para exibir os imóveis na tela 
void exibirImoveis(const vector<Imovel*>& imoveis) {
    cout << "Tamanho do vetor de imóveis: " << imoveis.size() << "\n";
    imprimirImoveis(imoveis); //Utiliza a função para imprimir o vetor de imóveis
}

//Função para verificar se um proprietário possui imóveis
bool possuiImovelDoProprietario(const vector<Imovel*>& imoveis, const string& proprietario) {
    for (const auto& imovel : imoveis) { //Percorre o vetor de imóveis
        if (imovel->pertenceAoProprietario(proprietario)) { //Verifica se o imóvel pertence ao proprietário
            return true; //Proprietário encontrado
        }
    }
    return false; //Proprietário não encontrado
}

//Função para obter imóveis abaixo de um valor limite 
vector<Imovel*> obterImoveisAbaixoDoValor(const vector<Imovel*>& imoveis, float valorLimite) {
    vector<Imovel*> imoveisAbaixoDoLimite; 
    for (const auto& imovel : imoveis) { //Percorre o vetor de imóveis
        if (imovel->getValor() <= valorLimite) {
            imoveisAbaixoDoLimite.push_back(imovel); //Adiciona o imóvel no vetor de imóveis abaixo do valor limite
        }
    }
    return imoveisAbaixoDoLimite; //Retorna o vetor de imóveis abaixo do valor limite
}

//Função para obter imóveis com um número de quartos especificado
vector<Imovel*> obterImoveisComQuartos(const vector<Imovel*>& imoveis, int quartosEspecificado) { 
    vector<Imovel*> imoveisComQuartos;
    for (const auto& imovel : imoveis) { //Percorre o vetor de imóveis
        if (imovel->getQuartos() >= quartosEspecificado) {
            imoveisComQuartos.push_back(imovel); //Adiciona o imóvel no vetor de imóveis com o número de quartos especificado
        }
    }
    return imoveisComQuartos;   //Retorna o vetor de imóveis com o número de quartos especificado
}

//Função para comparar dois imóveis por valor
bool compararPorValor(const Imovel* a, const Imovel* b) {
    return a->getValor() > b->getValor(); //Ordena em ordem decrescente
}

//Função para obter imóveis de um tipo ordenados por valor 
vector<Imovel*> obterImoveisPorTipoOrdenadosPorValor(const vector<Imovel*>& imoveis, const string& tipoEspecificado) {
    vector<Imovel*> imoveisDoTipo;
    for (const auto& imovel : imoveis) {
        if (imovel->getType() == tipoEspecificado) { //Verifica se o imóvel é do tipo especificado
            imoveisDoTipo.push_back(imovel); 
        }
    }

    sort(imoveisDoTipo.begin(), imoveisDoTipo.end(), compararPorValor); //Ordena os imóveis por valor utilizando a função sort

    return imoveisDoTipo; //Retorna o vetor de imóveis do tipo especificado ordenados por valor
} 

//Função para obter imóveis de uma cidade ordenados por valor 
vector<Imovel*> obterImoveisPorCidadeOrdenadosPorValor(const vector<Imovel*>& imoveis, const string& cidade) {
    vector<Imovel*> imoveisNaCidade;

    for (const auto& imovel : imoveis) {
        if (imovel->getCidade() == cidade) { //Verifica se o imóvel é da cidade especificada
            imoveisNaCidade.push_back(imovel);
        }
    }
    
    sort(imoveisNaCidade.begin(), imoveisNaCidade.end(), compararPorValor); //Ordena os imóveis por valor utilizando a função sort

    return imoveisNaCidade; //Retorna o vetor de imóveis da cidade especificada ordenados por valor
}

//Função para verificar se um imóvel possui um proprietário
bool temProprietario(const Imovel* imovel, const string& proprietario) {
    return imovel->getProprietario() == proprietario; 
}

//Função para imprimir um imóvel
void imprimirImovel(const Imovel* imovel) { 
    if (const Apartamento* apt = dynamic_cast<const Apartamento*>(imovel)) { //Verifica se o imóvel é um apartamento
        cout << "Apartamento\n";
        cout << *apt; //Imprime o apartamento
    } else if (const Casa* casa = dynamic_cast<const Casa*>(imovel)) { //Verifica se o imóvel é uma casa
        cout << "Casa\n";
        cout << *casa; //Imprime a casa
    } else if (const Chacara* chacara = dynamic_cast<const Chacara*>(imovel)) { //Verifica se o imóvel é uma chacara
        cout << "Chacara\n";
        cout << *chacara;  //Imprime a chacara
    }
    cout << "\n";
}

//Função para imprimir um vetor de imóveis usando a função imprimirImovel que imprime um imóvel
void imprimirImoveis(const vector<Imovel*>& imoveis) {
    cout <<"\n";
    for (const auto& imovel : imoveis) {
        imprimirImovel(imovel);
    }
}




//Função que retorna um iterador para cada tipo de imóvel que um proprietário tenha
//esse retorno é feito com um map do tipo <std::string, std::vector<Imovel*>::iterator>
map<string, vector<vector<Imovel*>::iterator>> buscarImoveisPorProprietarioEType(vector<Imovel*> &imoveis,string proprietario){
    
    vector<vector<Imovel*>::iterator> imovel;
    map<string, vector<vector<Imovel*>::iterator>> resultado { //mapa com os tipos de imoveis
        {"apartamento", imovel}, 
        {"casa", imovel}, 
        {"chacara", imovel}  
    }; 
    vector<Imovel*>::iterator ptr; //ponteiro para percorrer o vetor de imoveis

    for(ptr = imoveis.begin(); ptr < imoveis.end(); ptr++){ 
        //Verificando se o apartamento é do proprietário
         if((*ptr)->getProprietario() == proprietario && dynamic_cast<Apartamento*>(*ptr) != nullptr){ //dynamic_cast verifica se o ponteiro é do tipo Apartamento e retorna nullptr se não for
            resultado["apartamento"].push_back(ptr);
        }
        //Verificando se a casa é do proprietário
        if((*ptr)->getProprietario() == proprietario && dynamic_cast<Casa*>(*ptr) != nullptr){ //dynamic_cast verifica se o ponteiro é do tipo Casa e retorna nullptr se não for
            resultado["casa"].push_back(ptr);
        }
        //Verificando se a chacara é do proprietário
        if((*ptr)->getProprietario() == proprietario && dynamic_cast<Chacara*>(*ptr) != nullptr){ //dynamic_cast verifica se o ponteiro é do tipo Chacara e retorna nullptr se não for
            resultado["chacara"].push_back(ptr); 
        }
    }

    return resultado; //retorna o mapa com os tipos de imoveis
}

//Função para buscar imóveis por proprietário e exibir os imóveis separados por tipo 
void buscarEExibirImoveisPorProprietario(vector<Imovel*>& imoveis, const string& proprietario) {
    map<string, vector<vector<Imovel*>::iterator>> imoveisTipoPropietario; //cria map com os tipos de imoveis
    imoveisTipoPropietario = buscarImoveisPorProprietarioEType(imoveis, proprietario); //chama a função buscarImoveisPorProprietarioEType e armazena o retorno no map imoveisTipoPropietario
    //Verificando se foi encontrado um apartamento no nome do proprietario
    if(imoveisTipoPropietario["apartamento"].size() == 0) cout << "Nenhum apartamento foi encontrado no nome desse proprietario.\n" << endl;
    for(auto ptr : imoveisTipoPropietario["apartamento"]){ //percorre o vetor de apartamentos
        imprimirImovel(*ptr); //imprime o imovel através da função imprimirImovel
    }
    //Verificando se foi encontrado uma casa no nome do proprietario
    if(imoveisTipoPropietario["casa"].size() == 0) cout << "Nenhuma casa foi encontrada no nome desse proprietario.\n" << endl;
    for(auto ptr : imoveisTipoPropietario["casa"]){ //percorre o vetor de casas
        imprimirImovel(*ptr); //imprime o imovel através da função imprimirImovel
    }
    //Verificando se foi encontrado uma chacara no nome do proprietario
    if(imoveisTipoPropietario["chacara"].size() == 0) cout << "Nenhuma chacara foi encontrada no nome desse proprietario.\n" << endl;
    for(auto ptr : imoveisTipoPropietario["chacara"]){ //percorre o vetor de chacaras
        imprimirImovel(*ptr); //imprime o imovel através da função imprimirImovel
    } 
    
}

//Função para exibir ou salvar os imóveis 
void exibirOuSalvarImoveis(const vector<Imovel*>& imoveis, const string& tipoSaida, const string& nomeArquivo) {
    if (tipoSaida != "terminal" && tipoSaida != "arquivo") { //Verifica se o tipo de saída é válido
        cerr << "Tipo de saída inválido.\n";
        return;
    }

    if (tipoSaida == "terminal") {
        imprimirImoveis(imoveis);  //Utiliza a função para imprimir o vetor de imóveis
    } else {
        ofstream arquivoSaida(nomeArquivo); //Abre o arquivo de saída
        if (!arquivoSaida.is_open()) { //Verifica se o arquivo foi aberto
            cerr << "Erro ao abrir arquivo de saída.\n";
            return;
        }
        //percorre o vetor de imoveis e imprime no arquivo de saida
        for (const auto& imovel : imoveis) { 
            if (const Apartamento* apt = dynamic_cast<const Apartamento*>(imovel)) { //Verifica se o imóvel é um apartamento utilizando dynamic_cast que retorna nullptr se o ponteiro não for do tipo Apartamento
                arquivoSaida << *apt;
            } else if (const Casa* casa = dynamic_cast<const Casa*>(imovel)) { //Verifica se o imóvel é uma casa utilizando dynamic_cast que retorna nullptr se o ponteiro não for do tipo Casa
                arquivoSaida << *casa;
            } else if (const Chacara* chacara = dynamic_cast<const Chacara*>(imovel)) { //Verifica se o imóvel é uma chacara utilizando dynamic_cast que retorna nullptr se o ponteiro não for do tipo Chacara
                arquivoSaida << *chacara; 
            }
            arquivoSaida << "\n"; //Pula uma linha
        } 
        
        arquivoSaida.close(); //Fecha o arquivo de saída
    }
}
