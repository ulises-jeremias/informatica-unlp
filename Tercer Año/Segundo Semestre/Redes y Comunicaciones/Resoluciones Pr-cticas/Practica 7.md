# Práctica 7 - Capa de red

## Introducción

### 1. ¿Qué servicios presta la capa de red? ¿Cuál es la PDU en esta capa? ¿Qué dispositivo es considerado sólo de la capa de red?

La función de la capa de red es tremendamente simple: transporta paquetes desde un host emisor a un host receptor. En la realización de esta tarea podemos identificar dos importantes funciones de la capa de red:
 
* Reenvío (forwarding). Cuando un paquete llega al enlace de entrada de un router, éste tiene que pasar el paquete al enlace de salida apropiado.

* Enrutamiento (routing). La capa de red tiene que determinar la ruta o camino que deben seguir los paquetes a medida que fluyen de un emisor a un receptor. Los algoritmos que calculan estas rutas se conocen como algoritmos de enrutamiento.

Todo router tiene una tabla de reenvio. Un router reenvia un paquete examinando el valor de un campo de la cabecera del paquete entrante y utilizando después ese valor para indexarlo dentro de la tabla de reenvio del router. El resultado de la tabla de reenvío indica a cuál de las interfaces del enlace de salida del router será reenviado el paquete.  El algoritmo de enrutamiento determina los valores que se introducen en las tablas de reenvío de los routers. Este algoritmo puede estar centralizado o descentralizado (en cada router).

La capa de red de Internet proporciona un único servicio conocido como servicio de mejor esfuerzo (best-effort service). Al decir servicio de mejor esfuerzo estamos utilizando un eufemismo por no decir que no proporciona ningún servicio en absoluto. Con un servicio de mejor esfuerzo, la temporización relativa entre paquetes no está garantizada, tampoco está garantizado que los paquetes se reciban en el orden que fueron emitidos y tampoco se garantiza la entrega de los paquetes transmitidos. Por tanto, teniendo en cuenta esta definición, una red que no entregara los paquetes al destino satisfaría la definición de servicio de entrega de mejor esfuerzo.

Al PDU asociado a esta capa se lo conoce como `datagrama`.

El dispositivo que solo es considerado de la capa de red es el router (que en realidad es un conmutador de paquetes, como el switch, pero este último se basa en la cabecera de la capa de enlace ya que pertenece a esta). El router no implementa las capas superiores a la capa de red.

### 2.  ¿Cuántas redes clase A, B y C hay? ¿Cuántos hosts como máximo pueden tener cada una?

Los tipos de redes utilizados normalmente son A, B y C aunque existen los de tipo D y E que están destinados a otros usos que de momento no trataremos así que nosotros vamos a ver los res primeros que son los de tipo A, B y C.

**Redes de clase A**

Las redes de clase A tienen como número en su primer segmento uno comprendido entre el 1 y el 126 ambos incluidos, vamos con unos ejemplos:

* La dirección Ip 80.85.23.164 es de clase A
* La dirección Ip 186.23.54.69 no es de clase A
* La dirección Ip 126.36.76.65 es de clase A

Y por último queda la identificación por su máscara de subred que va a ser 255.0.0.0. Esto se puede comprobar accediendo a www.miip.es donde se ve como la dirección Ip es de clase A y va relacionada con las redes WAN (Wide Area Network).

**Redes de clase B**

Las redes de clase B tienen en su primer segmento números comprendidos entre el 128 y el 191 ambos incluidos vamos a verlo:

* La dirección Ip 149.34.127.143 es de clase B
* La dirección Ip 42.169.221.86 no es de clase B
* La dirección Ip 129.3.45.131 es de clase B

En este caso la máscara de subred va a ser 255.255.0.0. Este tipo de direcciones Ip o esta clase de red se puede asociar con las redes MAN (Metropolitan Area Network) no tan conocidas pero bueno…

**Redes de clase C**

Y para terminar las de clase C, vamos las que trabajamos nosotros y en las que su primer segmento se encuentra entre el 192 y el 223 ambos inlcuidos y vamos a verlo con unos ejemplos:

* La dirección Ip 192.78.91.97 es de clase C
* La dirección Ip 97.142.174.162 no es de clase C
* La dirección Ip 201.121.41.63 es de clase C

Bueno, esta es la más conocida como sabemos la máscara de subred es la conocida 255.255.255.0 y es para redes de tipo LAN (Local Area Network).
