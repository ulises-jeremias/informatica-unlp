# Práctica 2

## Ejercicio 2

> ¿Cuál es la importancia de la sintaxis para un lenguaje? ¿Cuáles son sus elementos?

La **sintaxis** describe la *forma* del lenguaje. Describe por completo la apariencia del mismo: cuáles serán sus palabras claves, cuáles serán los operadores válidos, cómo podrán ser formados los identificadores, cómo se separarán las sentencias, etc. Se encuentra estrechamente ligada a aspectos importantes de los lenguajes como la legibilidad y la facilidad de escritura, ya que una sintaxis diseñada cuidadosamente genera construcciones simples de entender y de escribir.

Los elementos de la sintaxis son:

* alfabeto
* identificadores
* operadores
* palabras clave y reservadas
* comentarios y blancos

## Ejercicio 3

> ¿Explique a qué se denomina regla lexicográfica y regla sintáctica?

Las **reglas lexicográficas** determinan, a partir del alfabeto, las *words* que se usarán en el lenguaje.

Las **reglas sintácticas** especifican *cómo* combinar las *words* para formar expresiones y sentencias.

## Ejercicio 4

> ¿En la definición de un lenguaje, a qué se llama palabra reservadas? ¿A qué son equivalentes en la definición de una gramática? De un ejemplo de palabra reservada en el lenguaje que más conoce. (Ada,C,Rubi,Python,..)

Las *palabras reservadas* son palabras que no pueden ser usadas como identificadores. Este concepto se suele confundir con el de *palabra clave*, que se refiere a palabras que tienen un cierto significado en un cierto contexto. En la definición de una gramática, las palabras reservadas serían `G`, `N`, `T`, `S` y `P`.

## Ejercicio 5

> Dada la siguiente gramática escrita en BNF:
> 
> ```
> G= (N, T, S, P)
> N = {<numero_entero>, <digito> }
> T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
> S = <numero_entero>
> P = {
>   <numero_entero> ::= <digito><numero_entero> | <numero_entero><digito> | <digito>
>   <digito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
> }
> ```
> 
> a. Identifique los componentes.
> 
> b. Indique por qué es ambigua y corríjala.

**a**.

* `G`: 4-tupla que engloba a los conjuntos que contienen las reglas léxicas y sintácticas a partir de las cuales se define la gramática.
* `N`: conjunto de símbolos no terminales.
* `T`: conjunto de símbolos terminales.
* `S`: símbolo más genérico.
* `P`: conjunto de producciones que determinan las reglas.

**b**. Es ambigua porque dado un número, por ejemplo `10`, se podrían construir dos árboles sintácticos. Para corregir este problema bastaría con eliminar `<digito><numero_entero>` o `<numero_entero><digito>` de la definición del símbolo `<número_entero>`.

*Una posible solución podría ser la siguiente*
```
  G = (N, T, S, P)
  N = {<numero_entero>, <numero_entero_con_signo>, <numero_entero_sin_signo>, <digito>, <signo>}
  T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, '-', '+'}
  S = {<numero_entero>}
  P = {
    <numero_entero> ::= <numero_entero_con_signo> | <numero_entero_sin_signo>
    <numero_entero_con_signo> ::= <signo><numero_entero_sin_signo>
    <numero_entero_sin_signo> ::= <digito><numero_entero_sin_signo> | <digito>
    <digito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
    <signo> ::= + | -
  }
```

## Ejercicio 6

> Defina en BNF (Gramática de contexto libre desarrollada por Backus- Naur) la gramática para la definición de una palabra cualquiera.

```
  G = (N, T, S, P)
  N = {<palabra>, <letra>}
  T = {'a'..'z', 'A'..'Z'}
  S = {<palabra>}
  P = {
    <palabra> ::= <letra><palabra> | <letra>
    <letra> ::= 'a'..'z' | 'A'..'Z'
  }
```

## Ejercicio 7 

> Defina en EBNF la gramática para la definición de números reales. Inténtelo desarrollar para BNF y explique las diferencias con la utilización de la gramática EBNF.

**BNF**

*Se me ocurre la siguiente solución aunque no estoy completamente seguro si es la más viable* **¯\\\_(ツ)_/¯**
```
  G = (N, T, S, P)
  N = {<numero_real>, <numero_entero>, <numero_entero_con_signo>, <numero_entero_sin_signo>, <digito>, <caracter>, <signo>}
  T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, '.', ',', '-', '+'}
  S = {<numero_real>}
  P = {
    <numero_real> ::= <numero_entero> | <numero_entero><caracter><numero_entero_sin_signo>
    <numero_entero> ::= <numero_entero_con_signo> | <numero_entero_sin_signo>
    <numero_entero_con_signo> ::= <signo><numero_entero_sin_signo>
    <numero_entero_sin_signo> ::= <digito><numero_entero_sin_signo> | <digito>
    <digito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
    <signo> ::= + | -
    <caracter> ::= . | ,
  }
```

**EBNF**

```
  G = (N, T, S, P)
  N = (<numero_real>, <digito>, <signo>, <caracter>)
  T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, '.', ',', '-', '+'}
  S = {<numero_real>}
  P = {
    <numero_real> ::= [<signo>]{<digito>}+[<caracter>{<digito>}+]
    <digito> ::= (0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9)
    <signo> ::= (+ | -)
    <caracter> ::= (. | ,)
  }
```

## Ejercicio 8

> Utilizando la gramática que desarrolló en los puntos 6 y 7, escriba el árbol sintáctico de:

**a**. Conceptos

**b**. Programación

**c**. 1255869

El símbolo inicial es <numero_real>.

La derivación del real 1255869 es:
```
  <numero_real> => <numero_entero>
                => <numero_entero_sin_signo>
                => <digito><numero_entero_sin_signo>
                => <digito><digito><numero_entero_sin_signo>
                => <digito><digito><digito><numero_entero_sin_signo>
                => <digito><digito><digito><digito><numero_entero_sin_signo>
                => <digito><digito><digito><digito><digito><numero_entero_sin_signo>
                => <digito><digito><digito><digito><digito><digito><numero_entero_sin_signo>
                => <digito><digito><digito><digito><digito><digito><digito>
                => 1<digito><digito><digito><digito><digito><digito>
                => 12<digito><digito><digito><digito><digito>
                => 125<digito><digito><digito><digito>
                => 1255<digito><digito><digito>
                => 12558<digito><digito>
                => 125586<digito>
                => 1255869
```

**d**. 854,26

El símbolo inicial es <numero_real>.

La derivación del real 854,26 es:
```
  <numero_real> => <digito><digito><digito><caracter><digito><digito>
                => 8<digito><digito><caracter><digito><digito>
                => 85<digito><caracter><digito><digito>
                => 854<caracter><digito><digito>
                => 854,<digito><digito>
                => 854, 2<digito>
                => 854,26
```
  
**e**. Conceptos de lenguajes
