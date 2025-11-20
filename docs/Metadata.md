# METADATA.md

## Comprobación de Entornos

Este documento forma parte del directorio `/docs/` del repositorio y detalla la verificación del entorno en el que se ejecutaron todas las pruebas.

---

## Aislamiento del Entorno

Todas las pruebas fueron realizadas en **máquinas virtuales (VMs) completamente aisladas**. Esto garantiza:

* Ausencia de comunicación externa no autorizada.
* Cero interacción con máquinas o servicios de producción.
* Ejecución exclusiva de los servicios necesarios para cada prueba.

Cada VM fue creada únicamente para este proyecto y no se utilizó con otros fines.

**Evidencia:** 
* Todas las maquinas estan aisladas para asegurar que se realizo en un entorno controlado:
![alt](https://github.com/SKYDaxxx/PIA-PAC/blob/main/evidence/VM_Aislada.jpg)

---

##  Procedimiento de Snapshots

Para asegurar la reproducibilidad y evitar efectos secundarios entre pruebas, se empleó un flujo estricto de snapshots.

###  Flujo de trabajo:

1. **Snapshot base**: Se generó un snapshot “limpio” antes de iniciar cualquier prueba.
2. **Ejecución de pruebas**: Todas las pruebas se realizaron únicamente sobre este estado base.
3. **Restauración automática**:

   * Al finalizar cada prueba, la VM fue apagada.
   * Se restauró nuevamente el snapshot base.
4. **Validación posterior**:

   * Comprobación de configuración inicial.
   * Verificación de que no existieran archivos residuales.
   * Confirmación de parámetros de red y recursos intactos.
5. **Ejemplo de snapchat creado**:
* **Snapshot Base ID:** `snap-0a1b2c3d4e5f6g7h8`
* **Fecha de Creación:** 2025-10-25
* **Descripción:** Instalación limpia de OS + herramientas de compilación (build-essential) sin código fuente clonado.

---

##  Herramientas Utilizadas

* **VirtualBox**

---

##  Notas

Este documento garantiza que el entorno de pruebas es consistente, seguro y replicable para cualquier contribuidor del repositorio.
