/**
Deverá ser o mesmo programa do exercício 4, mas as entradas e saídas devem ser
conforme o exemplo abaixo:
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main (){
    
    float a;
    float b;

    cout << "Informe o valor de a: " <<endl;
    cin >> a;
    cout << "Informe o valor de b: " << endl;
    cin >> b;

    // Imprime os valores

    cout << fixed << setprecision(1);
    cout << "Soma = " << a+b <<endl;
    cout << "Subtracao = " << a-b << endl;
    cout << "Multiplicacao = " << a*b << endl;
    cout << "Divisao = " << a/b << endl;
    cout << "Modulo = " <<  fmod(a,b) << endl;

    return 0;
}