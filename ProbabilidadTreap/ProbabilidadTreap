#include <iostream>
#include <cmath> // Para funciones matemáticas como log y pow

// Función para calcular la improbabilidad
double calculateImprobability(int N, double c) {
    const double e = std::exp(1.0); // Constante de Euler
    double lnN = std::log(N); // Logaritmo natural de N
    double term1 = N / e; // N/e
    double exponent = -c * std::log(e / c); // Exponente de la fórmula
    double improbability = std::pow(term1, exponent); // Fórmula del término de improbabilidad
    return improbability;
}

// Función para calcular la probabilidad completa
double calculateProbability(int N, double c) {
    const double e = std::exp(1.0); // Constante de Euler
    double lnN = std::log(N); // Logaritmo natural de N
    double term1 = N / e; // N/e
    double exponent = -c * std::log(e / c); // Exponente de la fórmula
    double probability = N * std::pow(term1, exponent); // Fórmula completa
    return probability;
}

int main() {
    int N;
    double c;

    // Solicitar al usuario los valores de N y c
    std::cout << "Ingrese el numero de nodos (N): ";
    std::cin >> N;
    std::cout << "Ingrese el valor de la constante c: ";
    std::cin >> c;

    // Validar entrada
    if (N <= 0 || c <= 0) {
        std::cerr << "Error: N y c deben ser mayores que 0." << std::endl;
        return 1;
    }

    // Calcular la probabilidad y la improbabilidad
    double probability = calculateProbability(N, c);
    double improbability = calculateImprobability(N, c);

    // Mostrar los resultados
    std::cout << "La probabilidad de que la altura del Treap exceda "
              << "2c * ln(N) es: " << probability << "%" << std::endl;

    std::cout << "Cuan improbable es que el Treap sea altamente desbalanceado: "
              << improbability << std::endl;

    return 0;
}
