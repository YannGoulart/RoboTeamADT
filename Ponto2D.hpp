#ifndef PONTO2D_H
#define PONTO2D_H // Define essa classe apenas se não tiver sido definida antes

#include <iostream>

struct Ponto2D {
    // Atributos
    double _x;
    double _y;

    // Métodos
    // Definindo o construtor, que recebe como valores padrão x = 0 e y = 0
    Ponto2D (double x = 0, double y = 0) {}

    double calcular_distancia(Ponto2D* ponto) {}
};

#endif