# Tarea 5 — Primer avance PIA — Equipo 3

## 🧩 Resumen del proyecto
El proyecto consiste en desarrollar un **payload educativo tipo “Ejecutor de algoritmo”**, cuyo propósito es **implementar y analizar algoritmos didácticos de cifrado y hashing** en C++. El programa procesará datos de prueba, mostrará resultados por consola y permitirá observar diferencias entre compilaciones optimizadas y sin optimizar.

---

## 🎯 Alcance y límites

**Alcance (permitido):**
- Implementar algoritmos **simples y educativos** de cifrado y hashing.  
- Lectura de archivos o texto desde stdin y salida por stdout o archivo local.  
- Compilación reproducible con variantes.  
- Análisis estático y dinámico de los binarios generados.  
- Documentación multimedia.

**Límites (prohibido):**
- No ejecutar ni descargar código externo.  
- No conexiones de red, persistencia en sistema ni modificación de archivos fuera del directorio del proyecto.  
- No uso de cifrado real, compresión o ofuscación con fines de ocultamiento.  
- No interacción con servicios, APIs o entornos del host.  

---

## 🗓️ Plan de trabajo por fases

| Fase | Actividades principales | Fecha estimada |
|------|--------------------------|----------------|
| **1. Diseño y planificación** | Definir algoritmos, estructura del código y convenciones de commits. | 25–31 oct |
| **2. Desarrollo inicial** | Iniciar la implementación del payload educativo en C++ y dejar evidencia de compilación y pruebas básicas en el repositorio del equipo. | 1–7 nov |
| **3. Pruebas y análisis** | Entrega las evidencias intermedias que demuestran la integración funcional del payload, las pruebas en laboratorio aislado y el inicio del análisis estático/dinámico. | 8-14 nov |
| **4. Documentación y entrega** | Entrega final del Proyecto Integrador Aplicado (PIA). | 15–20 nov |

---

## 👥 Distribución de tareas por integrante

**Jorge Casas**  
- Implementar funciones de cifrado.  
- Elaborar script de compilación.  
- Capturar análisis estático.

**Eduardo Flores**  
- Implementar funciones de hashing.  
- Ejecutar análisis dinámico (`strace`, `valgrind`).  
- Redactar resumen técnico e incluir capturas en el informe.

**Andres Flores**  
- Diseñar datos de prueba y validar resultados de algoritmos.  
- Documentar entorno de pruebas y checklist de seguridad.  
- Editar video demostrativo y preparar entrega final.

---

## 🛡️ Medidas éticas y de seguridad
- Todas las ejecuciones se realizarán **en máquinas virtuales aisladas** sin conexión externa.  
- Se crearán **snapshots previos y posteriores** a las pruebas.  
- No se realizará **exfiltración ni persistencia de datos**; todo el output será local.  
- El proyecto servirá exclusivamente para **fines académicos y demostrativos** bajo supervisión docente.

---

## 🏷️ Commit/tag inicial
Commit inicial del repositorio:  
`tag: v0.1-initial` — Hash: `c4bdbf0`  
Marca oficial del inicio del desarrollo de la Tarea 5.

---
