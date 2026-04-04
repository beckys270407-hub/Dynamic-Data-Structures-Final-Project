#ifndef ARBOL_GENEALOGICO_H
#define ARBOL_GENEALOGICO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "miembros.h" // Asegúrate de que este archivo exista en la misma carpeta

using namespace std;

// 1. DEFINICIÓN DEL NODO: El contenedor que forma el árbol
struct Nodo {
    Miembro persona; 
    Nodo* izq;
    Nodo* der;

    // Constructor del nodo
    Nodo(Miembro p) : persona(p), izq(nullptr), der(nullptr) {}
};

// 2. CLASE DEL ÁRBOL: La lógica de la Mafia
class ArbolGenealogico {
private:
    Nodo* raiz; // Ahora la raíz es de tipo Nodo

    // Funciones auxiliares privadas (Recursivas)
    void mostrarVivos(Nodo* nodo);
    Nodo* buscarPorId(Nodo* nodo, int id_buscar);
    void borrarArbol(Nodo* nodo);
    void verificarSucesion70(Nodo* nodo); // La lógica de jubilación

public:
    ArbolGenealogico();  // Constructor
    ~ArbolGenealogico(); // Destructor

    // FUNCIONES PRINCIPALES DEL PROYECTO
    void cargarDesdeCSV(string ruta);           // Punto 1: Carga masiva
    void insertar(Miembro nuevo);               // Auxiliar para insertar nodos
    void mostrarSucesion();                     // Punto 2: Mostrar jerarquía
    void gestionarSucesionAutomatica();         // Punto 3: Lógica de herencia y 70 años
    void modificarDatos(int id_target);         // Punto 4: Actualizar información

    // Getter para la raíz por si Rebecca lo necesita en el main
    Nodo* getRaiz() { return raiz; }
};

#endif