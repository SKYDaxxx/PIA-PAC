# ETHICS — PIA

## 1. Integrantes del Equipo

* Andres Tadeo Flores Pinal
* [Nombre Completo del Integrante 2]
* [Nombre Completo del Integrante 3]
* [Añadir más integrantes si es necesario]

## 2. Declaración de Cumplimiento y Medidas de Seguridad

Nosotros, los integrantes listados, declaramos que el software desarrollado para este Producto Integrador de Aprendizaje (PIA) es **estrictamente para fines educativos** y cumple con las siguientes medidas éticas y de seguridad:

1.  **Propósito Benigno:** El payload es fundamentalmente benigno. Su única funcionalidad es la **ejecución de un algoritmo didáctico** (como un cifrado simple o una función de hashing) sobre datos de prueba locales. Los resultados se imprimirán en la consola (`stdout`) y no se escribirán en ubicaciones sensibles del sistema.
2.  **No Persistencia:** El ejecutable no se instalará en el sistema, no modificará el registro (en Windows), no creará archivos de configuración fuera de su directorio de ejecución ni establecerá mecanismos para ejecutarse automáticamente (ej. servicios, tareas programadas).
3.  **No Exfiltración de Datos:** El código no leerá, copiará ni transmitirá datos reales del usuario o del sistema anfitrión. No realizará conexiones de red a servidores externos.
4.  **Entorno Controlado y Aislado:** Todas las compilaciones, ejecuciones y pruebas se realizarán **exclusivamente en máquinas virtuales (VMs) aisladas** (ej. VirtualBox, VMware) configuradas en modo "Red interna" (Internal Network) o "Anfitrión-solamente" (Host-only) para prevenir cualquier contacto con la red de producción o Internet.

## 3. Medidas Concretas de Mitigación

Para asegurar el cumplimiento de lo anterior, implementaremos las siguientes acciones prácticas:

* **Plataforma de Pruebas:** [Ej. VirtualBox 7.x en Windows 11]
* **Sistema Operativo Huésped (VM):** [Ej. Ubuntu 22.04 LTS Server / Windows 10 Pro VM]
* **Snapshot de Base:** Se utilizará un snapshot limpio de la VM antes de cada prueba.
    * **ID/Nombre del Snapshot Limpio:** `[Ej. PIA_BASE_LIMPIA_v1]`
* **Procedimiento de Restauración:** Después de cada ejecución y análisis, la máquina virtual será restaurada al snapshot limpio para eliminar cualquier artefacto y asegurar un entorno de prueba consistente y seguro.

## 4. Firmas

Como constancia de entendimiento y compromiso con estas directrices éticas:

* Andres Tadeo Flores Pinal
* [Nombre Completo del Integrante 2]
* [Nombre Completo del Integrante 3]
* [Añadir más integrantes si es necesario]
