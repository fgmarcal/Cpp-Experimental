#include <iostream>
#include <cmath>
#include <stdlib.h>






#ifndef CONVERSOR_H
#define CONVERSOR_H

using namespace std;

void taxaMesparaAno();

void taxaAnoparaMes();

void taxaaoPeriodo();



void taxaMesparaAno() // conversor de taxa ao mes para taxa ao ano.
{
    double taxa_inicial = 0;
    double taxa_convertida = 0;

    int prazo = 12;

    cout << "\tConversor de taxa ao mes para taxa ao ano.\n";
    cout << "Insira a taxa a ser convertida utilizando ponto (0.00): \n";
    cin >> taxa_inicial;


    taxa_convertida = (1 + taxa_inicial/100);
    taxa_convertida = pow(taxa_convertida, prazo);
    taxa_convertida = (taxa_convertida - 1) * 100;

    cout << "Resultado: \n";
    cout << taxa_convertida << "%" << " a.a." << endl;
    cout << "\n";

}

void taxaAnoparaMes() // conversor de taxa ao ao para taxa ao mes.
{
    double taxa_inicial = 0;
    double taxa_convertida = 0;

    double prazo = 12.0;

    cout << "\tConversor de taxa ao ano para taxa ao mes.\n";
    cout << "Insira a taxa a ser convertida utilizando ponto (0.00): \n";
    cin >> taxa_inicial;

    taxa_convertida = (1 + taxa_inicial/100);
    taxa_convertida = pow(taxa_convertida, (1 / prazo));
    taxa_convertida = (taxa_convertida - 1) * 100;

    cout << "Resultado: \n";
    cout << taxa_convertida << " %" << " a.m." << endl;
    cout << "\n";

}

void taxaaoPeriodo() // conversor de taxa ao mes para taxa no periodo selecionado.
{
    double taxa_inicial = 0;
    double taxa_convertida = 0;

    double prazo = 0.0;

    cout << "\tConversor de taxa ao mes no periodo em meses.\n";
    cout << "Insira a taxa ao mes a ser convertida utlizando ponto (0.00): \n";
    cin >> taxa_inicial;

    cout << "Insira o prazo em meses: \n";
    cin >> prazo;

    taxa_convertida = (1 + taxa_inicial/100);
    taxa_convertida = pow(taxa_convertida, prazo);
    taxa_convertida = (taxa_convertida - 1) * 100;

    cout << "Resultado: \n";
    cout << taxa_convertida << " %" << " n.p." << " de " << (int) prazo << " meses." <<endl;
    cout << "\n";

}


#endif