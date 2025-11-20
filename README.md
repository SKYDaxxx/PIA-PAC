# README
# MiniCryptTool: Herramienta de Cifrado y Hash

Este proyecto es un programa educativo en C++ para la línea de comandos que implementa algoritmos básicos de cifrado (César, XOR) y hashing (DJB2, FNV-1a) para procesar texto.

---

##  Características Principales

* **Cifrado y Descifrado:**
    * Cifrado César (con desplazamiento configurable).
    * Cifrado XOR (con clave simple).
* **Hashing:**
    * DJB2
    * FNV-1a
* **Entrada flexible:** Acepta texto desde `stdin` o archivos de entrada.
* **Salida flexible:** Muestra resultados en texto plano o formato hexadecimal.

##  Plataforma Objetivo

* **SO:** Windows / Linux
* **Arquitectura:** x86_64
* **Compilador (Recomendado):** g++ (C++17) o MSVC

## Para compilar con g++
g++ -std=c++11 -Wall -o minicrypt MiniCryptTool.cpp

## Ejecucion

El uso básico del programa es: ./minicrypt --mode cipher --alg <algoritmo> [opciones...]

**Ejemplo 1: Cifrado César (desde stdin) Se usa echo para pasar texto al programa a través de una pipeline**
* **Comando:
`echo "Hola Mundo" | ./minicrypt --mode cipher --alg caesar --shift 3`**

* **Salida:
`Krod Pxqgr`**
---
**Ejemplo 2: Descifrado César (desde stdin) Se usa el desplazamiento negativo correspondiente.**
* **Comando:
`--echo "Krod Pxqgr" | ./minicrypt --mode cipher --alg caesar --shift -3`**

* **Salida:
`Hola Mundo`**
---
**Ejemplo 3:Cifrado XOR (con archivo de entrada) Primero, creamos un archivo de prueba. Luego, lo ciframos y redirigimos la salida (>) a un nuevo archivo**
* **1. Crear archivo de entrada:
`echo "Este es un secreto importante." > entrada.txt`**
* **2. Cifrar archivo: 
`./minicrypt --mode cipher --alg xor --key "miClave123" --in entrada.txt > cifrado.bin`**
  
---
**Ejemplo 4:Descifrado XOR (con archivo de entrada) El cifrado XOR es simétrico. Usar la misma clave sobre el archivo cifrado recupera el original.**
* **Comando: `./minicrypt --mode cipher --alg xor --key "miClave123" --in cifrado.bin`
* **Salida:
`Este es un secreto importante.`**

---
**Ejemplo 5:Ver todas las opciones disponibles para ejecutar codigo**
* **Comando: `./minicrypttool --help`
---
## Video de uso basico de la herramienta:
[link](https://github.com/SKYDaxxx/PIA-PAC/blob/main/evidence/demo%20uso%20basico%20del%20script.mp4)
##  Plan de trabajo por fases

|ID| Contribuidor | Contribuciones |
|------|--------------------------|----------------|
| 1.| Jorge Luis Casas | Implementar funciones de cifrado. Elaborar script de compilación ||
| 2. |Eduardo Flores Smith | Implementar funciones de hashing y Ejecutar análisis dinámico | |
| 3. |Andres Tadeo Flores | Diseñar datos de prueba y validar resultados de algoritmos |  |

---
## Reporte ejecutivo
[Reporte final](https://github.com/SKYDaxxx/PIA-PAC/blob/main/docs/Reporte_Final.pdf)

---
## Video presentacion individual
Los videos se podran encontrar en el siguiente canal: 
[Enlace a canal de youtube](https://www.youtube.com/@LSTIproyectos-ou9mx)

**COMANDO PARA OBTENER AYUDA: `./minicrypt --help`**
---
##  Cómo Clonar

Para obtener una copia local de este proyecto, clona el repositorio usando el siguiente comando:

```bash
git clone https://github.com/TU_USUARIO/nombre-proyecto.git

--





