#include <iostream>

#include "Ponto2D.hpp"

int main(){
    Ponto2D ponto1 = Ponto2D(0, 0);
    Ponto2D ponto2 = Ponto2D(0, 1);
    Ponto2D ponto3 = Ponto2D();

    std::cout << ponto1.calcular_distancia(&ponto2) << std::endl;
    std::cout << ponto3.calcular_distancia(&ponto2) << std::endl;

    return 0;
}