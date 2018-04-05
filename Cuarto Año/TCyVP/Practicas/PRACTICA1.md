# Practica 1

### Responder brevemente los siguientes incisos

1.  **¿Qué es un problema (computacional) de decisión? ¿Es el tipo de problema más general
    que se puede formular?**

Dentro del universo de los problemas, se define la frontera "lo computable",
donde un problema computacional de decisión es un problema el cual se resuelve
algorítmicamente para un dominio dado.

Se entiende que este conjunto de problemas no es el conjunto más
general dado que existen aquellos problemas que no pueden ser resueltos
algorítmicamente, siendo estos aquellos que son no deterministicos para
ciertos subconjuntos de un dominio dado, así como tambien aquellos
problemas que ni siquiera son computables.

2.  **¿Qué cadenas integran el lenguaje aceptado por una MT?**

Las cadenas que integran el lenguaje aceptado por un MT son todos los subconjuntos
de Ʃ\* definido a partir de Ʃ, siendo Ʃ un conjunto finito de caracteres y
Ʃ\* el conjunto de todas las palabras formadas por símbolos de Ʃ.

3.

4.  **¿Qué postula la Tesis de Church-Turing?**

La conjetura conocida como _Tesis de Church-Turing_ postula que todo
lo computable puede ser llevado a cabo por una máquina de Turing.

5.  **¿Cuándo dos MT son equivalentes? ¿Cuándo dos modelos de MT son equivalentes?**

Dos Maquinas de Turing son computacionalmente equivalentes si ambas reconocen
el mismo lenguaje. Luego, dos modelos de Maquinas de Turing son equivalentes
si para toda MT de un modelo existe una MT de otro que sea equivalente.

6. **¿En qué difiere un lenguaje recursivo de un lenguaje recursivamente numerable no
recursivo?**

Un lenguaje L es recursivamente numerable (L ∈ RE) si y sólo si existe una MT M_L que lo acepta,
es decir L(ML) = L. Por lo tanto, para toda cadena w de Ʃ\*:

- Si w ∈ L, entonces M_L a partir de w para en su estado qA
- Si w ∉ L, entonces M_L a partir de w para en su estado qR o no para

Un lenguaje L es recursivo (L ∈ R) si y sólo si existe una MT M_L que lo acepta y para siempre
(también se puede decir directamente que lo decide). Por lo tanto, para toda cadena w de Ʃ\*:

- Si w ∈ L, entonces ML a partir de w para en su estado qA
- Si w ∉ L, entonces ML a partir de w para en su estado qR

Luego, sea L ∈ (RE - R), diremos que L es un lenguaje recursivamente numerable no recursivo,
es decir, que si existe una MT M_L que lo acepta, la misma no para siempre.

7. **¿En qué difiere un lenguaje recursivamente numerable de uno que no lo es?**

Sea L un lenguaje que no es recursivamente numerable, es decir L ∈ (CO-RE - R),
entonces no existe una MT M_L tal que L(M_L) = L. Sin embargo, sabemos que
existe una MT M_L talque L(M_L) = L^c.
