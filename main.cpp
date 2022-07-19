#include "formulas_financeiras.hpp"


using namespace std;

struct comma_separator : std::numpunct<char> {
    virtual char do_decimal_point() const override { return ','; }
};


int main( void )

{
    setlocale(LC_NUMERIC, "");

    cout.setf(ios::fixed);
    cout.precision(2);
    std::cin.imbue(std::locale(std::cout.getloc(), new comma_separator));

    menu_inicial();

}
