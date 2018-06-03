# Cuestionario 2

## Introducción

Cuestionario de las clases teóricas 3 a 6

## Resolución

**Defina fairness. ¿Cuál es la relación con las políticas de scheduling? (NO DESCRIBA LOS DISTINTOS
TIPOS DE POLITICAS DE SCHEDULING)**

a. ¿Por qué las propiedades de vida dependen de la política de scheduling?

b. ¿Cómo aplicaría el concepto de fairness al acceso a una base de datos compartida por n procesos
concurrentes?

Una *política de scheduling* es un algoritmo encargado de determinar cual será la próxima instrucción atómica a ejercutarse. 
Luego, **Fairness** es una propiedad que poseen, o no, dichas políticas que *tratan de garantizar que los procesos tengan
chance de avanzar, sin importar lo que los demás hagan*.

Las políticas de scheduling determinan el tiempo de espera de cada uno de los procesos, luego, ésto determina tambien las
propiedades de tiempo de vida, *liveness*, de cada uno de ellos.

Respecto del acceso a una base de datos, si una política de scheduling es fairness, buscará garantizar que los n procesos
avancen y puedan consultar la base de datos.

    
**Dado el siguiente programa concurrente, indique cuál es la respuesta correcta (justifique claramente)**
```C
    int a = 1, b = 0;
    co 〈await (b = 1) a = 0 〉 // while (a = 1) { b = 1; b = 0; } oc
```

a) Siempre termina

b) Nunca termina

c) Puede terminar o no

**¿Qué propiedades que deben garantizarse en la administración de una sección crítica en procesos
concurrentes?**

a. ¿Cuáles de ellas son propiedades de seguridad y cuáles de vida?
b. En el caso de las propiedades de seguridad, ¿cuál es en cada caso el estado “malo” que se debe evitar?

Se debe garantizar: 
* Exclusión mutua
* Ausencia de Deadlock
* Ausencia de Demora Innecesaria
* Eventual Entrada

Las 3 primeras son de seguridad, la 4ta de vida.

Los estados malos a evitar son:
* Exclusión mutua, que existan accesos simultaneos a la SC.
* Ausencia de Deadlock, que dos procesos accedan a la SC bloquandose simultaneamente.
* Ausencia de Demora Innecesaria, que exista una mala utilización de recursos.

**Resuelva el problema de acceso a sección crítica para N procesos usando un proceso coordinador. En este
caso, cuando un proceso SC[i] quiere entrar a su sección crítica le avisa al coordinador, y espera a que éste
le otorgue permiso. Al terminar de ejecutar su sección crítica, el proceso SC[i] le avisa al coordinador.
Desarrolle una solución de grano fino usando únicamente variables compartidas (ni semáforos ni
monitores).**

