#ifndef MIEMBRO_FAMILIA_H
#define MIEMBRO_FAMILIA_H

using namespace std; 

#include <string>

// Estructura que representa a cada integrante de la mafia
struct Miembro {
    // Datos obligatorios según el .csv
    int id;
    string name;
    string last_name;
    char genero;     // 'H' o 'M'
    int edad;
    int id_padre;     // ID del jefe (padre en el árbol)
    bool muerto_vivo;    // 1 si murió, 0 si vive
    bool preso_libre;    // 1 si está preso, 0 si está libre
    bool exjefe;   // 1 si ya tuvo el mando
    bool don_actual;    // 1 si es el Don actual

    // PUNTEROS PARA EL ÁRBOL BINARIO 
    // Cada jefe puede tener máximo 2 sucesores directos (hijos)
    Miembro* izq; 
    Miembro* der;

    // Constructor: Inicializa los punteros en NULL para evitar errores de memoria
    Miembro() {
        izq = nullptr;
        der = nullptr;
    }
};

#endif