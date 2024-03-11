/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef TORRESHANOI_H_
#define TORRESHANOI_H_

#include "Divide_Y_Venceras.h"

class TorresHanoi : public Divide_Y_Venceras {
	std::vector<int> resolverPequeño (std::vector<int> entrada) const;
	bool tamaño (int entrada) const;
	std::vector<std::vector<int>> dividir (std::vector<int> entrada) const;
	void combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const;

	std::string numeroSubProblemas () const;
	std::string factorDeReduccion () const;
	std::string tiempoDeCombinacion () const;
};



/**
 * Resuelve el caso menor del algoritmo TorresHanoi
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<int>}
*/
std::vector<int> 
TorresHanoi::resolverPequeño (std::vector<int> entrada) const {
	return {-1};
}



/**
 * Comprueba si la cadena es de tamaño minimo del algoritmo TorresHanoi
 * @param {int} entrada  -  Cadena de numeros
 * @return {bool}
*/
bool 
TorresHanoi::tamaño (int entrada) const {
 	return entrada == 1;	
}



/**
 * Divide la cadena en dos partes para algoritmo TorresHanoi
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {std::vector<std::vector<int>>}
*/
std::vector<std::vector<int>> 
TorresHanoi::dividir (std::vector<int> entrada) const {
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
 * Combina dos cadenas de entrada del algoritmo TorresHanoi
 * @param {std::vector<int>} solucion1  -  Cadena de numeros
 * @param {std::vector<int>} solucion2  -  Cadena de numeros
*/
void 
TorresHanoi::combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const {
  solucion2.push_back(solucion1.back());
	solucion1.pop_back();
}

/**
 * Da el numero de subproblemas creados del algoritmo TorresHanoi
 * @return {std::string}
*/
std::string 
TorresHanoi::numeroSubProblemas () const {
	return "2";
}

/**
 * Da el factor de reduccion de un subproblema del algoritmo TorresHanoi
 * @return {std::string}
*/
std::string  
TorresHanoi::factorDeReduccion () const {
	return "n - 1";
}

/**
 * Da el el tiempo de combinacion del algoritmo TorresHanoi
 * @return {std::string}
*/
std::string 
TorresHanoi::tiempoDeCombinacion () const {
	return "1";
}



#endif