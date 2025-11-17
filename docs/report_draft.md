# Borrador del Reporte Técnico — MiniCryptTool

## 1. Resumen Ejecutivo
MiniCryptTool es un ejecutable didáctico desarrollado en C++ que implementa cifrados simples (XOR y Caesar) y funciones hash (djb2 y FNV-1a). Su propósito es servir como un payload benigno para prácticas de análisis estático, dinámico y de ingeniería inversa.

---

## 2. Descripción del Payload y Límites Éticos
MiniCryptTool está diseñado exclusivamente con fines educativos y de laboratorio.  
Funciones permitidas:
- Cifrado XOR.
- Cifrado Caesar.
- Hashing con djb2.
- Hashing con FNV-1a.
- Lectura de archivos o entrada por stdin.
- Impresión de resultados por stdout.

Límites éticos:
- No realiza conexiones de red.
- No modifica el sistema operativo.
- No persiste ni se auto-reproduce.
- No exfiltra información.
- No ejecuta acciones maliciosas.

---

## 3. Diseño e Implementación
**Lenguaje:** C++  
**Estructura del proyecto:**
- `main.cpp`: parseo de argumentos, enrutamiento de modos.
- Funciones: `cipher_xor()`, `cipher_caesar()`, `hash_djb2()`, `hash_fnv1a()`.
- Uso de `std::vector<uint8_t>` para manipular bytes.
- Lectura de archivos con `std::ifstream` y manejo automático de memoria.

**Decisiones clave de implementación:**
- Parseo manual de argumentos para mantener el binario simple.
- Evitar dependencias externas.
- Cálculo de hash en tiempo lineal.
- Cifrado XOR byte por byte sin almacenamiento temporal inseguro.

---

## 4. Procedimiento de Pruebas Ejecutadas
**Pruebas realizadas:**
- Ejecución con todos los modos y algoritmos.
- Pruebas de lectura desde archivo y desde stdin.
- Validación de claves/shift inválidos.
- Comparación entre versiones de binarios con y sin símbolos.
- Validación de salida esperada para cadenas cortas y largas.

**Resultados generales:**
- El binario responde correctamente a todos los argumentos válidos.
- Los errores de uso se muestran con mensajes adecuados.
- No se observaron fugas de memoria ni comportamientos inesperados.

---

## 5. Análisis Estático (Hallazgos Iniciales)

### **Capturas incluidas en /analysis/**
- Vista de funciones detectadas por Ghidra.
- Gráfico de llamadas (call graph).
- Tabla de strings extraídos.

### **Lista de strings relevantes identificados:**
- `"--mode"`
- `"--alg"`
- `"--key"`
- `"--in"`
- `"xor"`
- `"caesar"`
- `"djb2"`
- `"fnv1a"`
- `"Usage: "`
- `"Invalid argument"`

### **Resumen:**
El análisis estático confirma que el binario contiene únicamente lógica asociada a cifrado y hashing. Las funciones están separadas y claramente identificables. Ghidra detectó estructuras simples, sin ofuscación ni empaquetado. No existen llamadas sospechosas a librerías del sistema. El flujo principal solo procesa argumentos, carga datos y ejecuta el algoritmo elegido.

---

## 6. Análisis Dinámico (Hallazgos Iniciales)

### **Evidencias incluidas en /analysis/**
- Captura de ejecución en sandbox (stdout/stderr).
- Registro de comportamiento mientras se procesan archivos.

### **Comportamiento observado:**
- El binario no genera procesos secundarios.
- No interactúa con red, registros del sistema ni recursos críticos.
- El uso de CPU y memoria es mínimo.
- Las salidas coinciden con el comportamiento esperado según algoritmo.

### **Diferencias entre comportamiento anticipado y observado:**
- No se detectaron discrepancias significativas.
- El binario operó exactamente dentro del límite funcional esperado.

---

## 7. Riesgos Identificados y Mitigaciones Aplicadas
| Riesgo | Impacto | Mitigación |
|-------|---------|------------|
| Cifrado mal configurado por usuario | Bajo | Validación de parámetros y mensajes de ayuda. |
| Entrada de archivo corrupto | Medio | Manejo seguro de `ifstream` y validación previa. |
| Lectura de memoria fuera de rangos | Bajo | Uso de `std::vector` en lugar de punteros crudos. |
| Uso indebido del binario | Bajo | Documentación clara y propósito educativo explícito. |

---

## 8. Trabajo Pendiente y Plan para la Entrega Final
- Completar captura detallada del flujo de ejecución en Ghidra.  
- Añadir pruebas adicionales con archivos grandes.  
- Generar versión optimizada del binario y compararla con la versión con símbolos.  
- Integrar más evidencia visual en `/evidence/` (capturas y clips).  
- Finalizar el reporte técnico completo con estructura formal.  

---
