#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

#include <stdlib.h>

#include "conversor_de_taxas.hpp"



using namespace std;



void valor_futuro();
void valor_presente();
void converter_taxa_de_juros();
void parcelado_price();
void parcelado_sac();
void parcelados_select();


void limpa_tela_()
{
    system("CLS");
}


void menu_inicial()
{
    int opcao = 0;
    //opcao escolhida pelo usuario
    // enquanto não digita opção valida, mostra menu novamente.
    while (opcao < 1 || opcao > 4)

    {
        limpa_tela_();
        cout << "\tCALCULO FINANCEIRO\n\n";
        cout << "Selecione a operacao desejada\n";
        cout << "\n1 - Valor Futuro";
        cout << "\n2 - Valor Presente";
        cout << "\n3 - Conversao de taxa de juros";
        cout << "\n4 - Financiamento Parcelado";
        cout << "\n\nEscolha uma opcao e tecle ENTER: ";
        cout << "\nOu feche a janela para sair." << endl;

        cin >> opcao;

        switch (opcao)
        {
            case 1:
                limpa_tela_();
                valor_futuro();
                break;
            case 2:
                limpa_tela_();
                valor_presente();
                break;
            case 3:
                limpa_tela_();
                converter_taxa_de_juros();
                break;
            case 4:
                limpa_tela_();
                parcelados_select();
                break;
            
        }
    }
}

void valor_futuro()
{
    limpa_tela_();

    int prazo = 0;
    int contador = 0;

    float juros = 0;
    double capital = 0;
    double future_value = 0;

    int option_taxa;

    // Capital inicial
    cout << "\t CALCULO DO VALOR FUTURO\n\n";
    cout << "\tInsira o valor do capital inicial em R$ sem pontos nem virgula";
    cout << "\n" << endl;
    cin >> capital;

    // Seletor de taxa de juros, deve ser ao mes ou ao ano
    
    cout <<"\tInforme a taxa de juros mensal ou anual: \n";
    cout <<"\n1 - mensal";
    cout <<"\n2 - anual" << endl;

    cin >> option_taxa;

    switch (option_taxa)
    {
    case 1:
        cout << "\n\tInsira a taxa mensal utilizando ponto (0.00): " << endl;
        cin >> juros;
        break;
    
    case 2:
        cout << "\n\tInsira a taxa anual utilizando ponto (0.00): " << endl;
        cin >> juros;


        break;
    
    default:
        break;
    }



    
    if(option_taxa == 1)
    {
        cout << "\tInsira o prazo em meses: " << endl;
        cin >> prazo;
    }
    else
    {
        cout << "\tInsira o prazo em anos: " << endl;
        cin >> prazo;

        prazo = prazo * 12;
    }
    


    future_value = capital;
    if (option_taxa == 1)
    {
        for (contador = 0; prazo != contador; contador++)
        {
            future_value = future_value * (1 + juros/100);
        }
    }
    else
    {
        for (contador = 0; prazo/12 != contador; contador++)
        {
            future_value = future_value * (1 + juros/100);
        }

    }
    
    limpa_tela_();
    cout << "\tResultado\n";
    cout << "Valor Inicial: " << "R$ " << capital << endl;
    cout << "Valor corrigido (valor futuro): " << "R$ " << future_value <<" apos " << prazo << " meses" << endl;
    cout << "Valor dos juros totais: R$ " << future_value - capital << endl;
    cout << "\n";
    cout << "\nSelecione o que deseja fazer: ";
    cout << "\n1 - Novo Calculo";
    cout << "\n2 - Retornar ao Menu Principal\n";
    cout << "\nFeche a janela para sair" << endl;

    int end_calc;

    cin >> end_calc;

    switch (end_calc)
    {
    case 1:
      
        valor_futuro();
        break;
    
    case 2:
     
        menu_inicial();
        break;
    
    default:
        break;
    }

    
}

void valor_presente()
{
    limpa_tela_();

    int prazo = 0;
    int contador = 0;

    float juros = 0;
    double capital = 0;
    double present_value = 0;

    int option_taxa;

    // Capital inicial
    cout << "\t CALCULO DO VALOR PRESENTE\n\n";
    cout << "\tInsira o valor do capital em R$ sem inserir virgula ou ponto";
    cout << "\n" << endl;
    cin >> capital;

    // Seletor de taxa de juros, deve ser ao mes ou ao ano
    
    cout <<"\tInforme a taxa de juros mensal ou anual: \n";
    cout <<"\n1 - mensal";
    cout <<"\n2 - anual" << endl;

    cin >> option_taxa;

    switch (option_taxa)
    {
    case 1:
        cout << "\n\tInsira a taxa mensal utilizando ponto (0.00): " << endl;
        cin >> juros;
        break;
    
    case 2:
        cout << "\n\tInsira a taxa anual utilizando ponto (0.00): " << endl;
        cin >> juros;


        break;
    
    default:
        break;
    }



    
    if(option_taxa == 1)
    {
        cout << "\tInsira o prazo em meses: " << endl;
        cin >> prazo;
    }
    else
    {
        cout << "\tInsira o prazo em anos: " << endl;
        cin >> prazo;

        prazo = prazo * 12;
    }
    


    present_value = capital;
    if (option_taxa == 1)
    {
        for (contador = 0; prazo != contador; contador++)
        {
            present_value = present_value / (1 + juros/100);
        }
    }
    else
    {
        for (contador = 0; prazo/12 != contador; contador++)
        {
            present_value = present_value / (1 + juros/100);
        }

    }
    
    limpa_tela_();
    cout << "\tResultado\n";
    cout << "Valor com juros: " << "R$ " << capital << endl;
    cout << "Valor trazido a valor presente: " << "R$ " << present_value <<" em " << prazo << " meses";
    cout << "\n";
    cout << "\nSelecione o que deseja fazer: ";
    cout << "\n1 - Novo Calculo";
    cout << "\n2 - Retornar ao Menu Principal\n";
    cout << "\nFeche a janela para sair" << endl;

    int end_calc;

    cin >> end_calc;

    switch (end_calc)
    {
    case 1:
      
        valor_presente();
        break;
    
    case 2:
     
        menu_inicial();
        break;
    
    default:
        break;
    }

    
}

void converter_taxa_de_juros()
{
    limpa_tela_();

    int end_calc; // seleção para o menu de fim de cálculo;
    
    cout << "\tCONVERSOR DE TAXAS - METODO JUROS COMPOSTOS\n\n";
    cout << "Selecione qual conversao quer realizar: \n";
    cout << "\n1 - Taxa ao mes para taxa ao ano: ";
    cout << "\n2 - Taxa ao ano para taxa ao mes: ";
    cout << "\n3 - Taxa ao periodo selecionado: " << endl;

    
    int option_taxa_convert = 0;
    cin >> option_taxa_convert;

    switch (option_taxa_convert)
    {
    case 1:
        limpa_tela_();
        taxaMesparaAno();
        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu Principal\n";
        cout << "\nFeche a janela para sair" << endl;

        

        cin >> end_calc;

        switch (end_calc)
        {
            case 1:
            
                converter_taxa_de_juros();
                break;
            
            case 2:
            
                menu_inicial();
                break;
            }
            break;
    
    case 2:
        limpa_tela_();
        taxaAnoparaMes();
        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu Principal\n";
        cout << "\nFeche a janela para sair" << endl;

        

        cin >> end_calc;

        switch (end_calc)
        {
            case 1:
            
                converter_taxa_de_juros();
                break;
            
            case 2:
            
                menu_inicial();
                break;
            }
        break;

    case 3:
        limpa_tela_();
        taxaaoPeriodo();
        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu Principal\n";
        cout << "\nFeche a janela para sair" << endl;

        

        cin >> end_calc;

        switch (end_calc)
        {
            case 1:
            
                converter_taxa_de_juros();
                break;
            
            case 2:
            
                menu_inicial();
                break;
            }
        break;
    }    
    


}

void parcelados_select()
{   
    limpa_tela_();

    int option_pmt;

    cout << "\tSELECIONE METODO DE CALCULO DE FINANCIAMENTO\n";
    cout << "\n1 - Metodo PRICE";
    cout << "\n2 - Metodo SAC";
    cout << "\n3 - Retornar ao Menu Principal" << endl;

    cin >> option_pmt;

    switch (option_pmt)
    {
        case 1:
            parcelado_price();
            break;
      
    
        case 2:
            limpa_tela_();
            cout << "PARCELAMENTO SAC - Nao disponivel nesta versao\n";
            system ("pause");
            menu_inicial();
            break;

        case 3:
            menu_inicial();
            break;
    }
}

void parcelado_price()
{
    limpa_tela_();

    float taxa = 0;
    float valor_financiamento = 0;
    int prazo {0};

    float parcela_price {0};
    
    cout << "\tCALCULO DA PARCELA DO FINANCIAMENTO - METODO PRICE\n";
    cout << "\nInsira a taxa ao mes utilizando ponto (0.00): " << endl;
    cin >> taxa;

    cout << "Insira o prazo em meses: " << endl;
    cin >> prazo;

    cout << "Insira o valor inicial do financiamento sem pontos nem virgula: " << endl;
    cin >> valor_financiamento;

    float fator_taxa = (1 + taxa / 100);  
    double potencia_pmt = pow(fator_taxa, prazo);

    
    parcela_price = valor_financiamento * ((potencia_pmt * taxa / 100) / (potencia_pmt - 1));
    

    cout << "Resultado do parcelamento: \n";
    cout <<"R$ " << parcela_price << " pagos mensalmente durante " << prazo << " meses.";
    cout << "\nValor total do financiamento com juros: R$ " << parcela_price * prazo;
    cout << "\nJuros totais pagos no periodo: R$ " << (parcela_price * prazo) - valor_financiamento << endl;
    cout << "\n";
    cout << "\nSelecione o que deseja fazer: ";
    cout << "\n1 - Novo Calculo";
    cout << "\n2 - Retornar ao Menu Principal\n";
    cout << "\nFeche a janela para sair" << endl;

    int end_calc;

    cin >> end_calc;

    switch (end_calc)
    {
        case 1:
        
            parcelados_select();
            break;
        
        case 2:
        
            menu_inicial();
            break;
        
        default:
            break;
    }

}

void parcelado_sac() // Implementar
{   
    limpa_tela_();
    // Make sure we use types that hold decimal places
	double new_balance, ending_balance;
	double interest_paid, annual_rate, principle_paid, payment;
	
	cout << "Please enter the original loan amount $ (-1 to end the program):";
	cin >> ending_balance;
	cout << "Enter the interest rate on your loan %:";
	cin >> annual_rate;
	cout << endl;

	// Setup the stream to show dollar amount formatting
	/*cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);*/

	// Setup a counter to count payments
	int count = 1;

	// Get our standard payment which is 1/20 of loan
	payment = (ending_balance / 20.0);

	while (ending_balance > 0.0) {
		new_balance = ending_balance;  

		// Calculate interest by multiplying rate against balance
		interest_paid = new_balance * (annual_rate / 12.0);

		// Subtract interest from your payment
		principle_paid = payment - interest_paid;

		// Subtract final payment from running balance
		ending_balance = new_balance - principle_paid;

		// If the balance remaining plus its interest is less than payment amount
		// Then print out 0 balance, the interest paid and that balance minus the interest will tell us
		// how much principle you paid to get to zero.

		if ((new_balance + interest_paid) < payment) 
        {
			cout << count << ". Payment: $" << (new_balance + interest_paid) << " Interest: $" << interest_paid << " Principle: $" << (new_balance - interest_paid) << " Loan Balance is: $0.00" << endl;
		}
		else {
			// Lets show the table, loan, interest, and payment made towards principle
			cout << count << ". Payment: $" << payment << " Interest: $" << interest_paid << " Principle: $" << principle_paid << " Loan Balance is: $" << ending_balance << endl;
		}
		count++;
	}


	
	system("pause");
	
    
}


int main( void )

{
    setlocale(LC_ALL, "pt-BR");

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    menu_inicial();

}
