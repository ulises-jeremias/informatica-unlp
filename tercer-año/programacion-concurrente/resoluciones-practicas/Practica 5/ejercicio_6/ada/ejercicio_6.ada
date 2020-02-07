
### 6. Suponga que existen N usuarios que deben ejecutar su programa, para esto
comparten K procesadores.

### Los usuarios solicitan un procesador al administrador. Una vez que el
administrador les entregó el número de procesador, el usuario le da su programa
al procesador que le fue asignado. Luego el usuario espera a que:

#### • El procesador le avise si hubo algún error en una línea de código con lo
cual el usuario arregla el programa y se lo vuelve a entregar al procesador, es
decir queda nuevamente en la cola de programas a ejecutar por su procesador.
El usuario no termina hasta que el procesador haya ejecutado su programa correctamente
(sin errores).

#### El procesador le avise que su programa termino, con lo cual termina su ejecución.

### El administrador tomará los pedidos de procesador hechos por los usuarios y
balanceara la carga de programas que tiene cada procesador, de esta forma le entregará
al usuario un número de procesador.

### El procesador ejecutará un Round-Robin de los programas listos a ejecutar.
Cada programa es ejecutado línea por línea por medio de la función EJECUCIÓN la cual devuelve:

#### • 1 error en la ejecución.
#### • 2 normal.
#### • 3 fin de programa.

##### NOTA: Suponga que existe también la función LineaSiguiente que dado un programa
devuelve la línea a ser ejecutada. Maximice la concurrencia en la solución.

procedure Punto6 is
    task User is

    end User;

    task Processor is

    end Processor;

    task Admin is
        entry
    end Admin;
begin -- ${1/([a-zA-Z0-9_]*).*$/Punto6/}

end ${1/([a-zA-Z0-9_]*).*$/Punto6/};
