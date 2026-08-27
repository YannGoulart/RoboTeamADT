#include "Robo.hpp"

Robo::Robo(int id, Ponto2D posicao, bool com_bola){
    this->_id = id;
    this->_posicao = posicao;
    this->_com_bola = com_bola;
}

    // Método que atualiza a posição do robo de acordo com os parametros:
    // v: magnitude do vetor velocidade; th: orientação em radianos do vetor velocidade
    // t: tempo que a velocidade foi aplicada
    // A distancia percorrida é reduzida do atributo _energia
void Robo::mover(double v, double th, double t){
    // Calculando a distância percorrida
    double distancia_percorrida = v * t;
    this->_energia -= distancia_percorrida;

    // Calculando a distancia percorrida verticalmente e horizontalmente
    double distancia_vertical = distancia_percorrida * std::sin(th);
    double distancia_horizontal = distancia_percorrida * std::cos(th);

    // Alterando a nova posiçaõ no próprio objeto
    this->_posicao._x += distancia_horizontal;
    this->_posicao._y += distancia_vertical;
}

    // método quecalcula e retorna a distancia euclidiana para outro robo passado como paramettro  
    double calcular_distancia(Robo* robo);

    // metodo que recebe um array de ponteiros (o time) e um parametro que informa quantos elementos no array, retorna o robo mais próximo do que invocou o método e retorna um ponteiro para ele
    Robo* determinar_robo_mais_proximo(Robo** naves, int n);

    // recebe um array de ponteiros para robos (o time) e um parametro que informa a quantidade de elementos desse array.
    // Passar a bola significa apenas modificar os valores do atributo '_com_bola'
    // Se o robô que invocou o método não estiver com a bola, imprime: "estou sem bola" com quebra de linha
    void passar_bola(Robo** time, int n);

    // Imprime o estatus atual do robo
    //id x y com_bola energia, utilizando tab(\t) \t para separar
    void imprimir_status();