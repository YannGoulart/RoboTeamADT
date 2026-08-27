#include "Robo.hpp"

//Atributos
double _energia = 100;
bool _com_bola;
Ponto2D _posicao;
int _id;


//Métodos
//Construtor
Robo::Robo(int id, Ponto2D posicao, bool com_bola){
    this->_id = id;
    this->_posicao = posicao;
    this->_com_bola = com_bola;
}

void mover(double v, double th, double t){}

double calcular_distancia(Robo* robo){
    return 0;
}

Robo* determinar_robo_mais_proximo(Robo** naves, int n){
    return 0;
}

void passar_bola(Robo** time, int n){}

void imprimir_status(){}
