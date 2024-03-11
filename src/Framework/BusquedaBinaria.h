/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef BUSQUEDABINARIA_H_
#define BUSQUEDABINARIA_H_

#include "Divide_Y_Venceras.h"

class BusquedaBinaria : public Divide_Y_Venceras {
	std::vector<int> resolverPequeño (std::vector<int> entrada) const;
	bool tamaño (int entrada) const;
	std::vector<std::vector<int>> dividir (std::vector<int> entrada) const;
	void combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const;

	std::string numeroSubProblemas () const;
	std::string factorDeReduccion () const;
	std::string tiempoDeCombinacion () const;
};



/**
 * Resuelve el caso menor del algoritmo BusquedaBinaria
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<int>}
*/
std::vector<int> 
BusquedaBinaria::resolverPequeño (std::vector<int> entrada) const {
	return entrada;
}



/**
 * Comprueba si la cadena es de tamaño minimo del algoritmo BusquedaBinaria
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {bool}
*/
bool 
BusquedaBinaria::tamaño (int entrada) const {
 	return entrada <= 1;	
}



/**
 * Divide la cadena en dos partes para algoritmo BusquedaBinaria
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<std::vector<int>>}
*/
std::vector<std::vector<int>> 
BusquedaBinaria::dividir (std::vector<int> entrada) const {
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
 * Combina dos cadenas de entrada del algoritmo BusquedaBinaria
 * @param {std::vector<int>} solucion1  -  Cadena de numeros
 * @param {std::vector<int>} solucion2  -  Cadena de numeros
 * @return {std::vector<int>}
*/
void
BusquedaBinaria::combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const {
  solucion1.insert(solucion1.end(), solucion2.begin(), solucion2.end());
}

/**
 * Da el numero de subproblemas creados del algoritmo BusquedaBinaria
 * @return {std::string}
*/
std::string 
BusquedaBinaria::numeroSubProblemas () const {
	return "1";
}

/**
 * Da el factor de reduccion de un subproblema del algoritmo BusquedaBinaria
 * @return {std::string}
*/
std::string  
BusquedaBinaria::factorDeReduccion () const {
	return "n/2";
}

/**
 * Da el el tiempo de combinacion del algoritmo BusquedaBinaria
 * @return {std::string}
*/
std::string 
BusquedaBinaria::tiempoDeCombinacion () const {
	return "1";
}



#endif