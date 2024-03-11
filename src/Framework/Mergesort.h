/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "Divide_Y_Venceras.h"

class Mergesort : public Divide_Y_Venceras {
	std::vector<int> resolverPequeño (std::vector<int> entrada) const;
	bool tamaño (int entrada) const;
	std::vector<std::vector<int>> dividir (std::vector<int> entrada) const;
	void combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const;

	std::string numeroSubProblemas () const;
	std::string factorDeReduccion () const;
	std::string tiempoDeCombinacion () const;
};



/**
 * Resuelve el caso menor del algoritmo Mergesort
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<int>}
*/
std::vector<int> 
Mergesort::resolverPequeño (std::vector<int> entrada) const {
	return entrada;
}



/**
 * Comprueba si la cadena es de tamaño minimo del algoritmo Mergesort
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {bool}
*/
bool 
Mergesort::tamaño (int entrada) const {
 	return entrada <= 1;	
}



/**
 * Divide la cadena en dos partes para algoritmo Mergesort
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<std::vector<int>>}
*/
std::vector<std::vector<int>> 
Mergesort::dividir (std::vector<int> entrada) const {
	std::vector<std::vector<int>> particion(2);
	int mitad = entrada.size() / 2;
  for (int i = 0; i < mitad; i++) {
    particion[0].push_back(entrada[i]);
  }
  for (int i = mitad; i < entrada.size(); i++) {
    particion[1].push_back(entrada[i]);
  }
	return particion;
}



/**
 * Combina dos cadenas de entrada del algoritmo Mergesort
 * @param {std::vector<int>} solucion1  -  Cadena de numeros
 * @param {std::vector<int>} solucion2  -  Cadena de numeros
 * @return {std::vector<int>}
*/
void
Mergesort::combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const {
	std::vector<int> combinacion;
	int posicion1 = 0;
	int posicion2 = 0;
	while (posicion1 < solucion1.size() && posicion2 < solucion2.size()) {
		if (solucion1[posicion1] <= solucion2[posicion2]) {
			combinacion.push_back(solucion1[posicion1]);
			posicion1++;
		} else {
			combinacion.push_back(solucion2[posicion2]);
			posicion2++;
		}
	}
	while (posicion1 < solucion1.size()) {
    combinacion.push_back(solucion1[posicion1]);
    posicion1++;
  }
	while (posicion2 < solucion2.size()) {
    combinacion.push_back(solucion2[posicion2]);
    posicion2++;
  }
	solucion1 = combinacion;
}



/**
 * Da el numero de subproblemas creados del algoritmo Mergesort
 * @return {std::string}
*/
std::string 
Mergesort::numeroSubProblemas () const {
	return "2";
}



/**
 * Da el factor de reduccion de un subproblema del algoritmo Mergesort
 * @return {std::string}
*/
std::string  
Mergesort::factorDeReduccion () const {
	return "n/2";
}



/**
 * Da el el tiempo de combinacion del algoritmo Mergesort
 * @return {std::string}
*/
std::string 
Mergesort::tiempoDeCombinacion () const {
	return "n";
}



#endif