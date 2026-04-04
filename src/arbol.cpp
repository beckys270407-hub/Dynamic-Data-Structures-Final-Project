
#include <iostream>
#include "arbol.h"
using namespace std;

// Inicializamos el árbol vacío
ArbolGenealogico::ArbolGenealogico() {
    raiz = nullptr;
}

// Función para buscar a un jefe por su ID (Recorrido del árbol)
Miembro* ArbolGenealogico::buscarPorId(Miembro* nodo, int id_buscar) {
    if (nodo == nullptr || nodo->id == id_buscar) return nodo;

    Miembro* encontrado = buscarPorId(nodo->izq, id_buscar);
    if (encontrado) return encontrado;

    return buscarPorId(nodo->der, id_buscar);
}

// Insertar un miembro nuevo conectándolo con su jefe
void ArbolGenealogico::insertar(Miembro* nuevo) {
    if (raiz == nullptr) {
        raiz = nuevo;
        return;
    }

    Miembro* jefe = buscarPorId(raiz, nuevo->id_padre);
    if (jefe) {
        if (jefe->izq == nullptr) jefe->izq = nuevo;
        else if (jefe->der == nullptr) jefe->der = nuevo;
        else cout << "Capacidad de sucesores llena para el ID: " << jefe->id << endl;
    }
}

// Punto 2: Mostrar sucesión (Solo vivos)
void ArbolGenealogico::mostrarSucesion() {
    cout << "\n--- LINEA DE SUCESION (MIEMBROS VIVOS) ---" << endl;
    mostrarVivos(raiz);
}

void ArbolGenealogico::mostrarVivos(Miembro* nodo) {
    if (nodo == nullptr) return;
    if (!nodo->muerto_vivo) { // Si es 0 (está vivo)
        cout << "- " << nodo->name << " " << nodo->last_name << " (ID: " << nodo->id << ")" << endl;
    }
    mostrarVivos(nodo->izq);
    mostrarVivos(nodo->der);
}