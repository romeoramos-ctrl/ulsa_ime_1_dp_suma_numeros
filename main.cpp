#include <iostream>
using namespace std;

int main() {
    const int CANTIDAD = 5;
    int contador = 0;
    double suma   = 0.0;
    double numero = 0.0;

    while (contador < CANTIDAD) {
        std::cout << "ingresa numero" << endl;
        std::cin >> numero;
        suma += numero;
        contador++;
        std::cout << "suma: " << suma << std::endl;
    }

    return 0;
}