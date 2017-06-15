# Práctica 5

## Ejercicio 1

Explique claramente cual es la utilidad del registro de activación y que representan
cada una de sus partes.(Basado en el modelo debajo detallado)

  * __Punto de retorno:__  Cuando una rutina llama a otra y esta última termina, el punto de retorno es la dirección de memoria donde continúa la ejecución.
  * __Link Dinámico:__ Puntero a la dirección base del registro de activación de la rutina llamadora.
  * __Link Estático:__ Puntero a la dirección base del registro de activación de la rutina que estáticamente la contiene.
  * __Variables:__ Se enumeran las variables que conforman la unidad y se van reemplazando los valores de acuerdo a la ejecución del programa.
  * __Parámetros:__ Se enumeran los parámetros que conformar la unidad.
  * __Procedimientos y Funciones:__ Se enumeran los identificadores de los proc y funciones que contiene la unidad.
  * __Valor de Retorno:__ Los valores retornados por las funciones que desde esta unidad se llamen a ejecutar deberán ser escritos en esta dirección de memoria.
  
## Ejercicio 2

Dado el siguiente programa escrito en Pascal-like, continuar la realización de las pilas de ejecución hasta finalizar las mismas.

a) Siguiendo la cadena estática

Registro de Activación _Main_ 
Punto de Retorno *1
a(1) = ~~1~~ 2
a(2) = ~~2~~ 5
a(3) = 3
a(4) = 4
a(5) = 5
a(6) = 6
a(7) = 7
a(8) = 8
a(9) = 9
a(10) = 10
x = ~~1..10~~ ~~5~~ ~~12~~ ~~0~~ ~~6~~ ~~5~~ ~~0~~ ~~6~~ ~~5~~ ~~0~~ ~~6~~ ~~5~~ 1..10
y = ~~1~~ ~~2~~ 3
z = ~~10~~ ~~11~~ 5
Procedure A
Function t
Procedure B
VR -----
IMPRIME 2,1 5,2 3,3 4,4 5,5 6,6 7,7 8,8 9,9 10,10

Registro de Activación _A_
Punto de Retorno *2
EE(*1)
ED(*1)
t = 1
y = 2
VR -----

Registro de Activación _B_
Punto de Retorno *3
EE(*1)
ED(*2)
d = ~~0~~ ~~2~~ ~~4~~ 6
Procedure I
VR -----

Registro de Activación _t_
Punto de Retorno *4
EE(*1)
ED(*3)
VR 7

Registro de Activación _I_
Punto de Retorno *5
EE(*3)
ED(*3)
VR -----

Registro de Activación _I_
Punto de Retorno *6
EE(*3)
ED(*3)
VR -----

Registro de Activación _I_
Punto de Retorno *7
EE(*3)
ED(*3)
VR -----


b) Siguiendo la cadena dinámica

Registro de Activación _Main_
Punto de Retorno *1
a(1) = ~~1~~ 2
a(2) = ~~2~~ 5
a(3) = 3
a(4) = ~~4~~ 9
a(5) = 5
a(6) = 6
a(7) = 7
a(8) = 8
a(9) = 9
a(10) = ~~10~~ 12
x = ~~1~~ ~~2~~ ~~0~~ ~~6~~ ~~5~~ ~~0~~ ~~6~~ ~~5~~ ~~0~~ ~~6~~ ~~5~~ 1..10
y = 1
z = ~~10~~ ~~11~~ 7
Procedure A
Function t
Procedure B
VR -----
IMPRIME 2,1 5,2 3,3 4,9 5,5 6,6 7,7 8,8 9,9 10,12

Registro de Activación _A_
Punto de Retorno *2
EE(*1)
ED(*1)
t = 1
y = ~~2~~ 3
VR -----

Registro de Activación _B_
Punto de Retorno *3
EE(*1)
ED(*2)
d = ~~0~~ ~~2~~ ~~4~~ 6
Procedure I
VR -----

Registro de Activación _I_
Punto de Retorno *4
EE(*3)
ED(*3)
VR -----

Registro de Activación _I_
Punto de Retorno *5
EE(*3)
ED(*3)
VR -----

Registro de Activación _I_
Punto de Retorno *6
EE(*3)
ED(*3)
VR -----

## Ejercicio 5

a) Siguiendo la cadena estática


Registro de Activación _Main_
Punto de Retorno *1
x = ~~1~~ ~~2~~ 11
y = ~~2~~ 4
a(1) = 1
a(2) = ~~2~~ ~~14~~ 21
a(3) = 3
a(4) = ~~4~~ 23
a(5) = 5
a(6) = 6
b(1) = ~~3~~ 4
b(2) = 4
b(3) = 5
b(4) = 6
b(5) = 7
b(6) = 8
z = ~~1..6~~ 1..6
Procedure B
Procedure D
Function C
VR -----
IMPRIME el array a y b

Registro de Activación _B_
Punto de Retorno *2
EE(*1)
ED(*1)
x = ~~2~~ 3
y = ~~5~~ 7
Procedure C
VR -----
IMPRIME 3,7

Registro de Activación _C_
Punto de Retorno *3
EE(*2)
ED(*2)
c = 2
VR -----

Registro de Activación _D_
Punto de Retorno *4
EE(*1)
ED(*3)
VR 4  __NOTA__ Es lo que me retornan, no lo que retorno

Registro de Activación _C_
Punto de Retorno *5
EE(*1)
ED(*2)
VR -----
