# Practica 2

## Punto 1

1.  a)

Para la construcción del arbol de clacificación se utiliza como método de
selección de atributos el criterio de _Ganancia de Información_. En el mismo
se detecta el atributo con menor incertidumbre para identificar la clase.
La ganancia de información es la diferencia entre la incertidumbre inicial
y la del atributo seleccionado. Luego, se elijirá aquel que brinde la
mayor ganancia de información.

Luego, dado un atributo A con V_a posibles valores y un conjunto de ejemplos
E, la Ganancia de Información de dicho atributo es:

`Ganancia(E, A) = Entropia(E) - Entropia(E, A)`

, siendo E_v el subconjunto de ejemplos para los que el atributo A toma el
valor v.

Para este ejercicio, evaluando el atributo `Examen_Final`, su entropia es:

`Entropia(E) = -(9/16)*log_2(9/16) -(7/16)*log_2(7/16) = 0.9887`

Ahora, evaluamos la ganancia de cada atributo:

-   **Colegio_UNLP**

    -   SI --> APROB(3) --> `Entropia(E_si) = -(3/3)*log_2(3/3) = 0`
    -   NO --> APROB(6); DESAPROB(7) --> `Entropia(E_no) = -(6/13)*log_2(6/17) -(7/13)*log_2(7/13) = 0.9957`
    -   **Entropia Colegio_UNLP**

    `Entropia(E, Colegio_UNLP) = (3/16)*0 + (13/16)*0.9957 = 0.809`

    -   **Ganancia Colegio_UNLP**

    `Ganancia(E, Colegio_UNLP) = 0.9887 - 0.809 = 0.1797`

-   **Activ_WebUNLP**

    -   BAJA --> APROB(3); DESAPROB(2) --> `Entropia(E_baja) = -(3/5)*log_2(3/5) -(2/5)*log_2(2/5) =
        0.9709`
    -   MEDIA --> APROB(5); DESAPROB(1) --> `Entropia(E_media) = -(5/6)*log_2(5/6) -(1/6)*log_2(1/6) =
        0.65`
    -   ALTA --> APROB(1); DESAPROB(4) --> `Entropia(E_alta) = -(1/5)*log_2(1/5) -(4/5)*log_2(4/5) =
        0.7219`
    -   **Entropia Activ_WebUNLP**

    `Entropia(E, Activ_WebUNLP) = (5/16)*0.9709 + (6/16)*0.65 + (5/16)*0.7219 = 0.7727`

    -   **Ganancia Activ_WebUNLP**

    `Ganancia(E, Activ_WebUNLP) = 0.9887 - 0.7727 = 0.216`

-   ...

* * *

Y así sucesivamente. Para obtener la ganancia rapidamente se puede utilizar
el operador _Weight by Information Gain_. El output es:

| attribute          | weight              |
| ------------------ | ------------------- |
| Entregas_Completas | 0.09715800163284705 |
| Asistencia         | 0.11369940828849745 |
| Colegio_UNLP       | 0.17967085346949552 |
| Activ_WebUNLP      | 0.21591640975098003 |
| TRABAJA            | 0.38024081494414785 |

Una vez determinada la mayor ganancia, y así el nodo raiz, (siendo en este caso
`TRABAJA`) analizo la respuesta de los atributos para los ejemplos que aún
no pertenecen a un subconjunto homogéneo, que en este caso es aquellos
en los que la columna `TRABAJA` tiene el valor `NO`.

2.  ...

3.  c)

| Row No. | Examen_Final |
| ------- | ------------ |
| 1       | DESAPROB     |
| 2       | DESAPROB     |
| 3       | DESAPROB     |
| 4       | APROB        |

4.  d)

Si, se puede utilizando el operador `ApplyModel` y efectivamente los resultados
coinciden.

## Punto 2

No se obtuvo el mismo resultado dado que el arbol generado en el inciso _a)_
define el arbol utilizando el campo _Asistencia_ en el segundo nivel,
el cual no tiene lugar en las predicciones generadas por el otro arbol.
