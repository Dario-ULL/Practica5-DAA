/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    12/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef Euclides_H_
#define Euclides_H_

#include "Divide_Y_Venceras.h"

class Euclides : public Divide_Y_Venceras {
	std::vector<int> resolverPequeño (std::vector<int> entrada) const;
	bool tamaño (int entrada) const;
	std::vector<std::vector<int>> dividir (std::vector<int> entrada) const;
	void combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const;

	std::string numeroSubProblemas () const;
	std::string factorDeReduccion () const;
	std::string tiempoDeCombinacion () const;
};



/**
 * Resuelve el caso menor del algoritmo Euclides
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<int>}
*/
std::vector<int> 
Euclides::resolverPequeño (std::vector<int> entrada) const {
	return entrada;
}



/**
 * Comprueba si la cadena es de tamaño minimo del algoritmo Euclides
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {bool}
*/
bool 
Euclides::tamaño (int entrada) const {
 	return entrada == 0;	
}



/**
 * Divide la cadena en dos partes para algoritmo Euclides
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<std::vector<int>>}
*/
std::vector<std::vector<int>> 
Euclides::dividir (std::vector<int> entrada) const {
	std::vector<std::vector<int>> particion(2);
  particion[0].push_back(entrada[0] - entrada[1]);
	particion[0].push_back(entrada[1]);
  particion[1].push_back(entrada[0]);
	particion[1].push_back(entrada[1] - entrada[0]);
	return particion;
}



/**
 * Combina dos cadenas de entrada del algoritmo Euclides
 * @param {std::vector<int>} solucion1  -  Cadena de numeros
 * @param {std::vector<int>} solucion2  -  Cadena de numeros
 * @return {std::vector<int>}
*/
void
Euclides::combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const {
  //no se usa
}

/**
 * Da el numero de subproblemas creados del algoritmo Euclides
 * @return {std::string}
*/
std::string 
Euclides::numeroSubProblemas () const {
	return "1";
}

/**
 * Da el factor de reduccion de un subproblema del algoritmo Euclides
 * @return {std::string}
*/
std::string  
Euclides::factorDeReduccion () const {
	return "n/2";
}

/**
 * Da el el tiempo de combinacion del algoritmo Euclides
 * @return {std::string}
*/
std::string 
Euclides::tiempoDeCombinacion () const {
	return "1";
}



#endif