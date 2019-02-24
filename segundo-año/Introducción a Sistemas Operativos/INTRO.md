# Introducción

## Introducción 1

### Sistema Operativo

> Qué es?

Es el software principal o conjunto de programas de un sistema informático que gestiona los recursos de hardware
y provee servicios a los programas de aplicación de software, ejecutándose en **modo privilegiado** respecto de
los restantes (aunque puede que parte de él se ejecute en espacio de usuario).

En ciertos textos, el sistema operativo es llamado indistintamente como núcleo o kernel, pero debe
tenerse en cuenta que la diferencia entre kernel y sistema operativo solo es aplicable si el núcleo es monolítico,
lo cual fue muy común entre los primeros sistemas. En caso contrario, es incorrecto llamar al sistema operativo núcleo.

> Unica definición?

Existen dos perspectivas al momento de definir lo que es un sistema operativo.

#### Perspectiva de arriba hacia abajo

-  Abstracción con respecto a la arquitectura

-  **Arquitectura**, conjunto de instrucciones, organización de memoria, E/S, estructura de bus)

-  El SO “oculta” el HW y presenta a los programas abstracciones más simples de manejar.

-  Los programas de aplicación son los _clientes_ del SO.

-  **Comparación**, uso de escritorio y uso de comandos de texto

-  Comodidad, “amigabilidad” (friendliness)

#### Perspectiva de abajo hacia arriba

-  Visión del SO como un administrador de recursos

-  Administra los recursos de HW de uno o más procesos

-  Provee un conjunto de servicios a los usuarios del sistema

-  Maneja la memoria secundaria y dispositivos de I/O.

-  Ejecución simultánea de procesos

-  Multiplexación en tiempo (CPU) y en espacio (memoria)
