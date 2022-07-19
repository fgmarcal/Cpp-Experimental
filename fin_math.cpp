#include "formulas_financeiras.hpp"

using namespace std;




void limpa_tela_()
{
    system("CLS");
}

void menu_inicial()
{
    int opcao = 0;
    //opcao escolhida pelo usuario
    // enquanto não digita opção valida, mostra menu novamente.
    
    do
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
                
                valor_futuro();
                break;
            case 2:
                
                valor_presente();
                break;
            case 3:
                
                converter_taxa_de_juros();
                break;
            case 4:
                
                parcelados_select();
                break;
            
        }
    }while(1);
}

void valor_futuro() // calculo do valor futuro de um fluxo postecipado
{
    int end_calc;

    do
    {
        limpa_tela_();

        int prazo {0};
        int contador {0};

        double future_value {0.0};
        double interest_rate_FV {0.0};
        double starting_capital_FV {0.0};

        int option_taxa;

        // Capital inicial
        cout << "\t CALCULO DO VALOR FUTURO\n\n";
        cout << "\tInsira o valor do capital inicial em R$: ";
        cout << "\n" << endl;
        std::cin >> starting_capital_FV;

        // Seletor de taxa de juros, deve ser ao mes ou ao ano
        
        cout <<"\tInforme a taxa de juros mensal ou anual: \n";
        cout <<"\n1 - mensal";
        cout <<"\n2 - anual" << endl;

        cin >> option_taxa;

        switch (option_taxa)
        {
        case 1:
            cout << "\n\tInsira a taxa mensal: " << endl;
            std::cin >> interest_rate_FV;
            break;
        
        case 2:
            cout << "\n\tInsira a taxa anual: " << endl;
            std::cin >> interest_rate_FV;
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

            prazo = prazo * MESES_ano;
        }
        
        
        future_value = starting_capital_FV;
        double fator_taxa = ( factor_converter + interest_rate_FV /Percent);
        if (option_taxa == 1)
        {
            for (contador = 0; prazo != contador; contador++)
            {
                future_value = future_value * (fator_taxa);
            }
        }
        else
        {
            for (contador = 0; (prazo * ANO_Meses) != contador; contador++)
            {
                future_value = future_value * (fator_taxa);
            }

        }
        
        limpa_tela_();
        cout << "\tResultado\n";
        cout << "Valor Inicial: " << "R$ " << starting_capital_FV << endl;
        cout << "Valor corrigido (valor futuro): " << "R$ " << future_value <<" apos " << prazo << " meses" << endl;
        cout << "Valor dos juros totais: R$ " << future_value - starting_capital_FV << endl;
        cout << "\n";

        system ("pause");

        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu Principal\n";
        cout << "\nFeche a janela para sair" << endl;

        cin >> end_calc;


    }while(end_calc != 2);
    menu_inicial();
    
}

void valor_presente() // valor presente de um fluxo postecipado
{
    int end_calc;

    do
    {

        limpa_tela_();

        int prazo {0};
        int contador {0};

        double interest_PV {0.0};
        double capital {0.0};
        double present_value {0.0};

        int option_taxa;

        // Capital inicial
        cout << "\t CALCULO DO VALOR PRESENTE\n\n";
        cout << "\tInsira o valor do capital em R$ ";
        cout << "\n" << endl;
        std::cin >> capital;

        // Seletor de taxa de juros, deve ser ao mes ou ao ano
        
        cout <<"\tInforme a taxa de juros mensal ou anual: \n";
        cout <<"\n1 - mensal";
        cout <<"\n2 - anual" << endl;

        cin >> option_taxa;

        switch (option_taxa)
        {
        case 1:
            cout << "\n\tInsira a taxa mensal: " << endl;
            std::cin >> interest_PV;
            break;
        
        case 2:
            cout << "\n\tInsira a taxa anual: " << endl;
            std::cin >> interest_PV;
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

            prazo = prazo * MESES_ano;
        }
        


        present_value = capital;
        double fator_taxa = (factor_converter + interest_PV / Percent);
        if (option_taxa == 1)
        {
            for (contador = 0; prazo != contador; contador++)
            {
                present_value = present_value / (fator_taxa);
            }
        }
        else
        {
            for (contador = 0; prazo * ANO_Meses != contador; contador++)
            {
                present_value = present_value / (fator_taxa);
            }

        }
        
        limpa_tela_();
        cout << "\tResultado\n";
        cout << "Valor com juros: " << "R$ " << capital << endl;
        cout << "Valor trazido a valor presente: " << "R$ " << present_value <<" em " << prazo << " meses";
        cout << "\n";

        system("pause");

        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu Principal\n";
        cout << "\nFeche a janela para sair" << endl;

        
        cin >> end_calc;

    
    }while( end_calc != 2);
    menu_inicial();
    
}

void converter_taxa_de_juros()
{
    int option_taxa_convert;

    limpa_tela_();
        
    cout << "\tCONVERSOR DE TAXAS - METODO JUROS COMPOSTOS\n\n";
    cout << "Selecione qual conversao quer realizar: \n";
    cout << "\n1 - Taxa ao mes para taxa ao ano: ";
    cout << "\n2 - Taxa ao ano para taxa ao mes: ";
    cout << "\n3 - Taxa ao periodo selecionado: ";
    cout << "\n4 - Retornar ao Menu Principal: " << endl;

    

    cin >> option_taxa_convert;

    switch (option_taxa_convert)
    {
    case 1:
        taxaMesparaAno();
        break;  
    
    case 2:
        taxaAnoparaMes();
        break;        

    case 3:
        taxaaoPeriodo();
        break;

    case 4:
        menu_inicial();
        break;
    }    
    
    


}

void parcelados_select() // menu intermediário de seleção de método de cálculo.
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
            parcelado_sac();
            break;

        case 3:
            menu_inicial();
            break;
    }
}

void parcelado_price() //método PRICE 
{
    int end_calc;
    do
    {
        limpa_tela_();

        float taxa {0};
        float valor_financiamento {0};
        int prazo {0};

        float parcela_price {0};
        
        cout << "\tCALCULO DA PARCELA DO FINANCIAMENTO - METODO PRICE\n";
        cout << "\nInsira a taxa ao mes: " << endl;
        std::cin >> taxa;

        cout << "Insira o prazo em meses: " << endl;
        cin >> prazo;

        cout << "Insira o valor inicial do financiamento: " << endl;
        std::cin >> valor_financiamento;

        float fator_taxa = (factor_converter + taxa / Percent);  
        double potencia_pmt = pow(fator_taxa, prazo);
        
        parcela_price = valor_financiamento * ((potencia_pmt * taxa / Percent) / (potencia_pmt - factor_converter));
        
        cout << "Resultado do parcelamento: \n";
        cout <<"R$ " << parcela_price << " pagos mensalmente durante " << prazo << " meses.";
        cout << "\nValor total do financiamento com juros: R$ " << parcela_price * prazo;
        cout << "\nJuros totais pagos no periodo: R$ " << (parcela_price * prazo) - valor_financiamento << endl;
        cout << "\n";

        system("pause");

        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Refazer calculo Price";
        cout << "\n2 - Retornar ao Menu de Metodos de Financiamento\n";
        cout << "\nFeche a janela para sair" << endl;

        int end_calc;

        cin >> end_calc;

        
    }while( end_calc != 2);
    parcelados_select();
}

void parcelado_sac() // método SAC descrescente
{   
    int end_calc;
    do
    {    
        limpa_tela_();

        float taxa_juros {0.0}; 
        int prazo {0};
        int parcelas {0};
        double pagamento {0.0};
        double valor_inicial {0.0};

        cout << "\tCALCULO DA PARCELA DO FINANCIAMENTO - METODO SAC\n";

        cout << "\nInsira valor da taxa de juros: " << endl;
        cin >> taxa_juros;
        taxa_juros = taxa_juros / Percent;

        cout << "\nInsira valor inicial em R$: " << endl;
        cin >> valor_inicial;

        cout << "\nInsira a quantidade de parcelas: " << endl;
        cin >> parcelas;


        int count_parcelas = parcelas;
        double juros_acc = taxa_juros * valor_inicial;
        double valor_amortizacao = (valor_inicial / parcelas);
        pagamento = juros_acc + valor_amortizacao;

        double novo_valor = valor_inicial - valor_amortizacao;

        string space_dataframe1 = "     ";
        string space_dataframe2 = "                           ";

        limpa_tela_();
        cout << "RESULTADO DO PARCELAMENTO - SAC DECRESCENTE\n\n";
        cout << "Valor Parcelado de R$ " << valor_inicial <<" ,dividido em " << parcelas << " parcelas, a taxa de juros de " << taxa_juros * Percent << "%" <<"\n\n";

        cout << "Quantidade de parcelas" << space_dataframe1 << "Valor da parcela" << endl;
        cout << parcelas << space_dataframe2 << "R$ "<< pagamento << endl;

        for (int i = 1; i < parcelas ; i++)
        {   
            
            
            juros_acc = taxa_juros * novo_valor;
            pagamento = juros_acc + valor_amortizacao;
            
            cout <<  --count_parcelas << space_dataframe2 <<"R$ " << pagamento << endl;
            novo_valor = novo_valor - valor_amortizacao;
        }
        system("pause");
        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Refazer Calculo SAC";
        cout << "\n2 - Retornar ao Menu de Metodos de Financiamento\n";
        cout << "\nFeche a janela para sair" << endl;

        

        cin >> end_calc;


    }while(end_calc != 2);
    parcelados_select();
    
    
}

void taxaMesparaAno() // conversor de taxa ao mes para taxa ao ano.
{   
    limpa_tela_();
    int end_calc;

    do
    {
        double interest_rate {0.0};
        double taxa_convertida {0.0};

        cout << "\tConversor de taxa ao mes para taxa ao ano.\n";
        cout << "Insira a taxa ao mes: \n";
        
        std::cin >> interest_rate;

        double fator_taxa = (factor_converter + (interest_rate / Percent));
        
        taxa_convertida = pow(fator_taxa, MESES_ano);
        taxa_convertida = (taxa_convertida - factor_converter) * Percent;

        cout << "Resultado: \n";
        cout << taxa_convertida << "%" << " a.a." << endl;
        cout << "\n";

        system("pause");

        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu\n";
        cout << "\nFeche a janela para sair" << endl;

        cin >> end_calc;

    }while(end_calc != 2);   
    converter_taxa_de_juros();

}

void taxaAnoparaMes() // conversor de taxa ao ao para taxa ao mes.
{
    limpa_tela_();
    int end_calc;
    do
    {
        double taxa_ano {0.0};
        double taxa_convertida = 0;
        
        cout << "\tConversor de taxa ao ano para taxa ao mes.\n";
        cout << "Insira a taxa ao ano: \n";
        std::cin >> taxa_ano;

        double fator_taxa = (factor_converter + taxa_ano / Percent);

        taxa_convertida = pow (fator_taxa, ANO_Meses);
        taxa_convertida = (taxa_convertida - factor_converter) * Percent;

        cout << "Resultado: \n";
        cout << taxa_convertida << " %" << " a.m." << endl;
        cout << "\n";

        system("pause");

        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu\n";
        cout << "\nFeche a janela para sair" << endl;

        cin >> end_calc;

    }while(end_calc != 2);   
    converter_taxa_de_juros();

}

void taxaaoPeriodo() // conversor de taxa ao mes para taxa no periodo selecionado.
{
    limpa_tela_();
    int end_calc;
    do
    {
        double taxa_periodo {0.0};
        double taxa_convertida {0.0};
        double prazo {0.0};
        

        cout << "\tConversor de taxa ao mes no periodo em meses.\n";
        cout << "Insira a taxa ao mes a ser convertida: \n";
        std::cin >> taxa_periodo;

        cout << "Insira o prazo em meses: \n";
        cin >> prazo;

        double fator_taxa = (factor_converter + taxa_periodo / Percent);

        taxa_convertida = pow(fator_taxa, prazo);
        taxa_convertida = (taxa_convertida - factor_converter) * Percent;

        cout << "Resultado: \n";
        cout << taxa_convertida << " %" << " n.p." << " de " << (int) prazo << " meses." <<endl;
        cout << "\n";

        system("pause");

        cout << "\nSelecione o que deseja fazer: ";
        cout << "\n1 - Novo Calculo";
        cout << "\n2 - Retornar ao Menu\n";
        cout << "\nFeche a janela para sair" << endl;

        cin >> end_calc;

    }while(end_calc != 2);
    converter_taxa_de_juros();

}

