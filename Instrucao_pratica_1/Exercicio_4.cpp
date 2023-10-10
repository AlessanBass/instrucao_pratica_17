/**
 Crie um arquivo chamado meuprog2.cpp contendo um programa que peça ao
    usuário 2 números inteiros, A e B, e mostre na tela a soma, subtração, multiplicação,
    divisão e resto da divisão desses números.

*/

#include <iostream>

using namespace std;

int main (){
    
    int a;
    int b;

    cout << "Informe o valor de a: " <<endl;
    cin >> a;
    cout << "Informe o valor de b: " << endl;
    cin >> b;

    // Imprime os valores
    cout << "Soma = " << a+b << endl;
    cout << "Subtracao = " << a-b << endl;
    cout << "Multiplicacao = " << a*b << endl;
    cout << "Divisao = " << a/b << endl;
    cout << "Modulo = " << a%b << endl;

    return 0;
}