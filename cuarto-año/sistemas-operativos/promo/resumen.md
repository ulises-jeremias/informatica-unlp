## THREADS

1. Un thread no tiene program counter (PC) propio.

La creación de un proceso involucra una operación tipo fork, creando un nuevo espacio
de direcciones, PCB, PC, etc. El nuevo proceso es creado y controlado a través de
system calls que exigen el mismo tratamiento que una interrupción.

La **creación de un hilo** involucra sólo la creación de un conjunto de registros, un PC y un espacio para stack, requiriendo un gasto mínimo de procesamiento.

2. Un context switch entre threads, no requiere un context switch de registros

Cuando un proceso tradicionales gana CPU, el sistema operativo debe hacer un cambio
de contexto (context switch) para hacer el correspondiente salvado del ambiente
relacionado con el proceso anterior y cargar el ambiente del nuevo. Esta actividad la
realiza el sistema operativo, en modo supervisor, y es la consecuencia de algún system
call emitido por el proceso saliente o interrupción.

**Entre los hilos que comparten una tarea, el cambio entre uno y otro es más simple pues
el context switch es sólo a nivel del conjunto de registros y carga**. No hay cambios con
respecto a espacios de direcciones. Podemos resumir que en el switching de los hilos no se exige la participación del sistema operativo e interrupciones al kernel. 

3. Un hilo creado por un proceso tendrá su propio contexto.

Un **hilo creado por un proceso tendrá su propio contexto**, pero se ejecutará
dentro del mismo espacio de direcciones que el proceso que lo creó. No sólo compartirá
recursos sino que se ejecutará en el mismo espacio de direcciones.

4. Un hilo creado por un proceso se ejecutará en el espacio de direcciones de este
último.

Efectivamente, no solo comparte recursos sino tambien el espacio de direcciones.

5. Un hilo es la unidad básica de uso de la CPU.

Para establecer una diferencia entre el concepto de proceso y de hilo, debemos
distinguir entre la **unidad de propiedad de recursos (el proceso)** y **la unidad de ejecución (el hilo)**. 

Un hilo es la unidad de trabajo que se puede someter a ejecución. Se ejecuta
secuencialmente y es interrumpible para que el procesador pase a otro hilo. Permite que
el programador pueda ejercer la modularidad.

Un proceso puede verse como una colección de uno o más hilos. Cuando un sistema operativo soporta varios hilos en ejecución dentro del mismo proceso se dice que es multihilo. 

6. Un hilo es la unidad de propiedad de recursos.

No, ese es el proceso.

7. Dentro de un proceso, un hilo cuenta con un estado de ejecución.

En un ambiente multihilo, un proceso es la unidad de protección y asignación de
recursos.

Así, **cada hilo dentro de un proceso contará con un estado de ejecución**, un contexto de
procesador, una pila en modo usuario y otra en modo supervisor, almacenamiento para
variables locales y acceso a memoria y recursos del proceso (archivos abiertos, señales,
además de la parte de código y datos) que compartirá con el resto de los hilos.

Todos juntos, los hilos de un proceso constituyen una tarea.

8. Hay un PCB por procesos y los hilos que él cree.

La estructura de un hilo está constituida por:
- un program counter
- un conjunto de registros
- un espacio de stack

Un proceso tradicional (heavyweight process o monohilo) es una tarea formada por un
solo hilo. Cuenta con un PCB (process control block), espacio de direcciones de usuario
y 2 pilas.

En un proceso multihilo, además de PCB, espacio de direcciones de usuario y 2 pilas,
cada hilo tiene su propio TCB (thread control block) y 2 pilas.

9. Cuando un proceso se swapea, los hilos quedan en memoria en estado de espera.



10. En la administración de los hilos a nivel de usuario, interviene el kernel.

En los ULT, la administracion de los hilos lo hace la aplicacion sin intervencion del kernel. **EL KERNEL NI SE ENTERA DE SU EXISTENCIA**. El kernel no ve un hilo: ve un proceso haciendo un requerimiento. La creacion y operacion de los hilos se hacen a nivel de usuario y por lo tanto son mas rapidos de crear y utilizar.

11. En los ULT, cada proceso se encarga de administrar sus hilos.

Correcto.

12. LA suspensión de un ULT, provoca la suspensión del proceso.

Si, es decir, bloquea a todos los hilos del proceso.

13. En los KLT, el context switch entre hilos, no provoca un cambio de modo.

En los KLT, el trabajo de gestión de hilos lo hace el núcleo. La aplicación gestiona el
hilo a través de una API. Existen un conjunto de system calls similar a la de los
procesos específicas para hilos). Esta metodología se usa en W2000, Linux, OS/2.

El kernel mantiene información del proceso en general y de cada hilo del proceso en
particular. La planificación la hace el kernel en base a los hilos.

La ventaja es que en un ambiente multiprocesador, los hilos de un mismo proceso
pueden estar ejecutándose concurrentemente en los distintos procesadores (la unidad de
asignación del procesador ya no es el proceso).

**La desventaja de los KLT es que el pase del control entre hilos de un mismo proceso
necesita un cambio de modo**. Esto hace prever que la creación y administración de los
KLTs es más lenta que los ULTs. 

14. El kernel de Linux 2.4 no consideraba el concepto de thread. V o F

False, Thread groups were a feature added in Linux 2.4 to support the POSIX threads notion of a set of threads that share a single PID. Internally, this shared PID is the so-called thread group identifier (TGID) for the thread group. Since Linux 2.4, calls to getpid(2) return the TGID of the caller.

15. La System Call clone() permitía compartir la tabla de archivos entre el proceso padre e hijo pero no el espacio de memoria. V o F

Supongo que Falso, dado que se utiliza para crear Threads, y los hilos tienen acceso al mismo espacio de memoria.

```
Unlike fork(2), clone() allows the child process to share parts of its execution context with the calling process, such as the virtual address space, the table of file descriptors, and the table of signal handlers.  (Note that on this manual page, "calling process" normally
corresponds to "parent process".  But see the description of
CLONE_PARENT below.)

One use of clone() is to implement threads: multiple flows of control in a program that run concurrently in a shared address space.

When the child process is created with clone(), it commences
execution by calling the function pointed to by the argument fn. (This differs from fork(2), where execution continues in the child from the point of the fork(2) call.)  The arg argument is passed as the argument of the function fn.
```

16. El kernel de Linux 2.6 adopto el modelo POSIX, donde se utilizaba el modelo N:M.
V o F

Falso. El modelo N:M venia desde kernel 2.4 NGPT y en el kernel 2.6 se cambió a 1:1 por ser mas eficiente.

```
Linux uses 1:1 threading model starting from kernel 2.6 (NPTL Native Posix threading library) and today almost all OSes move to this model:

FreeBSD starting from 7.0 if I'm not mistaken.
Solaris starting for some version also moved to 1:1 - I don't remember which one.
Once Linux had M:N model (this was in 2.4 NGPT) but 1:1 is generally superior.

The biggest problem with M:N model is:

Hard to implement
When using blocking system calls you actually need to notify somehow kernel to block only one user space thread and not kernel one
In age of multi cores you want to have as much kernel threads as you can.
One of them is the hybrid (M:N) model in which some N threads of an application are mapped to some M available processors.

Small correction - N application threads mapped to M kernel threads so they can use up to M processors.
```

17. Solaris implementa el modelo:
a) 1:1 b) N:1 c) N:M d) No implementa threads

Historicamente Solaris implementa `N:M`, pero creo que lei que Solaris 9 implementa `1:1`.

Tenemos N ULT multiplexados con un LWP asociado a un unico KLT. Por cada LWP nuevo, es un KLT distinto, por lo que es `1:1`.

18. En Solaris, cada ULT siempre tiene relacionado un LWP. V o F

Falso. En realidad, un ULT puede no tener un LWP, pero eso significaria que no está trabajando. Lo que si, un KLT tiene relacionado un LWP.

19. Supongamos que en Solaris existe un proceso con varios ULT y que tiene asociado un único LWP. Si uno de sus ULT realiza una operación de E/S:

- Otro ULT del mismo proceso pasa a ejecutarse
- Ningún ULT podrá ejecutarse hasta que no finalice la E/S
- Ninguna de las opciones es valida

Ningún ULT podrá ejecutarse hasta que no finalice la E/S

21. En Solaris, un proceso que tiene relacionado un único LWP, podrá aprovechar el uso de múltiples procesadores. V o F

Falso

22. En Solaris, existen tantos KLTs como procesadores tenga la computadora. V o F 

23. En Solaris, existen tantos LWPs como ULTs haya entre todos los procesos del sistema. V o F

Falso, dado que se multiplexan n ULTs con un LWPs por proceso, por lo que la relacion es que siempre la cantidad de ULTs es menor o igual a LWPs. 

24. En Solaris, la biblioteca de threads en modo usuario planifica la ejecución de los KLT sobre los procesadores. V o F.

La biblioteca de hilos realiza además estas actividades:

- Ajusta el número de LWPs para mejorar el rendimiento de la aplicación. Si todos los LWPs de un proceso están bloqueados y hay más ULTs, la biblioteca crea otro LWP para asignar a un ULT que espera. Pero no olvidemos que se
crea un hilo de kernel adicional 

- elimina los LWP cuando no se utilizan por cierto tiempo. 

25. En Solaris, un UTL ligado a un LWP podrá ejecutar aplicaciones con requerimientos de Tiempo Real. V o F

Verdadero, Solaris es una versión de Unix. Es un sistema operativo moderno que soporta threads a nivel de usuario y de kernel, SMP, planificación en tiempo real.

26. En Solaris, un ULT puede estar en estado “Sleeping” y el LWP asociado en estado “Blocked” V o F

Falso, si tiene asociado un LWP esta en estado activo.

27. En Solaris, todo LWP con estado “Running” tiene asociado un ULT en estado “Active”. V o F

Verdadero.

28. En Solaris, la información de los registros del procesador es almacenada en los ULT. V o F

Falso.

29. Supongamos que en Solaris tenemos un programa que almacena cada dato que ingresa un usuario en 7 archivos diferentes. Para garantizar el mayor paralelismo en
la aplicación, deberíamos contar con:

- Un proceso con 7 ULTs y un único LWP
- Un proceso con 1 ULT y 5 LWPs
- Un proceso con 1 ULT y un 1 LWP
- Un proceso con 7 ULTs y 7 LWPs
- Ninguna de las opciones anteriores es valida 

Un proceso con 7 ULTs y 7 LWPs.

## MULTIPROCESADORES

30. Los KLT, en un ambiente multiprocesador, pueden ejecutarse en distintos procesadores.

Verdadero, es una de las ventajas de usar KLT.

31. En multiprocesadores, en la organización maestro esclavo, una syscall puede ser atendida en cualquiera de los procesadores.

Falso.

32. En multiprocesadores, si cada CPU tiene su SO es posible que una CPU este saturada y otras sin trabajo productivo.

Verdadero, es una de las desventajas.

33. En multiprocesadores, la técnica de SMP no requiere de exclusión mutua para el acceso a las estructuras del kernel.

Si requiere, es la mas complicada de los 3 enfoques por presentarse el problema de que podemos tener todos los procesadores en modo kernel tratando de usar las mismas estructuras de datos.

34. En multiprocesadores, el uso de cache de CPU para la operación TSL soluciona problema de contención del bus.

Falso, el problema que Test and Set siempre escribe la palabra de memoria, y hace que las cache se deban sincronizar.

35. No existen diferencias en la planificación de procesos entre SO monoprocesadores y multiprocesadores.

Falso.

36. En un sistema distribuido, todos los SO de las diferentes computadoras que participan deben ser iguales.

Falso.

37. En las multicomputadoras, cada CPU tiene su memoria.

Verdadero. Y se cuenta con un espacio de intercambio de mensajes para la comunicacion entre CPUs.

38. En multicomputadoras, la comunicación entre procesos se realiza por:

a) Memoria Compartida b) Pasajes de Mensajes c) RPC d) Ninguna

Pasajes de Mensajes.

39. En multicomputadoras, cada nodo puede correr un SO diferente.

Falso.

40. Las computadoras que forman una Grid deben ser todas iguales.

Falso, es un sistema distribuido, el midleware abstrae las diferencias.

41. El middleware es una capa de software entre el Hardware y el Sistema Operativo.

Falso.

## DEADLOCKS

42. Basta que una de las 4 condiciones de deadlock se cumpla, para que haya deadlock.

Condiciones:

- Exclusión mutua: En un instante de tiempo dado, solo un
proceso puede utilizar una instancia de un recurso

- Retención y espera: Los procesos deben mantener los
recursos asignados y esperar por la asignación de los
nuevos requeridos

- No apropiación: Los recursos no pueden ser quitados a un
proceso que actualmente los posea

- Espera circular: En la gráfica de asignación de recursos
debe cerrarse un bucle en el grafo.

**Para estar en presencia de un Deadlock se deben cumplir
todas!**

43. La desventaja de usar algoritmos de prevención del deadlock, es que baja el grado de multiprogramación.

Falso, baja la productividad de la CPU en la ejecucion de los procesos.

44. En un esquema de una instancia por tipo de recurso, cuando se encuentra un ciclo en un grafo de alocación de recursos, la asignación de los recursos solicitados:

- a) puede poner al sistema en estado inseguro
- b) pone al sistema en estado inseguro.

**Pone al sistema en estado inseguro. (de hecho es un Deadlock).**

45. Todos los estados inseguros son deadlock.

Falso.

46. El algoritmo del Banquero sirve para sistemas con múltiples instancias de cada recurso.

Verdadero.

47. Siempre que el grafo de recursos tiene ciclos, hay deadlock.

Falso.

**Si el grafo no contiene ciclos NO hay
interbloqueo**

**Si el grafo contiene un ciclo:**

- Si sólo hay una instancia por tipo de recurso  SI hay interbloqueo

- Si hay varias instancias por tipo de recurso  hay posibilidad de deadlock.