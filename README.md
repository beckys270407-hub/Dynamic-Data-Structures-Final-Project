# Dynamic-Data-Structures-Final-Project
Dynamic Data Structures Lab Final Project Repository

Mafia Succession System - Dynamic Data Structures


Description

This project is a C++ implementation of a hierarchical management system for an Italian Mafia family. The system manages the succession of power using a Binary Tree structure. It handles data ingestion from CSV files, real-time updates of family members, and complex automated logic to determine the next Boss based on specific criteria such as age, legal status, and life status.


Project Structure

To comply with the technical requirements, the project is organized as follows:

  bin: Contains the program executable and the data.csv input file.

  src: Contains all .cpp and .h source files.

  README.md: Project documentation and instructions.


Requirements and Logic

The system implements the following core functionalities:

Binary Tree Ingestion: Loads data from .csv using a custom parser. No vectors are utilized in accordance with project constraints.

Current Succession: Displays all living family members eligible for the position.

Automated Succession: When a Boss dies, enters prison, or exceeds 70 years of age, the system searches the tree for the most suitable heir based on:

  Direct successors (children nodes).

  Cousin branches (sibling's children).

  Closest available ancestor with eligible successors.

Node Management: Allows editing member details, excluding unique IDs and parent IDs.


Authors

Rebecca Saras - Computer Engineering Student

Angelica Rodriguez - Computer Engineering Student

// bro, hay que ponerlo bonito

<h1 align="center">🌹 PROYECTO: EL PADRINO (SISTEMA DE SUCESIÓN)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/ESTADO-CONFIDENCIAL-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/LENGUAJE-C%2B%2B-black?style=for-the-badge&logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/ESTRUCTURA-ÁRBOL_BINARIO-B70000?style=for-the-badge" />
</p>

<p align="justify">
  Ante la inestabilidad en la selección del próximo líder, la Familia ha desarrollado este prototipo tecnológico. 
  El sistema procesa el linaje mediante un <b>Árbol Binario</b> (sin el uso de vectores) para garantizar que la 
  sucesión se mantenga bajo los más estrictos códigos de honor y disponibilidad legal.
</p>

<hr>

<h3>👥 INTEGRANTES DEL CLAN</h3>
<ul>
  <li><b>Angélica Rodríguez</b> - <i>Diseño de Sistemas y Lógica</i></li>
  <li><b>Rebecca Sarcos</b> - <i>Estructura de Datos y Algoritmos</i></li>
</ul>

<hr>

<h3>📂 ORGANIZACIÓN DEL EXPEDIENTE</h3>
<p>Siguiendo las normativas de entrega, el proyecto se estructura de la siguiente manera:</p>
<table>
  <tr>
    <td><b>📁 bin/</b></td>
    <td>Contiene el ejecutable <code>sistema_sucesion</code> y el archivo <code>datos_familia.csv</code>.</td>
  </tr>
  <tr>
    <td><b>📁 src/</b></td>
    <td>Contiene el código fuente íntegro (archivos <code>.cpp</code> y <code>.h</code>).</td>
  </tr>
</table>

<hr>

<h3>📜 PROTOCOLO DE SUCESIÓN (REGLAS DE HIERRO)</h3>
<p>El sistema asigna un nuevo Jefe automáticamente si el actual fallece, es encarcelado o supera los 70 años, siguiendo este orden de prioridad:</p>
<ul>
  <li><b>Fase 1:</b> El primer sucesor vivo y fuera de prisión encontrado en su subárbol.</li>
  <li><b>Fase 2:</b> Si no hay sucesores directos, se busca el primer sucesor apto en el árbol del compañero sucesor de su jefe.</li>
  <li><b>Fase 3:</b> De no hallar candidatos libres, se aplican las mismas reglas para miembros en prisión, empezando por el más cercano al jefe actual.</li>
  <li><b>Fase 4:</b> Búsqueda del jefe más cercano con dos sucesores libres para elegir al primer sucesor apto.</li>
</ul>

<hr>

<h3>📊 FORMATO DE DATOS (.CSV)</h3>
<p>El sistema convierte los datos del archivo <code>datos_familia.csv</code> considerando las siguientes columnas:</p>
<code>id, name, last_name, gender, age, id_boss, is_dead, in_jail, was_boss, is_boss</code>

<hr>

<h3>🚀 INSTRUCCIONES DE OPERACIÓN</h3>
<p>Para compilar y ejecutar el sistema (asegúrese de estar en la raíz del proyecto):</p>
<pre>
# 1. Compilación manual (Genera el binario en la carpeta bin)
g++ src/*.cpp -o bin/sistema_sucesion

# 2. Acceso a la carpeta bin
cd bin

# 3. Ejecución del protocolo
./sistema_sucesion
</pre>

<hr>

<h3>⚠️ NOTAS DE CUMPLIMIENTO</h3>
<ul>
  <li><b>Commits:</b> Se mantiene el formato estándar visto en clase (feat/fix/docs).</li>
  <li><b>Memoria:</b> Gestión dinámica de memoria mediante punteros (prohibido el uso de la librería <code>vector</code>).</li>
  <li><b>Persistencia:</b> El programa se mantiene en ejecución continua hasta que el usuario decida salir.</li>
</ul>

<br>
<p align="center">
  <i>"Mantén a tus amigos cerca, pero a tus archivos respaldados."</i><br>
  🥀 <b>SISTEMA DE CONTROL DE SUCESIÓN</b>
</p>
