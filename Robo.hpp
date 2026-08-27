#ifndef ROBO_H
#define ROBO_H

#include <iostream>
#include "Ponto2D.hpp"

struct Robo {
    //Atributos
    double _energia = 100;
    bool _com_bola;
    Ponto2D _posicao;
    int _id;


    //Métodos
    //Construtor
    Robo (int id, Ponto2D, bool);

    // Método que atualiza a posição do robo de acordo com os parametros:
    // v: magnitude do vetor velocidade; th: orientação em radianos do vetor velocidade
    // t: tempo que a velocidade foi aplicada
    // A distancia percorrida é reduzida do atributo _energia
    void mover(double v, double th, double t);

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
};

#endif
