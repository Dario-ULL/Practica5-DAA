/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/



#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Framework/Divide_Y_Venceras.h"
#include "Framework/Mergesort.h"
#include "Framework/Quicksort.h"
#include "Framework/BusquedaBinaria.h"
#include "Framework/TorresHanoi.h"



// Función para generar un vector aleatorio de un tamaño específico
std::vector<int> generarVectorAleatorio() {
    std::vector<int> vectorAleatorio;
    std::mt19937 generador(std::time(0) + clock()); 
    std::uniform_int_distribution<int> tamanoDistribution(10, 15); 
    std::uniform_int_distribution<int> valorDistribution(1, 100);  
    int tamano = tamanoDistribution(generador);
    for (int i = 0; i < tamano; ++i) {
        vectorAleatorio.push_back(valorDistribution(generador));
    }
    return vectorAleatorio;
}



int main () {
  Divide_Y_Venceras* algoritmo;

  algoritmo = new Mergesort;
  std::vector<int> cadena = generarVectorAleatorio();
  int numeroDeLamadasMergesort = 0;
  std::vector<int> resultado = algoritmo->resolver(cadena, cadena.size());
  std::cout << "Algortimo con Mergesort" << std::endl;
	std::cout << algoritmo->recurrecia() << std::endl << "Cadena inicial: {";
  for (int i = 0; i < cadena.size() - 1; i++) {
    std::cout << cadena[i] << ", ";
  }
  std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
	std::cout << "Resultado: {";
  for (int i = 0; i < resultado.size() - 1; i++) {
    std::cout << resultado[i] << ", ";
	}
	std::cout << resultado[resultado.size() - 1] << "}" << std::endl;

  algoritmo = new Quicksort;
  cadena = generarVectorAleatorio();
  int numeroDeLamadasQuicksort = 0;
  resultado = algoritmo->resolver(cadena, cadena.size());
  std::cout << "Algortimo con Quicksort" << std::endl;
	std::cout << algoritmo->recurrecia() << std::endl << "Cadena inicial: {";
  for (int i = 0; i < cadena.size() - 1; i++) {
    std::cout << cadena[i] << ", ";
  }
  std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
	std::cout << "Resultado: {";
  for (int i = 0; i < resultado.size() - 1; i++) {
    std::cout << resultado[i] << ", ";
	}
	std::cout << resultado[resultado.size() - 1] << "}" << std::endl;


  algoritmo = new BusquedaBinaria;
  std::vector<int> new_cadena {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int dato = 2;
  int encontrado = algoritmo->resolver(new_cadena, new_cadena.size(), dato);
  std::cout << "Algortimo con BusquedaBinaria" << std::endl;
	std::cout << algoritmo->recurrecia() << std::endl << "Cadena: {";
  for (int i = 0; i < new_cadena.size() - 1; i++) {
    std::cout << new_cadena[i] << ", ";
  }
  std::cout << new_cadena[new_cadena.size() - 1] << "}" << std::endl;
	std::cout << "Resultado buscado " << dato << ": " << encontrado << std::endl;

  algoritmo = new TorresHanoi;
  int num_discos = 4;

  // Define las agujas A, B y C
  std::vector<int> aguja_A = {4,3,2,1};
  std::vector<int> aguja_B = {};
  std::vector<int> aguja_C = {};

  algoritmo->resolver(num_discos, aguja_A, aguja_C, aguja_B);
  std::cout << "A" << std::endl;
  for (int i = aguja_A.size() - 1; i >= 0; i--) {
    std::cout << aguja_A[i] << std::endl;
  }
  std::cout << "B" << std::endl;
  for (int i = aguja_B.size() - 1; i >= 0; i--) {
    std::cout << aguja_B[i] << std::endl;
  }
  std::cout << "C" << std::endl;
  for (int i = aguja_C.size() - 1; i >= 0; i--) {
    std::cout << aguja_C[i] << std::endl;
  }
  return 0;
}