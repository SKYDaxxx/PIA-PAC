## Breve descripción del entorno de prueba

  * **SO:** Ubuntu 22.04 LTS (o la versión que estés usando)
  * **Compilador:** g++ (instalado mediante `build-essential`)
  * **Plataforma:** Linux x86_64

## Comandos a ejecutar para Compilar MiniCryptTool

### Compilar:
De manera estandar en la linea de comandos:
```bash
g++ MiniCryptTool.cpp -o MiniCryptTool
```
![alt](https://github.com/SKYDaxxx/PIA-PAC/blob/main/evidence/Copilacion-estandar.png)
---
### Make

Utilizando make: 
Si se descargo el archivo Makefile se puede compilar simplemente haciendo lo siguiente:
1. Asegurarse que el archivo Makefile esta en la carpeta donde esta el programa no compilado
2. Realizar:
```make```
3. En caso de ser necesario dar permisos con: chmod u+x
---
![alt](https://github.com/SKYDaxxx/PIA-PAC/blob/main/evidence/Makefile.png)

*(Nota: El ejecutable compilado `MiniCryptTool` fue movido a la carpeta `/bin/`)*

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
## Resultados observados

El archivo `out_xor.bin` se generó como un archivo binario ilegible.
Al ejecutar el comando de descifrado y revisar el archivo `recovered.txt` (usando `cat recovered.txt`), la salida de la consola fue:

```
Este es mi texto de prueba secreto
```

Esto confirma que el ciclo de cifrado y descifrado funciona correctamente.

### Evidencia (Capturas de Pantalla)

  * [Captura de la ejecución de la prueba](2025-11-07_19-12.png)


