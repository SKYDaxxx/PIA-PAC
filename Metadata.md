# Metadatos del Proyecto y Entorno de Reproducción

Este documento detalla la configuración exacta del entorno utilizado para compilar, analizar y probar **MiniCryptTool**. El objetivo es garantizar la reproducibilidad de los binarios y los resultados de las pruebas.

## 1. Configuración de Máquinas Virtuales (VMs)

A continuación se describen las VMs utilizadas en el ciclo de desarrollo y CI/CD.

| Rol de la VM | Sistema Operativo (OS) | Versión del Kernel | IP Interna (Anonimizada) | Notas Adicionales |
| :--- | :--- | :--- | :--- | :--- |
| **Build Host** | Ubuntu 22.04.2 LTS | 6.11.0.19-generic | `10.128.0.XX` | Servidor principal de compilación |
| **Test Env** | Ubuntu 22.04.9 LTS) | 6.11.0.23-generic | `10.128.0.YY` | Entorno limpio para tests de integración |
| **Trouble shooting** | Ubuntu 22.04.4 LTS | 3.10.0-173 | `192.168.1.XX` | Pruebas de compatibilidad hacia atrás |

> **Nota sobre privacidad:** Las IPs listadas corresponden a redes privadas. Los octetos finales han sido ofuscados por seguridad en este repositorio público.

## 2. Snapshots y Estado del Sistema

Para revertir el entorno a un estado conocido, utilizamos los siguientes snapshots en nuestro hipervisor (ej. VMware/VirtualBox/AWS AMI):

* **Snapshot Base ID:** `snap-0a1b2c3d4e5f6g7h8`
* **Fecha de Creación:** 2023-10-27
* **Descripción:** Instalación limpia de OS + herramientas de compilación (build-essential) sin código fuente clonado.
* **Checksum del Estado (SHA256):** `[Si aplica/disponible]`

## 3. Cadena de Herramientas (Toolchain) y Compilación

Versiones exactas de las herramientas utilizadas para generar el ejecutable `minicrypttool`.

### Compiladores
* **GCC / G++:** Versión `11.4.0` (Ubuntu 11.4.0-1ubuntu1~22.04)
* **Clang (Opcional):** Versión `14.0.0`
* **Estándar C++:** C++11 (Flags usados: `-std=c++11 -Wall -Wextra -O2`)

### Herramientas de Construcción
* **Make:** GNU Make 4.3
* **CMake:** (Si decides usarlo) Versión `3.22.1`

### Librerías del Sistema (Runtime)
* **glibc:** Versión `2.35`
* **libstdc++:** Versión `3.4.30`

## 4. Herramientas de Análisis y Seguridad

Herramientas utilizadas para verificar la integridad del código y la ausencia de fugas de memoria.

| Herramienta | Versión | Propósito | Comandos de Ejecución |
| :--- | :--- | :--- | :--- |
| **Valgrind** | `3.18.1` | Detección de memory leaks | `valgrind --leak-check=full ./minicrypttool ...` |
| **Cppcheck** | `2.7` | Análisis estático | `cppcheck --enable=all .` |
| **GDB** | `12.1` | Depuración | `gdb ./minicrypttool` |
| **ShellCheck** | `0.9.0` | Linting de scripts bash | `shellcheck tests/*.sh` |

---
*Última actualización de este archivo: 11/19/2025*
