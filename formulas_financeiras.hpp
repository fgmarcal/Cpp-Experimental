#include <iostream>
#include <cmath>
#include <locale>
#include <iomanip>
#include <string>
#include <cstring>

#include <cstdlib>


#ifndef FORMULAS_FINANCEIRAS_H
#define FORMULAS_FINANCEIRAS_H


const int MESES_ano {12};
const double ANO_Meses = (1.0 / 12.0);
const int Percent {100};
const double factor_converter {1.0};



using namespace std;

void taxaMesparaAno();

void taxaAnoparaMes();

void taxaaoPeriodo();

void valor_futuro();

void valor_presente();

void converter_taxa_de_juros();

void parcelado_price();

void parcelado_sac();

void parcelados_select();

void menu_inicial();




#endif