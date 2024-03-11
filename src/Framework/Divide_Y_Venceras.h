/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef DIVIDE_Y_VENCERAS_H_
#define DIVIDE_Y_VENCERAS_H_

#include <iostream>
#include <vector>
#include <string>

class Divide_Y_Venceras {
 public:
	virtual std::vector<int> resolverPequeño (std::vector<int> entrada) const = 0;
	virtual bool tamaño (int entrada) const = 0;
	virtual std::vector<std::vector<int>> dividir (std::vector<int> entrada) const = 0;
	virtual void combinar (std::vector<int> &solucion1, std::vector<int> &solucion2) const = 0;

	std::vector<int> resolver (std::vector<int> entrada, int tamano);
	int resolver (std::vector<int> entrada, int tamano, int dato);
	void resolver (int numeroDiscos, std::vector<int> &origen, std::vector<int> &destino, std::vector<int> &auxiliar);

	virtual std::string numeroSubProblemas () const = 0;
	virtual std::string factorDeReduccion () const = 0;
	virtual std::string tiempoDeCombinacion () const = 0;
	std::string recurrecia ();
};

/**
 * Resuelve de forma recursiva un algoritmo de ordenacion usando Divide y Venceras
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @param {int} numeroTotalDeLlamadas  -  Numero de iteraciones del programa
 * @return {std::vector<int>}
*/
std::vector<int>
Divide_Y_Venceras::resolver (std::vector<int> entrada, int tamano) {
  if (tamaño(entrada.size())) {
    return resolverPequeño(entrada);
  } else {
    std::vector<std::vector<int>> division = dividir(entrada);
    std::vector<int> solucion1 = resolver(division[0], tamano/2);
    std::vector<int> solucion2 = resolver(division[1], tamano/2);
    combinar(solucion1, solucion2);
    return solucion1;
  }	
}

/**
 * Resuelve de forma recursiva un algoritmo de busqueda usando Divide y Venceras
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @param {int} numeroTotalDeLlamadas  -  Numero de iteraciones del programa
 * @return {std::vector<int>}
*/
int
Divide_Y_Venceras::resolver (std::vector<int> entrada, int tamano, int dato) {
  if (tamaño(entrada.size())) {
		if (resolverPequeño(entrada)[0] == dato) {
			return resolverPequeño(entrada)[0];
		} else {
    	return -1;
		}
  } else {
    std::vector<std::vector<int>> division = dividir(entrada);
  	if (entrada[tamano / 2] > dato) {
		  return resolver(division[0], (tamano / 2) - 1, dato); 
		} else if (entrada[tamano / 2] < dato) {
		  return resolver(division[1], tamano / 2, dato); 
    } else {
    	return entrada[tamano / 2];
    }
  }
}

/**
 * Resuelve de forma recursiva un algoritmo de Torres de hanoi usando Divide y Venceras
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @param {int} numeroTotalDeLlamadas  -  Numero de iteraciones del programa
 * @return {std::vector<int>}
*/
void
Divide_Y_Venceras::resolver (int numeroDiscos, std::vector<int> &origen, std::vector<int> &destino, std::vector<int> &auxiliar) {
  if (tamaño(numeroDiscos)) {
    combinar(origen, destino);
  } else {
    resolver(numeroDiscos - 1, origen, auxiliar, destino);
    combinar(origen, destino);
    resolver(numeroDiscos - 1, auxiliar, destino, origen);
  }
}

/**
 * Devuelve la recurrencia de un algoritmo de Divivde y Venceras
 * @return {std::string}
*/
std::string
Divide_Y_Venceras::recurrecia () {
	std::string resultado = "T(n) <= ";
	resultado += numeroSubProblemas() + "T(";
	resultado += factorDeReduccion() + ") + ";
	resultado += tiempoDeCombinacion();
	return resultado;
}

#endif