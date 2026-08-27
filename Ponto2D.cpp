# include "Ponto2D.hpp"

Ponto2D::Ponto2D(double x, double y){
    // Pega os valores do parâmetro e associa aos atributos de Ponto2D
    this->_x = x;
    this->_y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto){
    double diferenca_x = this->_x - ponto->_x;
    double diferenca_y = this->_y - ponto->_y;

    double distancia = sqrt(diferenca_x * diferenca_x + diferenca_y * diferenca_y);

    return distancia;
}
