# Concurrente

## Clase 1

### ¿Qué es la concurrencia?

Concurrencia es la capacidad de ejecutar múltiples actividades en paralelo o simultáneamente.

- Permite a distintos objetos actuar al mismo tiempo.
- La necesidad de sistemas de cómputo cada vez más poderosos y flexibles atenta contra la simplificación de asunciones de secuencialidad.
- Está presente en la naturaleza (sistemas biológicos que comprenden un gran número de células evolucionando simultáneamente y realizando procesos independientes), la vida diaria, los sistemas de cómputo, etc.
- Cualquier sistema más o menos "inteligente" o complejo exhibe concurrencia...

#### Concurrencia "Natural"

Obliga a establecer un orden en la actualización de cada objeto a la nueva posición. Representa un código más complejo de desarrollar y mantener.

#### ¿Por qué es necesaria la Programación Concurrente?

- Aplicaciones con estructura más natural

  - El mundo no es secuencial
  - Es más apropiado programar múltiples actividades independientes y concurrentes
  - Reacción a entradas asincrónicas (ej: sensores en un STR)

- Mejora en la respuesta

  - No bloquear la aplicación completa por E/S
  - Incremento en el rendimiento de la aplicación por mejor uso del hardware (ejecución paralela)

- Sistemas distribuidos

  - Una aplicación en varias máquinas
  - Sistemas C/S o P2P

### Objetivos de los Sistemas Concurrentes

- **Ajustar el Modelo** de arquitectura de hardware y software al problema del mundo real a resolver. El mundo real ES CONCURRENTE.
- **Incrementa la Performance**, mejorando los tiempos de respuesta de los sistemas de procesamiento de datos, a través de un enfoque diferente de la arquitectura física y lógica de las soluciones.
- **Ventajas** La velocidad de ejecución que se puede alcanzar, mejor utilización de la CPU de cada procesador, y explotación de la concurrencia inherente a la mayoría de los problemas reales.

### Concurrencia a nivel de Hardware

`Leer de la teoría`

### ¿Qué es un proceso?

Un proceso es un programa secuencial, un solo flujo de control que ejecuta una instrucción y cuando esta finaliza ejecuta la siguiente.

- Un único thread o flujo de control

  - Programación secuencial, monoprocesador

- Múltiples threads o flujos de control

  - Programa concurrente
  - Procesos paralelos

Los procesos **cooperan** y **compiten**.

#### Prosibles comportamientos de los procesos

Los procesos **compiten** cuando existen recursos compartidos, tales como son los procesos que presentan un Sistema Operativo o un sistema de redes.

- Deadlock
- Starvation

Los procesos **cooperan** cuando se combinan para resolver una tarea común. Se aprecia un comportamiento de sincronización.

### Procesamiento secuencial, concurrente y paralelo

La solución secuencial nos fuerza a establecer un estricto orden temporal. Al disponer de sólo una máquina el ensamblado final del objeto sólo se podrá realizar luego de N pasos de procesamiento o fabricación.

Si disponemos de N máquinas para fabricar el objeto, y no hay dependencias (por ejemplo, de la materia prima), cada una puede trabajar al mismo tiempo en una parte.

#### Otro enfoque

Una máquina dedica parte del tiempo a cada componente del objeto

- Concurrencia sin paralelismo de hardware

**Dificultades**

- Distribución de carga de trabajo
- Necesidad de compartir recursos evitando conflictos
- Necesidad de esperarse en puntos clave
- Necesidad de comunicarse
- Necesidad de recuperar el "estado" de cada proceso al retomarlo.

### Concurrencia

Concepto de software no restringido a una arquitectura particular de hardware ni a un número determinado de procesadores.

### Programa Concurrente

Un **programa concurrente** especifica dos o más programas secuenciales que pueden ejecutarse concurrentemente en el tiempo como tareas o procesos. Un **proceso** _o tarea_ es un elemento concurrente abstracto que puede ejecutarse simultáneamente con otros procesos o tareas (en paralelo), si el hardware lo permite.

Un programa concurrente puede tener N procesos habilitados para ejecutarse concurrentemente y un sistema concurrente puede disponer de M procesadores cada uno de los cuales puede ejecutar uno o más procesos.

**Características importantes**

- Interacciòn
- No determinismo

  - Dificultad para la interpretación y debug

- Ejecución "infinita"

#### Concurrencia vs Paralelismo

La concurrencia no es (sólo) paralelismo.

- Concurrencia "interleaved" ⇒

  - Procesamiento simultáneo lógicamente
  - Ejecución intercalada en un único procesador
  - "Seudo-paralelismo"

- Concurrencia simultánea ⇒

  - Procesamiento simultáneo físicamente
  - Requiere un sistema multiprocesador o multicore
  - Paralelismo "full"

### Clase de Aplicaciones

`Leer de la teoría`

### Performance

El procesamiento paralelo lleva a los conceptos de **speedup** y **eficiencia**.

- Speedup

  - _S = Ts / Tp_

- Eficiencia

  - _E = S / p_

### Conceptos básicos de concurrencia

- Un programa concurrente puede ser ejecutado por:

  - Multiprogramación

    - los procesos comparten uno o más procesadores

  - Multiprocesamiento:

    - cada proceso corre en su propio procesador pero con memoria compartida

  - Procesamiento Distribuido:

    - cada proceso corre en su propio procesador conectado a los otros a través de una red

- Los procesos se COMUNICAN. La comunicación indica el modo en que se organiza y trasmiten datos entre tareas concurrentes. Esta organización requiere especificar protocolos para controlar el progreso y corrección de la comunicación.

  - Por memoria compartida
  - Por pasaje de mensajes
