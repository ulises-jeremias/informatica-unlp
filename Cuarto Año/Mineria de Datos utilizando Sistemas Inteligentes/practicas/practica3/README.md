# Practica 2

## Punto 1

**c)**

| Metodo | Cantidad de Reglas | Long. promedio del antecedente | Precisión (accuracy) |
| :----: | -----------------: | -----------------------------: | -------------------: |
|  ZeroR |                  1 |                              0 |               62.50% |
|  OneR  |                  2 |                              1 |               87.50% |
|  PRISM |                  4 |                           1.75 |              100.00% |

## Punto 2

#### OneR

###### Regla

-   Se estira? : Si	-> Si | No	-> No

Soporte = 14/16 = 0.875

#### PRISM

###### Reglas

-   If Se estira? = Si and Color = Amarillo then Si

    -   Soporte = 4/16 = 0.25
    -   Cobertura = 4/16 = 0.25
    -   Confianza = 4/4 = 1

-   If Se estira? = Si and Edad = Adulto then Si

    -   Soporte = 4/16 = 0.25
    -   Cobertura = 4/16 = 0.25
    -   Confianza = 4/4 = 1

-   If Se estira? = No then No

    -   Soporte = 8/16 = 0.5
    -   Cobertura = 8/16 = 0.5
    -   Confianza = 8/8 = 1

-   If Color = Rojo and Edad = Niño then No

    -   Soporte = 4/16 = 0.25
    -   Cobertura = 4/16 = 0.25
    -   Confianza = 4/4 = 1
