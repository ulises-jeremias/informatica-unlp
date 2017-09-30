### Ejercicio 1.
### Se dispone de un puente por el cual puede pasar un solo auto a la vez. Un auto pide permiso para pasar por el puente, cruza por el mismo y luego sigue su camino. Nota: no importa el orden en que han llegado al puente.
a. ¿El código funciona correctamente? Justifique su respuesta.

b. ¿Se podría simplificar el programa? En caso afirmativo, rescriba el código.

c. Si hubiese que respetar el orden de llegada de los vehículos, ¿La solución original lo respeta? Si rescribió el código en el punto b), ¿esa solución lo respeta?.
```C
Monitor Puente
    cond cola;
    int cant= 0;

    Procedure entrarPuente (int au)
        while ( cant > 0) wait (cola);
        cant = cant + 1;
    end;

    Procedure salirPuente (int au)
        cant = cant – 1;
        signal(cola);
    end;
End Monitor;

Process Auto [a:1..M]
    Puente. entrarPuente (a);
    “el auto cruza el puente”
    Puente. salirPuente(a);
End Process;
```

a.  No funciona porque cuando hay un auto en el puente deja esperando muchas veces al mismo auto en la cola. Se soluciona cambiando el while por un if.

b.  Se puede pensar a la variable cant como un boolean que determina si en un momento dado se puede cruzar o no, ya que la cantidad de autos permitidos en un momento dado es solo 1, pero el funcionamiento seria el mismo. Ademas de cambiar el while por un if.

```C
Monitor Puente
    cond cola;
    boolean ocupado = false;

    Procedure entrarPuente (int au)
        if (ocupado) wait (cola);
        else ocupado = true;
    end;

    Procedure salirPuente (int au)
        ocupado = false;
        signal(cola);
    end;
End Monitor;
```

c.  Ambas lo respetan, asumiendo que la primera funcionara.
