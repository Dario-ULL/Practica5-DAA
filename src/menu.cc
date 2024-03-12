/*
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
#include <chrono>

#include "Framework/Divide_Y_Venceras.h"
#include "Framework/Mergesort.h"
#include "Framework/Quicksort.h"
#include "Framework/BusquedaBinaria.h"
#include "Framework/TorresHanoi.h"
#include "Framework/Euclides.h"



// Función para generar un vector aleatorio de un tamaño específico
std::vector<int> generarVectorAleatorio(int tamañoVector) {
  std::vector<int> vectorAleatorio;
  std::mt19937 generador(std::time(0) + clock()); 
  std::uniform_int_distribution<int> valorDistribution(1, 100);  
  for (int i = 0; i < tamañoVector; ++i) {
    vectorAleatorio.push_back(valorDistribution(generador));
  }
  return vectorAleatorio;
}

// Función para generar un vector ordenado de un tamaño específico
std::vector<int> generarVectorOrdenado(int tamañoVector) {
  std::vector<int> vectorOrdenado;
  for (int i = 0; i < tamañoVector; ++i) {
    vectorOrdenado.push_back(i);
  }
  return vectorOrdenado;
}

// Función para leer por pantalla un numero
int obtenerNumero() {
  int tamaño;
  while (true) {
    std::cout << "Ingrese el tamaño del vector: ";
    std::cin >> tamaño;
    if (tamaño > 0) {
      break;
    } else {
      std::cout << "Ingrese un numero valido" << std::endl;
    }
  }
  return tamaño;
}


int main (int argv, char* argc[]) {
  if (argc[1][0] == '0') {
    std::cout  << "MODO NORMAL ACTIVADO" << std::endl;
  } else {
    std::cout  << "MODO DEBUG ACTIVADO" << std::endl;
  }
  Divide_Y_Venceras* algoritmo;
  int tipoAlgoritmo;
  while (true) {
    std::cout << "Algoritmos:" << std::endl;
    std::cout << "(1)Quicksort" << std::endl;
    std::cout << "(2)Mergesort" << std::endl;
    std::cout << "(3)Busqueda Binaria" << std::endl;
    std::cout << "(4)Torre de Hanoi" << std::endl;
    std::cout << "(5)Euclides" << std::endl;
    std::cout << "Elije el algoritmo: ";
    std::cin >> tipoAlgoritmo;
    if (tipoAlgoritmo == 1 || tipoAlgoritmo == 2 || tipoAlgoritmo == 3 || tipoAlgoritmo == 4 || tipoAlgoritmo == 5) {
      break;
    } else {
      std::cout << "Elije un algoritmo de la lista, para elegir el algoritmo deseado pone el numero que esta entre parentesis" << std::endl; 
    }
  }
  std::cout << std::endl << std::endl;

  switch (tipoAlgoritmo) {
    case 1:
      std::cout << "Algoritmo Quicksort" << std::endl;
      algoritmo = new Quicksort;
      if (argc[1][0] == '0') {
        std::vector<int> cadenaPequeña = generarVectorAleatorio(10);
        std::vector<int> cadenaMediana = generarVectorAleatorio(15);
        std::vector<int> cadenaGrande = generarVectorAleatorio(20);
        for (int i = 0; i < 3; ++i) {
          std::vector<int> &cadena = (i == 0) ? cadenaPequeña : ((i == 1) ? cadenaMediana : cadenaGrande);
          auto start_time = std::chrono::high_resolution_clock::now();
          std::vector<int> resultado = algoritmo->resolver(cadena);
          auto end_time = std::chrono::high_resolution_clock::now();
          auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
          std::cout << "Cadena inicial: {";
          for (int i = 0; i < cadena.size() - 1; i++) {
            std::cout << cadena[i] << ", ";
          }
          std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
          std::cout << "Resultado: {";
          for (int i = 0; i < resultado.size() - 1; i++) {
            std::cout << resultado[i] << ", ";
          }
          std::cout << resultado[resultado.size() - 1] << "}" << std::endl << std::endl;
          std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
        }
      } else {
        int tamaño = obtenerNumero();
        std::vector<int> cadena = generarVectorAleatorio(tamaño);
        auto start_time = std::chrono::high_resolution_clock::now();
        std::vector<int> resultado = algoritmo->resolver(cadena);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Cadena inicial: {";
        for (int i = 0; i < cadena.size() - 1; i++) {
          std::cout << cadena[i] << ", ";
        }
        std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
        std::cout << "Resultado: {";
        for (int i = 0; i < resultado.size() - 1; i++) {
          std::cout << resultado[i] << ", ";
        }
        std::cout << resultado[resultado.size() - 1] << "}" << std::endl << std::endl;
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
      } 
      break;
    case 2:
      std::cout << "Algoritmo Mergesort" << std::endl;
      algoritmo = new Mergesort;
      if (argc[1][0] == '0') {
        std::vector<int> cadenaPequeña = generarVectorAleatorio(10);
        std::vector<int> cadenaMediana = generarVectorAleatorio(15);
        std::vector<int> cadenaGrande = generarVectorAleatorio(20);
        for (int i = 0; i < 3; ++i) {
          std::vector<int> &cadena = (i == 0) ? cadenaPequeña : ((i == 1) ? cadenaMediana : cadenaGrande);
          auto start_time = std::chrono::high_resolution_clock::now();
          std::vector<int> resultado = algoritmo->resolver(cadena);
          auto end_time = std::chrono::high_resolution_clock::now();
          auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
          std::cout << "Cadena inicial: {";
          for (int i = 0; i < cadena.size() - 1; i++) {
            std::cout << cadena[i] << ", ";
          }
          std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
          std::cout << "Resultado: {";
          for (int i = 0; i < resultado.size() - 1; i++) {
            std::cout << resultado[i] << ", ";
          }
          std::cout << resultado[resultado.size() - 1] << "}" << std::endl << std::endl;
          std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
        }
      } else {
        int tamaño = obtenerNumero();
        std::vector<int> cadena = generarVectorAleatorio(tamaño);
        auto start_time = std::chrono::high_resolution_clock::now();
        std::vector<int> resultado = algoritmo->resolver(cadena);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Cadena inicial: {";
        for (int i = 0; i < cadena.size() - 1; i++) {
          std::cout << cadena[i] << ", ";
        }
        std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
        std::cout << "Resultado: {";
        for (int i = 0; i < resultado.size() - 1; i++) {
          std::cout << resultado[i] << ", ";
        }
        std::cout << resultado[resultado.size() - 1] << "}" << std::endl << std::endl;
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;      }
      break;
    case 3:
      std::cout << "Algoritmo Busqueda Binaria" << std::endl;
      algoritmo = new BusquedaBinaria;
      std::srand(static_cast<unsigned int>(std::time(nullptr)));
      if (argc[1][0] == '0') {
        std::vector<int> cadenaPequeña = generarVectorOrdenado(10);
        std::vector<int> cadenaMediana = generarVectorOrdenado(15);
        std::vector<int> cadenaGrande = generarVectorOrdenado(20);
        for (int i = 0; i < 3; ++i) {
          std::vector<int> &cadena = (i == 0) ? cadenaPequeña : ((i == 1) ? cadenaMediana : cadenaGrande);
          int dato = cadena[std::rand() % cadena.size()];
          auto start_time = std::chrono::high_resolution_clock::now();
          int encontrado = algoritmo->resolver(cadena, cadena.size(), dato);
          auto end_time = std::chrono::high_resolution_clock::now();
          auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
          std::cout << "Numero buscado (" << dato << ")" << std::endl;
          std::cout << "Cadena inicial: {";
          for (int i = 0; i < cadena.size() - 1; i++) {
            std::cout << cadena[i] << ", ";
          }
          std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
          std::cout << "Resultado encontrado: " << encontrado << std::endl << std::endl;
          std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
        }
      } else {
        int tamaño = obtenerNumero();
        std::vector<int> cadena = generarVectorOrdenado(tamaño);
        int dato = cadena[std::rand() % cadena.size()];
        auto start_time = std::chrono::high_resolution_clock::now();
        int encontrado = algoritmo->resolver(cadena, cadena.size(), dato);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Numero buscado (" << dato << ")" << std::endl;
        std::cout << "Cadena inicial: {";
        for (int i = 0; i < cadena.size() - 1; i++) {
          std::cout << cadena[i] << ", ";
        }
        std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
        std::cout << "Resultado encontrado: " << encontrado << std::endl << std::endl;
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
      }
      break;
    case 4:
      std::cout << "Algoritmo Torres de Hanoi" << std::endl;
      algoritmo = new TorresHanoi;
      if (argc[1][0] == '0') {
        int num_discos = 4;
        std::vector<int> aguja_A = {4,3,2,1};
        std::vector<int> aguja_B = {};
        std::vector<int> aguja_C = {};
        std::cout << "Inicio" << std::endl;
        std::cout << " A" << "   B   " << "C" << std::endl; 
        for (int i = 3; i >= 0; i--) {
          std::cout << "[" << aguja_A[i] << "]" << " [ ] [ ]" << std::endl; 
        }
        auto start_time = std::chrono::high_resolution_clock::now();
        algoritmo->resolver(num_discos, aguja_A, aguja_C, aguja_B);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Resultado" << std::endl;
        std::cout << " A" << "   B   " << "C" << std::endl; 
        for (int i = 3; i >= 0; i--) {
          std::cout << "[ ] [ ] [" << aguja_C[i] << "]" << std::endl; 
        }
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
      } else {
        int numDiscos = obtenerNumero();
        std::vector<int> aguja_A = {};
        for (int i = numDiscos; i >= 1; i--) {
          aguja_A.push_back(i);
        }
        std::vector<int> aguja_B = {};
        std::vector<int> aguja_C = {};
        std::cout << "Inicio" << std::endl;
        std::cout << " A" << "   B   " << "C" << std::endl; 
        for (int i = numDiscos - 1; i >= 0; i--) {
          std::cout << "[" << aguja_A[i] << "]" << " [ ] [ ]" << std::endl; 
        }
        auto start_time = std::chrono::high_resolution_clock::now();
        algoritmo->resolver(numDiscos, aguja_A, aguja_C, aguja_B);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Resultado" << std::endl;
        std::cout << " A" << "   B   " << "C" << std::endl; 
        for (int i = numDiscos - 1; i >= 0; i--) {
          std::cout << "[ ] [ ] [" << aguja_C[i] << "]" << std::endl; 
        }
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
      }
      break;
    case 5:
      std::cout << "Algoritmo Euclides" << std::endl;
      algoritmo = new Euclides;
      std::srand(static_cast<unsigned int>(std::time(nullptr)));
      if (argc[1][0] == '0') {
        std::vector<int> cadena = {8,12};
        for (int i = 0; i < 3; ++i) {
          auto start_time = std::chrono::high_resolution_clock::now();
          std::vector<int> encontrado = algoritmo->resolver(cadena);
          auto end_time = std::chrono::high_resolution_clock::now();
          auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
          std::cout << "Cadena inicial: {";
          for (int i = 0; i < cadena.size() - 1; i++) {
            std::cout << cadena[i] << ", ";
          }
          std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
          std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
        }
      } else {
        int tamaño = obtenerNumero();
        std::vector<int> cadena = generarVectorOrdenado(tamaño);
        int dato = cadena[std::rand() % cadena.size()];
        auto start_time = std::chrono::high_resolution_clock::now();
        int encontrado = algoritmo->resolver(cadena, cadena.size(), dato);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Cadena inicial: {";
        for (int i = 0; i < cadena.size() - 1; i++) {
          std::cout << cadena[i] << ", ";
        }
        std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
        std::cout << "Resultado encontrado: " << encontrado << std::endl << std::endl;
        std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
      }
      break;
    default:
      break;
  }
	std::cout << "Recurrencia del algoritmo: " << algoritmo->recurrecia() << std::endl;
  return 0;
}