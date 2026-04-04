#include "arbol.h"
#include <iostream>

using namespace std;

// Constructor
ArbolGenealogico::ArbolGenealogico() {
    raiz = nullptr;
}

// Destructor: Limpia la memoria al cerrar el programa
ArbolGenealogico::~ArbolGenealogico() {
    borrarArbol(raiz);
}

void ArbolGenealogico::borrarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    borrarArbol(nodo->izq);
    borrarArbol(nodo->der);
    delete nodo;
}

// Buscar por ID (Ahora busca dentro del Nodo)
Nodo* ArbolGenealogico::buscarPorId(Nodo* nodo, int id_buscar) {
    if (nodo == nullptr || nodo->persona.id == id_buscar) return nodo;

    Nodo* encontrado = buscarPorId(nodo->izq, id_buscar);
    if (encontrado) return encontrado;

    return buscarPorId(nodo->der, id_buscar);
}

// Insertar un miembro nuevo
void ArbolGenealogico::insertar(Miembro nuevo_miembro) {
    Nodo* nuevoNodo = new Nodo(nuevo_miembro);

    if (raiz == nullptr) {
        raiz = nuevoNodo;
        return;
    }

    Nodo* jefe = buscarPorId(raiz, nuevo_miembro.id_padre);
    if (jefe) {
        if (jefe->izq == nullptr) jefe->izq = nuevoNodo;
        else if (jefe->der == nullptr) jefe->der = nuevoNodo;
        else cout << "Capacidad de sucesores llena para el ID: " << jefe->persona.id << endl;
    }
}

// Punto 2: Mostrar sucesión (Solo vivos)
void ArbolGenealogico::mostrarSucesion() {
    cout << "\n--- LINEA DE SUCESION (MIEMBROS VIVOS) ---" << endl;
    mostrarVivos(raiz);
}

void ArbolGenealogico::mostrarVivos(Nodo* nodo) {
    if (nodo == nullptr) return;
    // Si muerto_vivo es 0 (asumiendo 0 = vivo, 1 = muerto)
    if (nodo->persona.muerto_vivo == 0) { 
        cout << "- " << nodo->persona.name << " " << nodo->persona.last_name 
             << " [ID: " << nodo->persona.id << "]" << endl;
    }
    mostrarVivos(nodo->izq);
    mostrarVivos(nodo->der);
}

// --- LO QUE FALTABA: PUNTO 3 (JUBILACIÓN 70 AÑOS) ---
void ArbolGenealogico::gestionarSucesionAutomatica() {
    cout << "\n--- VERIFICANDO JUBILACIONES (REGLA DE 70 ANOS) ---" << endl;
    verificarSucesion70(raiz);
}

void ArbolGenealogico::verificarSucesion70(Nodo* nodo) {
    if (nodo == nullptr) return;

    if (nodo->persona.edad >= 70) {
        cout << "! Alerta: " << nodo->persona.name << " tiene " << nodo->persona.edad 
             << " anos. Debe entregar el mando." << endl;
        
        if (nodo->izq) cout << "  > Sucesor sugerido (Primogenito): " << nodo->izq->persona.name << endl;
        else if (nodo->der) cout << "  > Sucesor sugerido (Segundo): " << nodo->der->persona.name << endl;
        else cout << "  > No tiene herederos directos." << endl;
    }

    verificarSucesion70(nodo->izq);
    verificarSucesion70(nodo->der);
}

// --- LO QUE FALTABA: PUNTO 4 (MODIFICAR DATOS) ---
void ArbolGenealogico::modificarDatos(int id_target) {
    Nodo* objetivo = buscarPorId(raiz, id_target);
    
    if (objetivo) {
        cout << "Modificando a: " << objetivo->persona.name << endl;
        cout << "Nuevo nombre: "; cin >> objetivo->persona.name;
        cout << "Nueva edad: "; cin >> objetivo->persona.edad;
        cout << "Estado (0-Vivo, 1-Muerto, 2-Preso): "; cin >> objetivo->persona.muerto_vivo;
        cout << "Datos actualizados correctamente." << endl;
    } else {
        cout << "Error: No se encontro el miembro con ID " << id_target << endl;
    }
}

// Función para Rebecca (Cargar desde CSV) - Ella debe completar la lógica del archivo
void ArbolGenealogico::cargarDesdeCSV(string ruta) {
    cout << "Intentando cargar archivo: " << ruta << "..." << endl;
    // Rebecca usara ifstream aqui para leer linea por linea e invocar a insertar()
}