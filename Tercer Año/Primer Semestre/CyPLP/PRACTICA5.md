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

