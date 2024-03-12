# DAA - Práctica 5

## Objetivos de la práctica
Los siguientes objetivos se consideran condición necesaria pero no suficiente para aprobar la práctica:

Crear un Framework que utilice el patrón “Template” para la implementación de algoritmos de Divide y Vencerás binarios.
Utilizar el paradigma de Programación Orientada a Objetos, así como los lenguajes de programación C++, C# o Java.
Implementar haciendo uso del Framework creado los algoritmos de MergeSort y QuickSort


## Requisitos evaluables de la práctica
    1- La práctica debe cumplir con todos los requisitos de la práctica anterior.

    2- Tanto las instancias como las soluciones a cada uno de los problemas deben poder mostrarse por pantalla de forma legible para el usuario, de acuerdo a las características particulares de cada una de ellas.

    3- Se deben poder crear instancias a los problemas de diferentes tamaños.

    4- Debe existir un fichero main que permita elegir 2 modos de ejecución:
        Modo normal, donde se elige algoritmo, se ejecuta con diferentes tamaños de instancia y se muestra el tiempo que tarda en su ejecución.
        Modo debug, donde se elige algoritmo y tamaño de instancia y se muestra por pantalla tanto la instancia como la solución obtenida.


## La organización del directorio del proyecto es la siguiente:

```
└── src
    ├── Framework
    │       ├── Divide_Y_Venceras.h
    │       ├── Mergesort.h
    │       ├── Quicksort.h
    │       ├── BusquedaBinaria.h
    │       └── TorresHanoi.h
    └── main.cc
```