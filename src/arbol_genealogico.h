#ifndef ARBOL_GENEALOGICO_H
#define ARBOL_GENEALOGICO_H

#include "miembro_familia.h"
#include <iostream>
#include <fstream>
#include <sstream>

class ArbolGenealogico {
private:
    Miembro* raiz; // la base del árbol

    //Funciones auxiliares: navegan enetre punteros 
    void mostrarVivos(Miembro* nodo);
    Miembro* buscarPorId(Miembro* nodo, int id_buscar);
    void borrarArbol(Miembro* nodo); // Para limpiar la memoria al final

public:
    ArbolGenealogico();  // Constructor: pone la raíz en nullptr
    ~ArbolGenealogico(); // Destructor: borra todo para no dejar basura en la PC

    // REQUISITOS DEL PROYECTO
    void cargarDesdeCSV(string ruta);    // Punto 1: Carga y crea el árbol
    void insertar(Miembro* nuevo);        // Parte lógica del Punto 1
    void mostrarSucesion();               // Punto 2: Solo los vivos
    void gestionarSucesionAutomatica();   // Punto 3: La lógica pesada de herencia
    void modificarDatos(int id_target);   // Punto 4: Cambiar todo menos IDs
};

#endif