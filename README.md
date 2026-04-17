<div align="center">

# 🍷 PROYECTO: OMERTA (SISTEMA DE SUCESIÓN) 🍷
### *“El poder no se pide, se hereda por la estructura”*

![Estado](https://img.shields.io/badge/ESTADO-CONFIDENCIAL-red?style=for-the-badge)
![Lenguaje](https://img.shields.io/badge/LENGUAJE-C%2B%2B-black?style=for-the-badge&logo=c%2B%2B)
![Estructura](https://img.shields.io/badge/ESTRUCTURA-ARBOL_BINARIO-8b0000?style=for-the-badge)

---

</div>

## 📑 DOSSIER DEL CLAN (DESARROLLADORES)
Este sistema de alta seguridad ha sido diseñado por los siguientes operativos:
* **👤 Angélica Rodríguez** — `C.I: 32.220.574`
* **👤 Rebecca Saras** — `C.I: 32.039.073`

---

## 🏗️ ORGANIZACIÓN LOGÍSTICA
Para cumplir con los protocolos de entrega, el proyecto se divide en:

* **📁 bin/**: Contiene el ejecutable `succession_system` y la base de datos `family_data.csv`.
* **📁 src/**: Contiene exclusivamente el código fuente del proyecto (`.cpp` y `.hpp`).

---

## 📜 PROTOCOLO DE HIERRO (REGLAS DE SUCESIÓN)
El sistema analiza el árbol genealógico y asigna un nuevo Don automáticamente si el actual fallece, es encarcelado o supera los 70 años:

1. **Fase 1:** Primer sucesor vivo y libre dentro de su propio subárbol.
2. **Fase 2:** Si no hay directos, se busca en la rama del segundo sucesor del Don.
3. **Fase 3:** Si todos están marcados, se consideran candidatos en prisión (por cercanía).
4. **Fase 4:** Búsqueda en jefes aliados con sucesores aptos.

---

## 🚀 INSTRUCCIONES DE OPERACIÓN (COMPILACIÓN)

Para compilar y ejecutar el sistema, asegúrese de estar en el directorio raíz del proyecto y siga estos comandos:

### 🛠️ 1. Compilación
Use el compilador `g++` para vincular los archivos de `src/` y generar el binario en la carpeta `bin/`:

```bash
g++ src/*.cpp -o bin/succession_system