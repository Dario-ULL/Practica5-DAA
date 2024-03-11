#include <iostream>

// Definición de la estructura Aguja
struct Aguja {
    int nombre; // Puedes usar cualquier identificador para la aguja (A, B, C, por ejemplo)
};

// Función para mover un disco de una aguja a otra
void MoverDisco(Aguja origen, Aguja destino) {
    std::cout << "Mover disco de Aguja " << origen.nombre << " a Aguja " << destino.nombre << std::endl;
}

// Función principal de Torres de Hanoi
void Hanoi(int n, Aguja origen, Aguja destino, Aguja auxiliar) {
    if (n == 1) {
        MoverDisco(origen, destino);
    } else {
        Hanoi(n - 1, origen, auxiliar, destino);
        MoverDisco(origen, destino);
        Hanoi(n - 1, auxiliar, destino, origen);
    }
}

int main() {
    int num_discos;
    std::cout << "Ingrese el número de discos: ";
    std::cin >> num_discos;

    // Define las agujas A, B y C
    Aguja aguja_A = {1};
    Aguja aguja_B = {2};
    Aguja aguja_C = {3};

    // Llama a la función Hanoi para resolver el problema
    Hanoi(num_discos, aguja_A, aguja_C, aguja_B);

    return 0;
}
