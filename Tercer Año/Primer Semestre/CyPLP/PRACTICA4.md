# Práctica 4

## Objetivo 
Conocer el manejo de identificadores en memoria y como lo definen e implementan los diferentes lenguajes.

## Ejercicio 1
### a) Tome una de las variables de la línea 3 del siguiente código e indique y defina cuales son sus atributos:

__variable I__
  
    Nombre: I
    Alcance: desde la linea 3 a la 16
    Tipo: Integer, predefinido
    L-value: Tiempo de ejecución del programa, automático
    R-value:  Espacio de memoria alocada de 4 bytes, sin inicialización por defecto.
        
### b) Compare los atributos de la variable del punto a) con los atributos de la variable de la línea 4. Que dato contiene esta variable?, que otra variable hay en este código?

    La variable _p_ contiene una referencia de la variable _i_. Luego, la variable anónima ^p contiene el valor de la variable _i_.
    
## Ejercicio 2
### a) Indique cuales son las diferentes formas de inicializar una variable en el momento de la declaración de la misma.
    
Las formas de inicializar una variables son:
* Inicialización por defecto: Depende de los tipos definidos en un lenguaje determinado y el valor por defecto que le corresponde a cada uno.
* Inicialización en la declaración: Se especifica el tipo correspondiente en el momento de la declaración.
* Algunos lenguajes permiten que el r-valor de una variable sea una referencia al l-valor de otra variable.

## Ejercicio 3
### a) Explique los siguientes conceptos asociados al atributo l-valor de una:
* Variable estática: Su tiempo de vida se extiende durante la ejecución completa del programa. La asignación de memoria se hace en tiempo de compilación.
* Variable automáticas: Son variables locales a un bloque de sentencias de código. Su tiempo de vida está definido por el bloque donde pertenece.
* Variables dinámicas: 
* Variables semi-dinámicas: 

## Ejercicio 4
### a) ¿A qué se denomina variable local y a qué se denomina variable global?
* Variable local: Son todas las referencias que se han creado dentro del programa o subprograma. Su alcance se límita al entorno donde este fue definida.
* Variables globales: Son todas las referencias creadas en el programa principal con un alcance completo, no restringido, el cual le permite a estas variables ser referenciadas en cualquier ámbito del programa.

### b) ¿Una variable local puede ser estática respecto de su l-valor? En caso afirmativo de un ejemplo
Las variables locales pueden ser estáticas, de forma que estos datos son inaccesibles desde otros módulos a menos que sean pasados por parámetros. Esto es dado que una variables estática puede ser referenciada en todos aquellos ambitos en los cuales tenga alcance el entorno donde esta fué creada.

### c) Una variable global ¿siempre es estática? Justifique la respuesta
No necesariamente es estática, dado que el alcance de una variable estática está limitado por el alcance del entorno donde es definido. Por otro lado, las variables globales tienen un alcance completo de todo el programa, luego estas variables pueden ser o no estáticas. Por ejemplo, en el lenguaje de programación C se usa static con variables globales y funciones para restringir su ámbito al archivo donde se definen.

### d) Indique que diferencia hay entre una variable estática respecto de su l-valor y una constante.

## Ejercicio 6
Con variables locales, static se usa para almacenar la variable en la memoria asignada de forma estática en lugar de en la memoria asignada de forma automática. Esto permite que, para este ejemplo particular, sea indistinto utilizar una variable global que una variable estática definida en func1. Esto es dado que, siendo estática, se aloca el espacio en memoria una unica vez, y no pasa a redefinirse con cada llamado a la función.

## Ejercicio 7
Las variables locales son aquellas declaradas dentro del ambito de un método y las globales son las que están declaradas dentro de la clase, fuera del entorno de una clase.

## Ejercicio 8
### a) Indique el rango de instrucciones que representa el tiempo de vida de las variables i, h y mipuntero.
    Rango: [1-15]

### b) Indique el rango de instrucciones que representa el alcance de las variables i, h y mipuntero.
    mipuntero: [3-15]
    i: [4-15]
    h: [5-15]

### c) Indique si el programa anterior presenta un error al intentar escribir el valor de h. Justifique
No presenta error, dado que mipuntero es una referencia a i, osea, mipuntero := ^i, luego, ^mipuntero := i.
    
### d) Indique si el programa anterior presenta un error al intentar asignar a i la resta de h con mipuntero. Justifique


### e) Determine si existe otra entidad que necesite ligar los atributos de alcance y tiempo de vida para justificar las respuestas anteriores. En ese caso indique cuál es la entidad y especifique su tiempo de vida y alcance.
    ^mipuntero es la entidad faltante de tipo dinámico de alcance 6-15 y tiempo de vida 9-12.

### f) Especifique el tipo de variable de acuerdo a la ligadura con el l-valor de las variables que encontró en el ejercicio.
