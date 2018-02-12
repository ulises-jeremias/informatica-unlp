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

--------------------------------------------------------------------------------

#### Memoria Compartida

Los procesos intercambian información sobre la memoria compartida o actúan coordinadamente sobre datos residentes en ella.

Lógicamente no pueden operar simultáneamente sobre la memoria compartida, lo que obliga a bloquear y liberar el acceso a la memoria (ej: semáforos).

#### Pasaje de Mensajes

Es necesario establecer un canal (lógico o físico) para transmitir información entre procesos.

También el lenguaje debe proveer un protocolo adecuado.

Para que la comunicación sea efectiva los procesos deben "saber" cuándo tienen mensajes para leer y cuando deben trasmitir mensajes.

--------------------------------------------------------------------------------

#### Sincronización

Los procesos se SINCRONIZAN por exclusión mutua en el acceso a secciones críticas de código para no ejecutar simultáneamente, y por condición.

La sincronización permite posesión de información acerca de otro proceso para coordinar actividades.

## Clase 2

Conceptos básicos de la PC

### Prioridad

Un proceso que tiene mayor **prioridad** puede causar la suspensión (pre-emption) de otro proceso concurrente.

Análogamente puede tomar un recurso compartido, obligando a retirarse a otro proceso que lo tenga en un instante dado.

### Elección de la Granularidad

Para una dada aplicación, significa optimizar la relación entre el número de procesadores y el tamaño de memoria total.

- Grano fino
- Grano grueso

Puede verse también como la relación entre cómputo y comunicación.

### Manejo de los recursos

Uno de los temas principales de la programación concurrente es la **administración de recursos compartidos**.

Esto incluye la asignación de recursos compartidos, métodos de acceso a los recursos, bloqueo y liberación de recursos, seguridad y consistencia.

Una propiedad deseable en sistemas concurrentes es el equilibrio en el acceso a recursos compartidos por todos los procesos (fairness).

Dos situaciones NO deseadas en los programas concurrentes son la inanición de un proceso (no logra acceder a los recursos compartidos) y el overloading de un proceso (la carga asignada excede su capacidad de procesamiento).

### El problema del Deadlock

Dos (o más procesos) pueden entrar en **deadlock**, si por error de programación ambos se quedan esperando que el otro libere un recurso compartido.

La ausencia de deadlock es una propiedad necesaria en los procesos concurrentes.

4 propiedades necesarias y suficientes para que exista deadlock:

-Recursos reusables serialmente

- Los procesos comparten recursos que pueden usar con EM

  - Adquisición incremental

- Los procesos mantienen los recursos que poseen mientras esperar adquirir recursos adicionales

  - No-preemption

- Una vez que son adquiridos por un proceso, los recursos no pueden quitarse de manera forzada sino que sólo son liberados voluntariamente

  - Espera cíclica

- Existe una cadena circular (ciclo) de procesos t.q. cada uno tiene un recurso que su sucesor en el ciclo está esperando adquirir

### Requerimientos del Lenguaje Concurrente

Independientemente del mecanismo de comunicación / sincronización entre procesos, los lenguajes de programación concurrente deberán proveer primitivas adecuadas para la especificación e implementación de las mismas.

De un lenguaje de programación concurrente se requiere:

- Indicar las tareas o procesos que pueden ejecutarse concurrentemente.
- Mecanismos de sincronización
- Mecanismos de comunicación entre los procesos.

### Resumen de Conceptos

La Concurrencia es un concepto de software (propiedad del programa)

La Programación Paralela se asocia con la ejecución concurrente en múltiples procesadores que pueden tener memoria compartida, y con un objetivo de incrementar performance (propiedad de la máquina).

La Programación Distribuida es un "caso" de concurrencia con múltiples procesadores y sin memoria compartida.

En Programación Concurrente la organización de **procesos y procesadores** constituyen la arquitectura del sistema concurrente.

**Especificar la concurrencia es esencialmente especificar los procesos concurrentes, su comunicación y sincronización.**

### Paradigmas de resolución de Programas concurrentes

Si bien el número de aplicaciones es muy grande, en general los "patrones" de resolución concurrentes son pocos:

- Paralelismo iterativo
- Paralelismo recursivo
- Productores y consumidores (pipelines o workflows)
- Clientes y servidores
- Pares que interactúan (interacting peers)

#### Paralelismo iterativo

En el **paralelismo iterativo** un programa consta de un conjunto de procesos (posiblemente idénticos) c/u de los cuales tiene 1 o más loops ⇒ cada proceso es un programa iterativo.

Los procesos **cooperan** para resolver un único problema (x ej un sistema de ecuaciones), pueden trabajar independientemente, y comunicarse y sincronizar por memoria compartida o MP.

Generalmente, el dominio de datos se divide entre los procesos siguiendo diferentes patrones

#### Paralelismo recursivo

En el paralelismo recursivo el problema general (programa) puede descomponerse en procesos recursivos que trabajan sobre partes del conjunto total de datos (Dividir y conquistar).

Ejemplos clásicos son el sorting by merging, el cálculo de raíces en funciones continuas, problema del viajante, juegos (tipo ajedrez).

#### Productores y consumidores

Los esquemas **productor-consumidor** muestran procesos que se comunican.

Es habitual que estos procesos se organicen en pipes a través de los cuales fluye la información.

Cada proceso en el pipe es un filtro que consume la salida de su proceso predecesor y produce una salida para el proceso siguiente.

#### Clientes y servidores

**Cliente-servidor** es el esquema dominante en las aplicaciones de procesamiento distribuido.

Los servidores son procesos que esperan pedidos de servicios de múltiples clientes. Unos y otros pueden ejecutarse en procesadores diferentes. Comunicación bidireccional. Atención de a un cliente o con multithreading a varios.

Mecanismos de invocación variados (rendezvous y RPC x ej en MD, monitores x ej en MC).

El soporte distribuido puede ser simple (LAN) o extendido a la WEB.

#### Pares que interactúan

En los esquemas de **pares que interactúan** los procesos (que forman parte de un programa distribuido) resuelven partes del problema (normalmente mediante código idéntico) e intercambian mensajes para avanzar en la tarea y completar el objetivo.

Permite mayor grado de asincronismo que C/S

Configuraciones posibles: grilla, pipe circular, uno a uno, arbitraria

### Arquitecturas paralelas

Podemos identificar diferentes enfoques para clasificar las arquitecturas paralelas

- por la organización del espacio de direcciones (memoria compartida / memoria distribuida)
- por el mecanismo de control
- por la granularidad
- por la red de interconexión

--------------------------------------------------------------------------------

#### Clasificación por la organización del espacio de direcciones

- Multiprocesadores de memoria compartida.

  - Interacción modificando datos en la memoria compartida.
  - Problema de consistencia.

- Multiprocesadores con memoria distribuida.

  - Memoria local (no hay problemas de consistencia).
  - Interacción es sólo por pasaje de mensajes.

#### Clasificación por mecanismo de control

Propuesta por Flynn ("Some computer organizations and their effectiveness", 1972).

Se basa en la manera en que las instrucciones son ejecutadas sobre los datos.

4 clases:

- SISD (Single Instruction Single Data)
- SIMD (Single Instruction Multiple Data)
- MISD (Multiple Instruction Single Data)
- MIMD (Multiple Instruction Multiple Data)

`Leer de la teoria`
