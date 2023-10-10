#include <iostream>
#include <cmath>


/*
    Crie uma classe chamada Ponto que represente um ponto no plano cartesiano com
    coordenadas x e y. Inclua construtores, métodos para definir e obter as coordenadas,
    e um método para calcular a distância até a origem (0,0).
*/

using namespace std;

class Ponto {
  private:
    int x = 0;
    int y = 0;


    public:
    //Construtor
    Ponto (int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }

    void setX(int _x){
        x = _x;
    }

    void setY(int _y){
        y = _y;
    }

    void setCoordenadas(int _x, int _y){
        x = _x;
        y = _y;
    }

    int getX (){
        return x;
    }

    int getY (){
        return y;
    }

    double calcularDistancia(){
        return sqrt((pow(x, 2) + pow(y,2)));
    }

};


int main (){

    //Instanciando objeto
    Ponto p1 (3,4);
    double distancia = p1.calcularDistancia();

    cout << "Reposta: a distancia do ponto (" << p1.getX() << "," << p1.getY() << ") ate a origem eh de " << distancia << endl;

    Ponto p2(-2, 7);
    p2.setCoordenadas(1,1);
    distancia = p2.calcularDistancia();

    cout << "Reposta: a distancia do ponto (" << p2.getX() << "," << p2.getY() << ") ate a origem eh de " << distancia << endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2,2);
    pontos[1].setCoordenadas(-1,5);
    pontos[2].setCoordenadas(0,0);

    for(int i = 0; i<3; i++){
        distancia = pontos[i].calcularDistancia();
        cout << "Reposta: a distancia do ponto " << i + 1 << " eh de " << distancia << endl;
    }
    return 0;
}