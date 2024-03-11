/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "Divide_Y_Venceras.h"

class Quicksort : public Divide_Y_Venceras {
	std::vector<int> resolverPequeño (std::vector<int> entrada) const;
	bool tamaño (int entrada) const;
	std::vector<std::vector<int>> dividir (std::vector<int> entrada) const;
	void combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const;

	std::string numeroSubProblemas () const;
	std::string factorDeReduccion () const;
	std::string tiempoDeCombinacion () const;
};



/**
 * Resuelve el caso menor del algoritmo Quicksort
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<int>}
*/
std::vector<int> 
Quicksort::resolverPequeño (std::vector<int> entrada) const {
	return entrada;
}



/**
 * Comprueba si la cadena es de tamaño minimo del algoritmo Quicksort
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {bool}
*/
bool 
Quicksort::tamaño (int entrada) const {
 	return entrada <= 1;	
}



/**
 * Divide la cadena en dos partes para algoritmo Quicksort
 * en el que se obserba si cada elemento es menor o mayor a un pivite
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<std::vector<int>>}
*/
std::vector<std::vector<int>> 
Quicksort::dividir (std::vector<int> entrada) const {
	std::vector<std::vector<int>> particion;
	particion.resize(2);
  int pivote = entrada.back();
	particion[1].push_back(pivote);
  for (int i = 0; i < entrada.size() - 1; i++) {
    if (entrada[i] <= pivote) {
			particion[0].push_back(entrada[i]);
    } else {
			particion[1].push_back(entrada[i]);
		}
  }
	return particion;
;
}



/**
 * Combina dos cadenas de entrada del algoritmo Quicksort
 * @param {std::vector<int>} solucion1  -  Cadena de numeros
 * @param {std::vector<int>} solucion2  -  Cadena de numeros
 * @return {std::vector<int>}
*/
void
Quicksort::combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const {
  solucion1.insert(solucion1.end(), solucion2.begin(), solucion2.end());
}



/**
 * Da el numero de subproblemas creados del algoritmo Quicksort
 * @return {std::string}
*/
std::string 
Quicksort::numeroSubProblemas () const {
	return "2";
}


/**
 * Da el factor de reduccion de un subproblema del algoritmo Quicksort
 * @return {std::string}
*/
std::string  
Quicksort::factorDeReduccion () const {
	return "n/2";
}


/**
 * Da el el tiempo de combinacion del algoritmo Quicksort
 * @return {std::string}
*/
std::string 
Quicksort::tiempoDeCombinacion () const {
	return "n";
}



#endif