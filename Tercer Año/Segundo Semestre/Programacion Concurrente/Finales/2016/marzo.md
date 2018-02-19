1. Ejercicio 1
  - a) En programación concurrente hablamos de **interferencia** cuando un proceso realiza una acción que invalida las suposiciones hechas por otro proceso. Esto puede evitarse mediante la utilización de alguna tecnica de sincronización. La **sincronización** es la posesión de información acerca de otro proceso para coordinar actividades. Los procesos se sincronizan:
    - Por exclusión mutua.
    - Por condición.

  - b) Una sentencia de asignación x = e satisface la propiedad de "A lo sumo una vez" si:

    1. e contiene a lo sumo una referencia crítica y x no es referenciada por otro proceso, o
    2. e no contiene referencias críticas, en cuyo caso x puede ser leída por otro proceso.

  Una expresiones e que no está en una sentencia de asignación satisface la propiedad de “A lo sumo una vez” si no contiene más de una referencia crítica.

  Si una sentencia de asignación cumple la propiedad ASV, entonces su ejecución parece atómica, pues la variable compartida será leída o escrita sólo una vez


2. Defina el problema de la sección crítica. Compare los algoritmos para resolver este problema (Spinlocks, Tie Breaker, Ticket y Bakery). Marque ventajas y desventajas de cada uno.

El problema de la **sección crítica** es la consecuencia del uso óptimo de la CPU al ejecutar procesos concurrentes, esto es, la multiprogramación.

Se necesita de un mecanismo de sincronización en la entrada y salida de la sección crítica para asegurar la utilización exclusiva del recurso. El no tener un control por sobre esta sección puede conllevar a inconsistencias y/o corrupción de datos (contenidos en variables) compartidos por un conjunto de procesos.

El problema de la sección crítica es uno de los problemas que con mayor frecuencia aparece cuando se ejecutan procesos concurrentes (o también en programación con multithread donde los hilos deben llevar a cabo una sincronización para procesar datos en el orden correcto, y aprovecha la característica de multiprocesamiento de computadoras que tienen multicores).

Para entender un poco mejor el concepto se presenta el siguiente ejemplo: Se tiene un Sistema Operativo que debe asignar un identificador de proceso (PID) a dos procesos en un sistema multicore. Cuando el SO realiza esta acción en dos procesadores de forma simultánea sin ningún tipo de control, se pueden producir errores, ya que se puede asignar el mismo PID a dos procesos distintos. Este problema se debe a que constituyen una sección crítica que debe ejecutarse en forma atómica, es decir, de forma completa e indivisible y ningún otro proceso podrá ejecutar dicho código mientras el primero no haya acabado su sección.
