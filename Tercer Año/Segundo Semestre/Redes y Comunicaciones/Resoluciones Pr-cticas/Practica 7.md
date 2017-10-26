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

---


