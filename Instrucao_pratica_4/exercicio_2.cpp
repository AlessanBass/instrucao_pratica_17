/*
    Os caracteres numéricos aparecem na tabela ASCII, e em outras, numa
    sequência que começa pelo caractere ‘0’ até o caractere ‘9’. As variáveis de
    tipo caractere podem ser tratadas também como valores numéricos. Com
    base nestas afirmações desenvolva um programa em C++ que:
*/

#include <iostream>
#include <locale>
using namespace std;

int main (){
     setlocale(LC_ALL, "Portuguese_Brazil.1252");
    /*
        A) Imprima na tela, utilizando cout, cada um dos caracteres numéricos
        e seu correspondente código numérico. Como modificar o
        comportamento do cout para imprimir um objeto de tipo char como
        caractere e como número?

    */

    cout << "============ LETRA A ==============" << endl;
    char numero = '0';
    for(int i = 0; i<=9; i++){
        cout << numero << " -> "<<  int (numero) << endl; 
        numero++;
    }
    cout << "==================================" << endl;

    /*
        B) Modifique o exercício anterior para que a saída imprima também o
        código numérico em octal e em hexadecimal.

    */

    cout << "============ LETRA B ==============" << endl;
    numero = '0';
    for(int i = 0; i<=9; i++){
        cout << numero << " -> " << int(numero) << " -> " << oct << int(numero) << " -> " << hex << int(numero) << endl;
        cout << dec ; // Volta a converter para decimal
        numero++;
    }
    cout << "==================================" << endl;

    /*
        C) Acrescente ao código do exercício anterior a possibilidade de ler um
        caractere qualquer e imprima no mesmo formato do inciso anterior.
    */

    cout << "============ LETRA C ==============" << endl;
    char caractere = ' ';
    cout << "Informe um caracter: " << endl ;
    cin >> caractere;
    cout << caractere << " -> " << int(caractere) << " -> " << oct << int (caractere) << " -> "<< hex << int(caractere) << endl;
    cout << "==================================" << endl;

    cout << "============ LETRA D ==============" << endl;
    wchar_t caractereCedilha = L'ç';
    wchar_t caractereAcentuado = L'ã';

    wcout << L"Caractere 'ç': " << caractereCedilha << endl;
    wcout << L"Caractere 'ã': " << caractereAcentuado << endl;
    cout << "==================================" << endl;


    return 0;
}