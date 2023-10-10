/**
    Crie um arquivo chamado meuprog1.cpp contendo um programa em C++ que peça o
    nome_do_usuário e mostre a mensagem “Bom dia <nome_do_usuário>

*/

#include <iostream>

using namespace std;

int main (){
    
    string nome;
    cout << "Informe o nome usuario:" << endl;
    cin >> nome;

    cout << "Bom dia " << nome << endl;
    return 0;
}