## Breve descripción del entorno de prueba

  * **SO:** Ubuntu 22.04 LTS (o la versión que estés usando)
  * **Compilador:** g++ (instalado mediante `build-essential`)
  * **Plataforma:** Linux x86_64

## Comandos exactos ejecutados

### Compilar:

```bash
g++ MiniCryptTool.cpp -o MiniCryptTool
```

*(Nota: El ejecutable compilado `MiniCryptTool` fue movido a la carpeta `/bin/`)*

### Ejecutar Prueba (XOR con archivo):

Se creó un archivo `input.txt` con el texto "Este es mi texto de prueba secreto".

**Cifrado:**

```bash
./bin/MiniCryptTool --mode cipher --alg xor --key prueba1 --in input.txt > out_xor.bin
```

**Descifrado:**

```bash
./bin/MiniCryptTool --mode cipher --alg xor --key prueba1 --in out_xor.bin > recovered.txt
```

## Resultados observados

El archivo `out_xor.bin` se generó como un archivo binario ilegible.
Al ejecutar el comando de descifrado y revisar el archivo `recovered.txt` (usando `cat recovered.txt`), la salida de la consola fue:

```
Este es mi texto de prueba secreto
```

Esto confirma que el ciclo de cifrado y descifrado funciona correctamente.

### Evidencia (Capturas de Pantalla)

  * [Captura de la ejecución de la prueba](2025-11-07_19-12.png)
