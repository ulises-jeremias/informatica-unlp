# Practica 2

## Punto 1

**c)**

| Metodo | Cantidad de Reglas | Long. promedio del antecedente | Precisión (accuracy) |
| :----: | -----------------: | -----------------------------: | -------------------: |
|  ZeroR |                  1 |                              0 |               62.50% |
|  OneR  |                  2 |                              1 |               87.50% |
|  PRISM |                  4 |                           1.75 |              100.00% |

## Punto 2

**a)**

#### OneR

###### Regla

-   Se estira? : Si	-> Si | No	-> No

Sop(X => Y) = 14/16 = 0.875

#### PRISM

###### Reglas

-   If Se estira? = Si and Color = Amarillo then Si

    -   Sop(X => Y) = 4/16 = 0.25
    -   Cob(X => Y) = 4/16 = 0.25
    -   Conf(X => Y) = 4/4 = 1
    -   Interes(X => Y) = ?

        -   Sop(X) = 4/16 = 0.25
        -   Sop(Y) = 6/16 = 0.375
        -   Interes(X => Y) = Sop(X => Y)/(Sop(X) * Sop(Y)) = 0.25/(0.25*0.375) = 2.66


-   If Se estira? = Si and Edad = Adulto then Si

    -   Sop(X => Y) = 4/16 = 0.25
    -   Cob(X => Y) = 4/16 = 0.25
    -   Conf(X => Y) = 4/4 = 1
    -   Interes(X => Y) = ?

        -   Sop(X) = 4/16 = 0.25
        -   Sop(Y) = 6/16 = 0.375
        -   Interes(X => Y) = Sop(X => Y)/(Sop(X) * Sop(Y)) = 0.25/(0.25*0.375) = 2.66

-   If Se estira? = No then No

    -   Sop(X => Y) = 8/16 = 0.5
    -   Cob(X => Y) = 8/16 = 0.5
    -   Conf(X => Y) = 8/8 = 1
    -   Interes(X => Y) = ?

        -   Sop(X) = 8/16 = 0.5
        -   Sop(Y) = 10/16 = 0.625
        -   Interes(X => Y) = Sop(X => Y)/(Sop(X) * Sop(Y)) = 0.5/(0.5*0.625) = 1.6

-   If Color = Rojo and Edad = Niño then No

    -   Sop(X => Y) = 4/16 = 0.25
    -   Cob(X => Y) = 4/16 = 0.25
    -   Conf(X => Y) = 4/4 = 1
    -   Interes(X => Y) = ?

        -   Sop(X) = 4/16 = 0.25
        -   Sop(Y) = 10/16 = 0.625
        -   Interes(X => Y) = Sop(X => Y)/(Sop(X) * Sop(Y)) = 0.25/(0.25*0.625) = 1.6

**b)**

Podemos determinar una respuesta para estas preguntas mirando aquellas reglas
que resulten interesantes, es decir, aquellas cuyo **_interes sea mayor a 1_**.
A partir de lass reglas formadas, podemos saber que los globos que no se inflan
ni con niños ni con adultos son aquellos que no se estiran, por lo tanto
esos globos no debieron ser comprados.

Al mismos tiempo, podemos saber que los globos de color rojo pueden ser
inflados solo por adultos, al igual que aquellos que se estiran.
