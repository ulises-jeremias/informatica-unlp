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

Y por último queda la identificación por su máscara de subred que va a ser 255.0.0.0. Va relacionada con las redes WAN (Wide Area Network).

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

### 3. ¿Qué son las subredes? ¿Por qué es importante siempre especificar la máscara de subred asociada?

En redes de computadoras, una subred es un rango de direcciones lógicas. Cuando una red de computadoras se vuelve muy grande, conviene dividirla en subredes, por los siguientes motivos:

* Reducir el tamaño de los dominios de broadcast.
* Hacer la red más manejable, administrativamente. Entre otros, se puede controlar el tráfico entre diferentes subredes mediante ACLs.

Existen diversas técnicas para conectar diferentes subredes entre sí. Se pueden conectar:

* a nivel físico *(capa 1 OSI)* mediante repetidores o concentradores (hubs),
* a nivel de enlace *(capa 2 OSI)* mediante puentes o conmutadores (switches),
* a nivel de red *(capa 3 OSI)* mediante routers,
* a nivel de transporte *(capa 4 OSI)*,
* aplicación *(capa 7 OSI)* mediante pasarelas.

También se pueden emplear técnicas de encapsulación *(tunneling)*.

En el caso más simple, se puede dividir una red en subredes de tamaño fijo (todas las subredes tienen el mismo tamaño). Sin embargo, por la escasez de direcciones IP, hoy en día frecuentemente se usan subredes de tamaño variable.

**Máscara de una subred**

La máscara de subred o subneting señala qué bytes (o qué porción) de su dirección es el identificador de la red. La máscara consiste en una secuencia de unos seguidos de una secuencia de ceros con el mismo tamaño que una dirección IP (32 bits, o lo que es lo mismo 4 bytes), por ejemplo, una máscara de 20 bits se escribiría 255.255.240.0, es decir como una dirección IP con 20 bits en 1 seguidos por 12 bits en 0, pero para facilitar su lectura se escribe separando bloques de 8 bits (1 byte) con puntos y escribiéndolos en decimal. La máscara determina todos los parámetros de una subred: dirección de red, dirección de difusión (broadcast) y direcciones asignables a nodos de red (hosts).

Los routers constituyen los límites entre las subredes. La comunicación desde y hasta otras subredes es hecha mediante un puerto específico de un router específico, por lo menos momentáneamente.

Una subred típica es una red física hecha con un router, por ejemplo: una Red Ethernet o una “red de área local virtual” (Virtual Local Area Network, VLAN). Sin embargo, las subredes permiten a la red ser dividida lógicamente a pesar del diseño físico de la misma, por cuanto es posible dividir una red física en varias subredes configurando diferentes computadores host que utilicen diferentes routers. La dirección de todos los nodos en una subred comienzan con la misma secuencia binaria, que es su ID de red e ID de subred. En IPv4, las subredes deben ser identificadas por la base de la dirección y una máscara de subred.

Las subredes simplifican el enrutamiento, ya que cada subred típicamente es representada como una fila en las tablas de ruteo en cada router conectado. Las subredes fueron utilizadas antes de la introducción de las direcciones IPv4, para permitir a una red grande tener un número importante de redes más pequeñas dentro, controladas por varios routers. Las subredes permiten el enrutamiento entre dominios sin clases (CIDR). Para que las computadoras puedan comunicarse con una red, es necesario contar con números IP propios, pero si tenemos dos o más redes, es fácil dividir una dirección IP entre todos los hosts de la red. De esta forma se pueden partir redes grandes en redes más pequeñas.

Es necesario para el funcionamiento de una subred calcular los bits de una IP y quitarle los bits de host, y agregárselos a los bits de network mediante el uso de una operación lógica.

### 4. Describa qué es y para qué sirve el protocolo ICMP.

El 'Protocolo de Mensajes de Control de Internet' o ICMP (por sus siglas en inglés de Internet Control Message Protocol) es el sub protocolo de control y notificación de errores del Protocolo de Internet (IP). Como tal, se usa para enviar mensajes de error, indicando por ejemplo que un router o host no puede ser localizado. También puede ser utilizado para transmitir mensajes ICMP Query.

ICMP difiere del propósito de TCP y UDP ya que generalmente no se utiliza directamente por las aplicaciones de usuario en la red. La única excepción es la herramienta ping y traceroute, que envían mensajes de petición Echo ICMP (y recibe mensajes de respuesta Echo) para determinar si un host está disponible, el tiempo que le toma a los paquetes en ir y regresar a ese host y cantidad de hosts por los que pasa.

#### a. Analice cómo funciona el comando ping.

**i. Indique el tipo y código ICMP que usa el ping.**
**ii. Indique el tipo y código ICMP que usa la respuesta de un ping.**

Como programa, **ping** es una utilidad diagnóstica1 en redes de computadoras que comprueba el estado de la comunicación del host local con uno o varios equipos remotos de una red IP por medio del envío de paquetes ICMP de solicitud (ICMP tipo 8 Echo Request codigo 0) y de respuesta (ICMP tipo 0 Echo Reply codigo 0). Mediante esta utilidad puede diagnosticarse el estado, velocidad y calidad de una red determinada.

#### b. Analice cómo funciona el comando traceroute (tracert en Windows) y cómo manipula el campo TTL de los paquetes IP.

**Traceroute** es una consola de diagnóstico que permite seguir la pista de los paquetes que vienen desde un host (punto de red). Se obtiene además una estadística del RTT o latencia de red de esos paquetes, lo que viene a ser una estimación de la distancia a la que están los extremos de la comunicación.

Tracert utiliza el campo **Time To Live** (TTL) de la cabecera IP. Este campo sirve para que un paquete no permanezca en la red de forma indefinida (por ejemplo, debido a la existencia en la red de un bucle cerrado en la ruta). El campo TTL es un número entero que es decrementado por cada nodo por el que pasa el paquete. De esta forma, cuando el campo TTL llega al valor 0 ya no se reenviará más, sino que el nodo que lo esté manejando en ese momento lo descartará. Lo que hace tracert es mandar paquetes a la red de forma que el primer paquete lleve un valor TTL=1, el segundo un TTL=2, etc. De esta forma, el primer paquete será eliminado por el primer nodo al que llegue (ya que éste nodo decrementará el valor TTL, llegando a cero). Cuando un nodo elimina un paquete, envía al emisor un mensaje de control especial indicando una incidencia. Tracert usa esta respuesta para averiguar la dirección IP del nodo que desechó el paquete, que será el primer nodo de la red. La segunda vez que se manda un paquete, el TTL vale 2, por lo que pasará el primer nodo y llegará al segundo, donde será descartado, devolviendo de nuevo un mensaje de control. Esto se hace de forma sucesiva hasta que el paquete llega a su destino.

#### c. Indique la cantidad de saltos realizados desde su computadora hasta el sitio info.unlp.edu.ar. En algunos de los saltos ¿muestra el nombre del dominio asociado al salto y su ip? Detalle los encontrados.

#### d. Verifique el recorrido a dos de los servidores de mail de gmail.com y compare los saltos realizados. ¿Realizaron la misma cantidad de saltos, hicieron el mismo camino?

### 5. ¿Para que se usa el bloque 127.0.0.0/8? ¿Qué PC responde a los siguientes comandos?

El dispositivo de red loopback es una interfaz de red virtual. Las direcciones del rango '127.0.0.0/8' son direcciones de loopback, de las cuales se utiliza, de forma mayoritaria, la '127.0.0.1' por ser la primera de dicho rango, añadiendo '::1' para el caso de IPv6 ('127.0.0.1::1'). Las direcciones de loopback pueden ser redefinidas en los dispositivos, incluso con direcciones IP públicas, una práctica común en los routers. y son usualmente utilizadas para probar la capacidad de la tarjeta interna si se están enviando datos BGP.

Esta dirección se suele utilizar cuando una transmisión de datos tiene como destino el propio host. También se suele usar en tareas de diagnóstico de conectividad y validez del protocolo de comunicación.

La dirección de loopback es una dirección especial que los hosts utilizan para dirigir el tráfico hacia ellos mismos. La dirección de loopback crea un método de acceso directo para las aplicaciones y servicios TCP/IP que se ejecutan en el mismo dispositivo para comunicarse entre sí. Al utilizar la dirección de loopback, en lugar de la dirección host IPv4 asignada, dos servicios en el mismo host pueden desviar las capas inferiores del stack de TCP/IP. También es posible hacer ping a la dirección de loopback para probar la configuración de TCP/IP en el host local.

A pesar de que sólo se usa la dirección única '127.0.0.1', se reservan las direcciones desde la '127.0.0.0' hasta la '127.255.255.255'. Cualquier dirección dentro de este bloque producirá un loopback dentro del host local. Las direcciones dentro de este bloque no deben figurar en ninguna red.

### 6. Investigue para qué sirven los comandos ifconfig y route. ¿Qué comandos podría utilizar en su reemplazo? Inicie una topología con CORE, cree una máquina y utilice en ella los comandos anteriores para practicar sus diferentes opciones, mínimamente:

#### Configurar y quitar una dirección IP en una interfaz.
#### Ver la tabla de ruteo de la máquina.

**ifconfig** («configuración de interfaz») es un programa disponible en varias versiones del sistema operativo UNIX, que permite configurar o desplegar numerosos parámetros de las interfaces de red residentes en el núcleo, como la dirección IP (dinámica o estática), o la máscara de red. Si se llama sin argumentos suele mostrar la configuración vigente de las interfaces de red activas, con detalles como la dirección MAC o el tráfico que ha circulado por las mismas hasta el momento. Las interfaces de red en Linux se suelen denominar eth (eth0, eth1, etc.).

Como reemplazo a este comando podemos utilizar **ip**. [ifconfig vs ip](https://www.tecmint.com/ifconfig-vs-ip-command-comparing-network-configuration/)

**route** es una herramienta de línea de comandos disponible tanto en Microsoft Windows como en GNU/Linux. Nos permite manipular las tablas de enrutamiento de nuestro sistema.
