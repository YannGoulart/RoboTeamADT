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

    // Alterando a nova posição no próprio objeto
    this->_posicao._x += distancia_horizontal;
    this->_posicao._y += distancia_vertical;
}

// método que calcula e retorna a distancia euclidiana para outro robo passado como parametro
double Robo::calcular_distancia(Robo* robo){
    // Utiliza o método de Ponto2D pra calcular essa distância
    return this->_posicao.calcular_distancia(&robo->_posicao);
}

// metodo que recebe um array de ponteiros (o time) e um parametro que informa quantos elementos no array, retorna o robo mais próximo do que invocou o método e retorna um ponteiro para ele
Robo* Robo::determinar_robo_mais_proximo(Robo** naves, int n){
    Robo* mais_proximo = this;
    double distancia_mais_proxima = 0;
    double distancia_ate_robo = 0;

    for (int i = 0; i < n; i ++)
    {
        distancia_ate_robo = this->calcular_distancia(naves[i]);

        if (i == 0){
            distancia_mais_proxima = distancia_ate_robo;
            mais_proximo = naves[i];
        }
        if (distancia_ate_robo < distancia_mais_proxima){
            distancia_mais_proxima = distancia_ate_robo;
            mais_proximo = naves[i];
        }
    }

    return mais_proximo;
}

// recebe um array de ponteiros para robos (o time) e um parametro que informa a quantidade de elementos desse array.
// Passar a bola significa apenas modificar os valores do atributo '_com_bola'
// Se o robô que invocou o método não estiver com a bola, imprime: "estou sem bola" com quebra de linha
// Deve passar a bola para o robo mais próximo
void Robo::passar_bola(Robo** time, int n){
    if (this->_com_bola){
        this->_com_bola = 0;
        Robo* mais_proximo = determinar_robo_mais_proximo(time, n);
        mais_proximo->_com_bola = 1;

    } else {
        std::cout << "Estou sem a bola!" << std::endl;
    }
}

// Imprime o estatus atual do robo
//id x y com_bola energia, utilizando tab(\t) \t para separar
void Robo::imprimir_status(){
    std::cout << this->_id << "\t" << this->_posicao._x << "\t" << this->_posicao._y << "\t" << this->_com_bola << "\t" << this->_energia << std::endl;
}
